#pragma once
#include <string>
#include <vector>
#include <thread>
#include <iostream>
#include <fstream>
#include <filesystem>

class MyGrep {
    std::string _wordToFind;
    std::string _logFileName;
    std::string _resFileName;
    std::string _searchedDir;
    size_t _searchedFiles = 0, _filesWithWord = 0;

public:
    MyGrep (std::string passedWord, std::string passedLogName, std::string passedResName, std::string passedDir)
        : _wordToFind(passedWord)
        , _logFileName(passedLogName)
        , _resFileName(passedResName)
        , _searchedDir(passedDir)
    {}
    MyGrep (std::string passedWord)
        : MyGrep(passedWord, "MyGrep.log", "MyGrep.txt", "..")
    {}
    ~MyGrep() {}

    //getters
    size_t getSearchedFilesNum() { return _searchedFiles; }

    void searchForWord();
};