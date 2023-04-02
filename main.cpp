#include "MyGrep.hpp"
#include <chrono>

int main(int argc, char *argv[]) {
    auto start = std::chrono::high_resolution_clock::now();
    std::string wordToFind;
    if(argc <= 1) {
        std::cout << "Write a phrase you're looking for, in this pattern: ./MyGrep <phrase>\n";
        return 0;
    }

    // Pull phrase to look for from argv[1]
    if(argc > 1) {
        wordToFind = argv[1];
    }

    // Use argv[2], argv[3], etc to read flags to change settings of grep
    std::vector<std::string> flags;
    if(argc > 2) {
        for(int i = 2; i < argc - 1; i++) {
            flags.push_back(argv[i]);
        }
    }

    MyGrep lookForThis(wordToFind);
    lookForThis.searchForWord();
    lookForThis.createResFile();
    lookForThis.createLogFile();

    auto stop = std::chrono::high_resolution_clock::now();

    std::cout << "Searched files: " << lookForThis.getSearchedFilesNum() << "\n";
    std::cout << "Files with pattern: " << lookForThis.getFoundWordFilesNum() << "\n";
    std::cout << "Patterns number: " << lookForThis.getFoundWordCount() << "\n";
    std::cout << "Result file: " << lookForThis.getResFileDir() << "\n";
    // std::cout << "Log file: " << lookForThis.getLogFileDir() << "\n";
    // std::cout << "Used threads: " << lookForThis.
    std::cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() << "[ms]\n";
}