#Grep

The purpose of the program is to find a given phrase among the files in the current folder and its subfolders,
and create result and threads log files. Using flags, it is possible to change the searched path, the names of the
of the result and log files and the number of running threads. At the end of the program's execution, it displays
a message, presenting information such as: number of files searched, number of files containing the searched phrase,
number of instances found, path to the result file and to the log file, the number of threads and time of program's
execution.

I also made a basic CMakeLists.txt file. The only way I know to compile using CMake is to create and enter build/ folder
and type following commands:
```
cmake ..
make
```
or download the folder from this repository, you can then skip the first command.

I also tried to create a thread pool and force the path search function to run using threads, but due to this being my
first contact with multithreading, it failed. My attempts can be seen on the threadpool branch
