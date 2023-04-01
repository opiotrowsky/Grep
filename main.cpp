#include <iostream>
#include "MyGrep.hpp"

int main(int argc, char *argv[]) {
    std::string wordToFind;
    if(argc > 1) {
        wordToFind = argv[1];
    }

    // use argv[2], argv[3], etc to read flags to change settings of grep
    std::vector<std::string> flags;
    if(argc > 2) {
        for(int i = 2; i < argc - 1; i++) {
            flags.push_back(argv[i]);
        }
    }

    MyGrep lookForThis(wordToFind);
    lookForThis.searchForWord();

    std::vector<std::thread> threadPool;

    std::cout << "Searched files: " << lookForThis.getSearchedFilesNum() << "\n";
}