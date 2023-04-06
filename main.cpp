#include "MyGrep.hpp"
#include <chrono>

int main(int argc, char *argv[]) {
    auto start = std::chrono::high_resolution_clock::now();
    std::string wordToFind;
    std::string resName;
    std::string logName;
    std::string dirName;
    size_t threadsNum = 0;
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
        for(int i = 2; i < argc; i++) {
            flags.push_back(argv[i]);
        }
        flags.shrink_to_fit();
    }
    for(size_t i = 0; i < flags.size(); i++) {
        if(flags.at(i) == "-d" || flags.at(i) == "--dir") {
            dirName = flags.at(i + 1);
        }
        if(flags.at(i) == "-r" || flags.at(i) == "--result_file") {
            resName = flags.at(i + 1);
        }
        if(flags.at(i) == "-l" || flags.at(i) == "--log_file") {
            logName = flags.at(i + 1);
        }
        if(flags.at(i) == "-t" || flags.at(i) == "--threads") {
            threadsNum = std::stoi(flags.at(i + 1));
        }
    }

    MyGrep lookForThis(wordToFind);
    lookForThis.setFlags(dirName, logName, resName, threadsNum);
    lookForThis.searchForWord();
    lookForThis.createResFile();
    lookForThis.createLogFile();

    auto stop = std::chrono::high_resolution_clock::now();

    std::cout << "Searched files: " << lookForThis.getSearchedFilesNum() << "\n";
    std::cout << "Files with pattern: " << lookForThis.getFoundWordFilesNum() << "\n";
    std::cout << "Patterns number: " << lookForThis.getFoundWordCount() << "\n";
    std::cout << "Result file: " << lookForThis.getResFileDir() << "\n";
    std::cout << "Log file: " << lookForThis.getLogFileDir() << "\n";
    std::cout << "Used threads: should be " << lookForThis.getThreadsNum() << " but there was none :(\n";
    std::cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() << "[ms]\n";
}
