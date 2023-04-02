#include "MyGrep.hpp"

void MyGrep::searchForWord() {
    std::ifstream readFile;
    std::string line;
    size_t lineNum = 1;
    bool isWordInFile = false;
    for(const auto& dirElement : std::filesystem::recursive_directory_iterator(_searchedDir)) {
        readFile.open(dirElement.path());
        if(!readFile.is_open()) {
            continue;
        }

        while(std::getline(readFile, line)) {
            if(line.find(_wordToFind) != std::string::npos) {
                _res.push_back(dirElement.path().string() + ":" + std::to_string(lineNum) + ": " + line + "\n");
                _wordCount++;
                isWordInFile = true;
            }
            lineNum++;
        }
        readFile.close();



        if(isWordInFile) {
            _filesWithWord++;
        }
        lineNum = 1;
        isWordInFile = false;
        if(std::filesystem::is_directory(dirElement.path())) {
            continue;
        }
        _searchedFiles++;
    }
}

void MyGrep::createResFile() {
    std::fstream resultFile;
    auto path = std::filesystem::absolute(_searchedDir).string();
    resultFile.open(path + _resFileName, std::ios::out);
    if(!resultFile.is_open()) {
        std::cerr << "Could not create file with searching results\n";
    }
    for(const auto& resLine : _res) {
        resultFile << resLine;
    }
    resultFile.close();
}

void MyGrep::createLogFile() {
    std::fstream logFile;
    auto path = std::filesystem::absolute(_searchedDir).string();
    logFile.open(path + _logFileName, std::ios::out);
    if(!logFile.is_open()) {
        std::cerr << "Could not create the log file\n";
    }
    for(const auto& logLine : _log) {
        logFile << logLine;
    }
    logFile.close();
}