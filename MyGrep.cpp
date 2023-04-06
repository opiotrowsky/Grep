#include "MyGrep.hpp"

void MyGrep::setFlags(std::string passedDir, std::string passedLogName, std::string passedResName, size_t passedThreads) {
    if(!passedDir.empty()) {
        _searchedDir = std::filesystem::path(passedDir);
    }
    if(!passedLogName.empty()) {
        _logFileName = passedLogName;
    }
    if(!passedResName.empty()) {
        _resFileName = passedResName;
    }
    if(passedThreads > 4) {
        _numOfThreads = passedThreads;
    }
}

void MyGrep::searchForWord() {
    std::ifstream readFile;
    std::string line;
    std::vector<std::string> resTemp;
    size_t lineNum = 1;
    bool isWordInFile = false;
    int wordCountInFile = 0, maxWordCountInFile = 0;
    for(const auto& dirElement : std::filesystem::recursive_directory_iterator(_searchedDir)) {
        if(std::filesystem::is_directory(dirElement.path())) {
            continue;
        }
        readFile.open(dirElement.path());
        if(!readFile.is_open()) {
            continue;
        }

        while(std::getline(readFile, line)) {
            if(line.find(_wordToFind) != std::string::npos) {
                resTemp.push_back(dirElement.path().string() + ":" + std::to_string(lineNum) + ": " + line + "\n");
                _wordCount++;
                wordCountInFile++;
                isWordInFile = true;
            }
            lineNum++;
        }
        readFile.close();

        if(wordCountInFile > maxWordCountInFile) {
            for(int i = resTemp.size() - 1; i >= 0; i--) {
                _res.insert(_res.begin(), resTemp[i]);
            }
            maxWordCountInFile = wordCountInFile;
        }
        else {
            for(const auto& el : resTemp) {
                _res.push_back(el);
            }
        }

        if(isWordInFile) {
            _filesWithWord++;
        }
        resTemp.clear();
        lineNum = 1;
        isWordInFile = false;
        _searchedFiles++;
        wordCountInFile = 0;
    }
}

void MyGrep::createResFile() {
    std::ofstream resultFile("../" + _resFileName);
    if(!resultFile.is_open()) {
        std::cerr << "Could not create file with searching results\n";
    }
    for(const auto& resLine : _res) {
        resultFile << resLine;
    }
    resultFile.close();
}

void MyGrep::createLogFile() {
    std::ofstream logFile("../" + _logFileName);
    if(!logFile.is_open()) {
        std::cerr << "Could not create the log file\n";
    }
    for(const auto& logLine : _log) {
        logFile << logLine;
    }
    logFile.close();
}