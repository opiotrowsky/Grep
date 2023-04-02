#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <thread>
#include <iostream>
#include <fstream>
#include <filesystem>

class MyGrep {
    std::string _wordToFind;
    std::string _logFileName;
    std::string _resFileName;
    std::string _searchedDir;
    size_t _searchedFiles = 0, _filesWithWord = 0, _wordCount = 0;
    std::vector<std::string> _log, _res;

public:
    MyGrep (std::string passedWord, std::string passedLogName, std::string passedResName, std::string passedDir)
        : _wordToFind(passedWord)
        , _logFileName(passedLogName)
        , _resFileName(passedResName)
        , _searchedDir(passedDir)
    {}
    MyGrep (std::string passedWord)
        : MyGrep(passedWord, "MyGrep.log", "MyGrep.txt", std::filesystem::current_path().parent_path().string())//std::filesystem::current_path().u8string())
    {}
    ~MyGrep() {}

    //getters
    size_t getSearchedFilesNum() { return _searchedFiles; }
    size_t getFoundWordFilesNum() { return _filesWithWord; }
    size_t getFoundWordCount() { return _wordCount; }
    std::string getResFileDir() { return std::filesystem::current_path().parent_path().string() + "/" + _resFileName; }
    std::string getLogFileDir() { return std::filesystem::current_path().parent_path().string() + "/" + _logFileName; }

    void searchForWord();
    void createResFile();
    void createLogFile();
};