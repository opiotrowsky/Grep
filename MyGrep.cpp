#include "MyGrep.hpp"

void MyGrep::searchForWord() {
    std::fstream logFile, resultFile;
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