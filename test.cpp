#include <catch2/catch_all.hpp>
#include "MyGrep.hpp"

SCENARIO("Program is looking for words with default settings.") {
    GIVEN("The word 'house'") {
        std::string word = "house";
        MyGrep lookFor(word);
        
        WHEN("the program looks for given word") {
            lookFor.searchForWord();
            
            THEN("default settings should be:") {
                REQUIRE(lookFor.getSearchedDir() == std::filesystem::current_path().parent_path().string());
                REQUIRE(lookFor.getResFileName() == "MyGrep.txt");
                REQUIRE(lookFor.getLogFileName() == "MyGrep.log");
                REQUIRE(lookFor.getThreadsNum() == 4);
            }
        }
    }
}

SCENARIO("Program is looking for words with single flag.") {
    GIVEN("The word 'house'") {
        std::string word = "house";
        MyGrep lookFor(word);
        std::string newDir;
        std::string newLogFile;
        std::string newResFile;
        int newThrdNum;

        WHEN("the '-d' or '--dir' flag is set") {
            newDir = "c/users/download";
            lookFor.setFlags(newDir, newLogFile, newResFile, newThrdNum);

            THEN("new directory should be 'c/users/download'") {
                REQUIRE(lookFor.getSearchedDir() == newDir);
            }
        }

        WHEN("the '-l' or '--log_file' flag is set") {
            newLogFile = "newLog.log";
            lookFor.setFlags(newDir, newLogFile, newResFile, newThrdNum);

            THEN("new log file name should be 'newLog.log'") {
                REQUIRE(lookFor.getLogFileName() == newLogFile);
            }
        }

        WHEN("the '-r' or '--res_file' flag is set") {
            newResFile = "newRes.txt";
            lookFor.setFlags(newDir, newLogFile, newResFile, newThrdNum);

            THEN("new result file name should be 'newRes.txt'") {
                REQUIRE(lookFor.getResFileName() == newResFile);
            }
        }

        WHEN("the '-t' or '--threads'") {
            newThrdNum = 12;
            lookFor.setFlags(newDir, newLogFile, newResFile, newThrdNum);

            THEN("new threads number should be 12") {
                REQUIRE(lookFor.getThreadsNum() == newThrdNum);
            }
        }
    }
}

SCENARIO("Program is looking for word 'house' with multiple flags.") {
    GIVEN("The word 'house'") {
        std::string word = "house";
        MyGrep lookFor(word);
        std::string newDir;
        std::string newLogFile;
        std::string newResFile;
        int newThrdNum;

        WHEN("'-d' and '-l' flags are set") {
            newDir = "c/users/download";
            newLogFile = "newLog.log";
            lookFor.setFlags(newDir, newLogFile, newResFile, newThrdNum);

            THEN("searched directory and log file name should be changed") {
                REQUIRE(lookFor.getSearchedDir() == newDir);
                REQUIRE(lookFor.getLogFileName() == newLogFile);
            }
        }

        WHEN("'-d' and '-r' flags are set") {
            newDir = "c/users/download";
            newResFile = "newRes.txt";
            lookFor.setFlags(newDir, newLogFile, newResFile, newThrdNum);

            THEN("searched directory and result file name should be changed") {
                REQUIRE(lookFor.getSearchedDir() == newDir);
                REQUIRE(lookFor.getResFileName() == newResFile);
            }
        }

        WHEN("'-d' and '-t' flags are set") {
            newDir = "c/users/download";
            newThrdNum = 12;
            lookFor.setFlags(newDir, newLogFile, newResFile, newThrdNum);

            THEN("searched directory and thread number should be changed") {
                REQUIRE(lookFor.getSearchedDir() == newDir);
                REQUIRE(lookFor.getThreadsNum() == newThrdNum);
            }
        }

        WHEN("'-l' and '-r' flags are set") {
            newLogFile = "newLog.log";
            newResFile = "newRes.txt";
            lookFor.setFlags(newDir, newLogFile, newResFile, newThrdNum);

            THEN("log file and result file names should be changed") {
                REQUIRE(lookFor.getLogFileName() == newLogFile);
                REQUIRE(lookFor.getResFileName() == newResFile);
            }
        }

        WHEN("'-l' and '-t' flags are set") {
            newLogFile = "newLog.log";
            newThrdNum = 12;
            lookFor.setFlags(newDir, newLogFile, newResFile, newThrdNum);

            THEN("log file name and thread number should be changed") {
                REQUIRE(lookFor.getLogFileName() == newLogFile);
                REQUIRE(lookFor.getThreadsNum() == newThrdNum);
            }
        }

        WHEN("'-r' and '-t' flags are set") {
            newResFile = "newRes.txt";
            newThrdNum = 12;
            lookFor.setFlags(newDir, newLogFile, newResFile, newThrdNum);

            THEN("res file name and thread number should be changed") {
                REQUIRE(lookFor.getResFileName() == newResFile);
                REQUIRE(lookFor.getThreadsNum() == newThrdNum);
            }
        }
    }
}