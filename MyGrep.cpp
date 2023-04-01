#include "MyGrep.hpp"

void MyGrep::searchForWord() {
    std::fstream logFile, resultFile;
    std::ifstream readFile;
    for(const auto& dirElement : std::filesystem::recursive_directory_iterator(_searchedDir)) {
        std::ifstream readFile(dirElement.path().filename().u8string(), std::ios::binary);
        if(!readFile.is_open()) {
            std::cerr << "File opening error.\n";
        }



        _searchedFiles++;
    }

    
}