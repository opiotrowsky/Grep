#include "ThreadPool.hpp"

void ThreadPool::loopOfThreads() {
    while(true) {
        std::function<void()> task;
        {
            std::unique_lock<std::mutex> lock(taskQueueMutex);
            mutexCondVariable.wait(lock, [this] { return !jobs.empty() || stopWorking; });
            if(stopWorking) {
                return;
            }
            task = tasksQueue.front();
            tasksQueue.pop();
        }
        task();
    }
}

void ThreadPool::start() {
    threadsVector.resize(threadsNumber);
    for(size_t i = 0; i < threadsNumber; i++) {
        threadsVector.at(i) = std::thread(loopOfThreads);
    }
}

void ThreadPool::stop() {
    {
        std::unique_lock<std::mutex> lock(taskQueueMutex);
        stopWorking = true;
    }
    mutexCondVariable.notify_all();
    for(std::thread& activeThread : threadsVector) {
        activeThread.join();
    }
    threadsVector.clear();
}

void ThreadPool::queueATask(const std::function<void()>& task) {
    {
        std::unique_lock<std::mutex> lock(taskQueueMutex);
        tasksQueue.push(task);
    }
    mutexCondVariable.notify_one();
}

void ThreadPool::busy() {
    bool isPoolBusy;
    {
        std::unique_lock<std::mutex> lock(taskQueueMutex);
        isPoolBusy = tasksQueue.empty();
    }
    return isPoolBusy;
}
