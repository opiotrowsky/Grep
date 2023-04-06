#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <filesystem>

class MyGrep {
    std::string _wordToFind;
    std::string _logFileName = "MyGrep.log";
    std::string _resFileName = "MyGrep.txt";
    std::filesystem::path _searchedDir = std::filesystem::current_path().parent_path();
    size_t _numOfThreads = 4;
    size_t _searchedFiles = 0, _filesWithWord = 0, _wordCount = 0;
    std::vector<std::string> _log, _res;

public:
    MyGrep (std::string passedWord)
        : _wordToFind(passedWord)
    {}
    ~MyGrep() {}

    //setters
    void setFlags(std::string passedDir, std::string passedLogName, std::string passedResName, size_t passedThreads);

    //getters
    size_t getThreadsNum() { return _numOfThreads; }
    size_t getSearchedFilesNum() { return _searchedFiles; }
    size_t getFoundWordFilesNum() { return _filesWithWord; }
    size_t getFoundWordCount() { return _wordCount; }
    std::string getResFileDir() { return std::filesystem::current_path().parent_path().string() + "/" + _resFileName; }
    std::string getLogFileDir() { return std::filesystem::current_path().parent_path().string() + "/" + _logFileName; }

    void searchForWord();
    void createResFile();
    void createLogFile();
};
