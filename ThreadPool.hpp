#pragma once
#include <queue>
#include <vector>
#include <thread>
#include <functional>
#include <mutex>
#include <condition_variable>

class ThreadPool {
    void loopOfThreads();

    int threadsNumber;
    bool stopWorking = false;
    std::vector<std::thread> threadsVector;
    std::queue<std::function<void()>> tasksQueue;
    std::mutex taskQueueMutex;
    std::condition_variable mutexCondVariable;

public:
    ThreadPool(int passedThreadsNumber) : threadsNumber(passedThreadsNumber)
    {}
    ThreadPool() : ThreadPool(4)
    {}
    ~ThreadPool() {}

    void start();
    void stop();
    void busy();
    void queueATask(const std::function<void()>& task);
};
