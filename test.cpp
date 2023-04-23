#include <catch2/catch_all.hpp>
#include "MyGrep.hpp"

SCENARIO("Program is looking for words with default settings.") {
    GIVEN("The word 'house'") {
        std::string word = "house";
        MyGrep lookFor(word);
        
        WHEN("the program looks for given word") {
            lookFor.searchForWord();
            
            THEN("default settings should be:") {
                CHECK(lookFor.getSearchedDir() == std::filesystem::current_path().parent_path().string());
                CHECK(lookFor.getResFileName() == "MyGrep.txt");
                CHECK(lookFor.getLogFileName() == "MyGrep.log");
                CHECK(lookFor.getThreadsNum() == 4);
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
                CHECK(lookFor.getSearchedDir() == newDir);
            }
        }

        WHEN("the '-l' or '--log_file' flag is set") {
            newLogFile = "newLog.log";
            lookFor.setFlags(newDir, newLogFile, newResFile, newThrdNum);

            THEN("new log file name should be 'newLog.log'") {
                CHECK(lookFor.getLogFileName() == newLogFile);
            }
        }

        WHEN("the '-r' or '--res_file' flag is set") {
            newResFile = "newRes.txt";
            lookFor.setFlags(newDir, newLogFile, newResFile, newThrdNum);

            THEN("new result file name should be 'newRes.txt'") {
                CHECK(lookFor.getResFileName() == newResFile);
            }
        }

        WHEN("the '-t' or '--threads'") {
            newThrdNum = 12;
            lookFor.setFlags(newDir, newLogFile, newResFile, newThrdNum);

            THEN("new threads number should be 12") {
                CHECK(lookFor.getThreadsNum() == newThrdNum);
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
                CHECK(lookFor.getSearchedDir() == newDir);
                CHECK(lookFor.getLogFileName() == newLogFile);
            }
        }

        WHEN("'-d' and '-r' flags are set") {
            newDir = "c/users/download";
            newResFile = "newRes.txt";
            lookFor.setFlags(newDir, newLogFile, newResFile, newThrdNum);

            THEN("searched directory and result file name should be changed") {
                CHECK(lookFor.getSearchedDir() == newDir);
                CHECK(lookFor.getResFileName() == newResFile);
            }
        }

        WHEN("'-d' and '-t' flags are set") {
            newDir = "c/users/download";
            newThrdNum = 12;
            lookFor.setFlags(newDir, newLogFile, newResFile, newThrdNum);

            THEN("searched directory and thread number should be changed") {
                CHECK(lookFor.getSearchedDir() == newDir);
                CHECK(lookFor.getThreadsNum() == newThrdNum);
            }
        }

        WHEN("'-l' and '-r' flags are set") {
            newLogFile = "newLog.log";
            newResFile = "newRes.txt";
            lookFor.setFlags(newDir, newLogFile, newResFile, newThrdNum);

            THEN("log file and result file names should be changed") {
                CHECK(lookFor.getLogFileName() == newLogFile);
                CHECK(lookFor.getResFileName() == newResFile);
            }
        }

        WHEN("'-l' and '-t' flags are set") {
            newLogFile = "newLog.log";
            newThrdNum = 12;
            lookFor.setFlags(newDir, newLogFile, newResFile, newThrdNum);

            THEN("log file name and thread number should be changed") {
                CHECK(lookFor.getLogFileName() == newLogFile);
                CHECK(lookFor.getThreadsNum() == newThrdNum);
            }
        }

        WHEN("'-r' and '-t' flags are set") {
            newResFile = "newRes.txt";
            newThrdNum = 12;
            lookFor.setFlags(newDir, newLogFile, newResFile, newThrdNum);

            THEN("res file name and thread number should be changed") {
                CHECK(lookFor.getResFileName() == newResFile);
                CHECK(lookFor.getThreadsNum() == newThrdNum);
            }
        }

        WHEN("'-d', '-l' and '-r' flags are set") {
            newDir = "c/users/download";
            newLogFile = "newLog.log";
            newResFile = "newRes.txt";
            lookFor.setFlags(newDir, newLogFile, newResFile, newThrdNum);

            THEN("searched directory, log file name and result file name should be changed") {
                CHECK(lookFor.getSearchedDir() == newDir);
                CHECK(lookFor.getLogFileName() == newLogFile);
                CHECK(lookFor.getResFileName() == newResFile);
            }
        }

        WHEN("'-d', '-l' and '-t' flags are set") {
            newDir = "c/users/download";
            newLogFile = "newLog.log";
            newThrdNum = 12;
            lookFor.setFlags(newDir, newLogFile, newResFile, newThrdNum);

            THEN("searched directory, log file name and thread number should be changed") {
                CHECK(lookFor.getSearchedDir() == newDir);
                CHECK(lookFor.getLogFileName() == newLogFile);
                CHECK(lookFor.getThreadsNum() == newThrdNum);
            }
        }

        WHEN("'-d', '-r' and '-t' flags are set") {
            newDir = "c/users/download";
            newResFile = "newRes.txt";
            newThrdNum = 12;
            lookFor.setFlags(newDir, newLogFile, newResFile, newThrdNum);

            THEN("searched directory, log file name and thread number should be changed") {
                CHECK(lookFor.getSearchedDir() == newDir);
                CHECK(lookFor.getResFileName() == newResFile);
                CHECK(lookFor.getThreadsNum() == newThrdNum);
            }
        }

        WHEN("'-l', '-r' and '-t' flags are set") {
            newLogFile = "newLog.log";
            newResFile = "newRes.txt";
            newThrdNum = 12;
            lookFor.setFlags(newDir, newLogFile, newResFile, newThrdNum);

            THEN("log file name, res file name and thread number should be changed") {
                CHECK(lookFor.getLogFileName() == newLogFile);
                CHECK(lookFor.getResFileName() == newResFile);
                CHECK(lookFor.getThreadsNum() == newThrdNum);
            }
        }

        WHEN("'-d', '-l', '-r' and '-t' flags are set") {
            newDir = "c/users/download";
            newLogFile = "newLog.log";
            newResFile = "newRes.txt";
            newThrdNum = 12;
            lookFor.setFlags(newDir, newLogFile, newResFile, newThrdNum);

            THEN("searched directory, log file name, res file name and thread number should be changed") {
                CHECK(lookFor.getSearchedDir() == newDir);
                CHECK(lookFor.getLogFileName() == newLogFile);
                CHECK(lookFor.getResFileName() == newResFile);
                CHECK(lookFor.getThreadsNum() == newThrdNum);
            }
        }
    }
}

SCENARIO("Program, while looking for word 'house', generates output information.") {
    GIVEN("The word 'house' and folder locs/ with files prepared for testing") {
        std::string word = "house";
        MyGrep lookFor(word);

        WHEN("we search prepared directory with only '-d' flag") {
            std::string testDir = std::filesystem::current_path().parent_path().string() + "/locs";
            std::string emptyLogFile, emptyResFile;
            int emptyThrdNum;
            lookFor.setFlags(testDir, emptyLogFile, emptyResFile, emptyThrdNum);
            lookFor.searchForWord();

            THEN("the output data should be like that in the testing directory") {
                CHECK(lookFor.getSearchedFilesNum() == 6);
                CHECK(lookFor.getFoundWordFilesNum() == 3);
                CHECK(lookFor.getFoundWordCount() == 5);
            }
        }

        WHEN("we search prepared directory with all possible flags") {
            std::string testDir = std::filesystem::current_path().parent_path().string() + "/locs";
            std::string testLogFile = "testLog.log";
            std::string testResFile = "testRes.txt";
            int testThrdNum = 10;
            lookFor.setFlags(testDir, testLogFile, testResFile, testThrdNum);
            lookFor.searchForWord();

            THEN("the output data should not change according to no flags") {
                CHECK(lookFor.getSearchedFilesNum() == 6);
                CHECK(lookFor.getFoundWordFilesNum() == 3);
                CHECK(lookFor.getFoundWordCount() == 5);
            }
        }
    }
}

SCENARIO("Program, while looking for word 'house', creates files containing program's result and log info") {
    GIVEN("The word 'house' and folder locs/ with files prepared for testing") {
        std::string word = "house";
        MyGrep lookFor(word);

        WHEN("there is only '-d' flag for testing folder") {
            std::string testDir = std::filesystem::current_path().parent_path().string() + "/locs";
            std::string emptyLogFile, emptyResFile;
            int emptyThrdNum;
            lookFor.setFlags(testDir, emptyLogFile, emptyResFile, emptyThrdNum);
            lookFor.searchForWord();
            lookFor.createLogFile();
            lookFor.createResFile();

            THEN("there should be default result and log files") {
                CHECK(lookFor.getLogFileDir() == std::filesystem::current_path().parent_path().string() + "/MyGrep.log");
                CHECK(lookFor.getResFileDir() == std::filesystem::current_path().parent_path().string() + "/MyGrep.txt");
                std::filesystem::remove(std::filesystem::path(lookFor.getLogFileDir()));
                std::filesystem::remove(std::filesystem::path(lookFor.getResFileDir()));
            }
        }

        WHEN("there is '-d' flag for testing folder and '-l' to change log file name") {
            std::string testDir = std::filesystem::current_path().parent_path().string() + "/locs";
            std::string testLogFile = "testLog.log";
            std::string emptyResFile;
            int emptyThrdNum;
            lookFor.setFlags(testDir, testLogFile, emptyResFile, emptyThrdNum);
            lookFor.searchForWord();
            lookFor.createLogFile();
            lookFor.createResFile();

            THEN("there should be default result file and changed log file") {
                CHECK(lookFor.getLogFileDir() == std::filesystem::current_path().parent_path().string() + "/" + testLogFile);
                CHECK(lookFor.getResFileDir() == std::filesystem::current_path().parent_path().string() + "/MyGrep.txt");
            }
            std::filesystem::remove(std::filesystem::path(lookFor.getLogFileDir()));
            std::filesystem::remove(std::filesystem::path(lookFor.getResFileDir()));
        }

        WHEN("there is '-d' flag for testing folder and '-r' to change log file name") {
            std::string testDir = std::filesystem::current_path().parent_path().string() + "/locs";
            std::string emptyLogFile;
            std::string testResFile = "testRes.txt";
            int emptyThrdNum;
            lookFor.setFlags(testDir, emptyLogFile, testResFile, emptyThrdNum);
            lookFor.searchForWord();
            lookFor.createLogFile();
            lookFor.createResFile();

            THEN("there should be changed result file and default log file") {
                CHECK(lookFor.getLogFileDir() == std::filesystem::current_path().parent_path().string() + "/MyGrep.log");
                CHECK(lookFor.getResFileDir() == std::filesystem::current_path().parent_path().string() + "/" + testResFile);
            }
            std::filesystem::remove(std::filesystem::path(lookFor.getLogFileDir()));
            std::filesystem::remove(std::filesystem::path(lookFor.getResFileDir()));
        }

        WHEN("there is '-d' flag for testing folder, '-l' and '-r' to change log and result files names") {
            std::string testDir = std::filesystem::current_path().parent_path().string() + "/locs";
            std::string testLogFile = "testLog.log";
            std::string testResFile = "testRes.txt";
            int emptyThrdNum;
            lookFor.setFlags(testDir, testLogFile, testResFile, emptyThrdNum);
            lookFor.searchForWord();
            lookFor.createLogFile();
            lookFor.createResFile();

            THEN("there should be changed result file and default log file") {
                CHECK(lookFor.getLogFileDir() == std::filesystem::current_path().parent_path().string() + "/" + testLogFile);
                CHECK(lookFor.getResFileDir() == std::filesystem::current_path().parent_path().string() + "/" + testResFile);
            }
            std::filesystem::remove(std::filesystem::path(lookFor.getLogFileDir()));
            std::filesystem::remove(std::filesystem::path(lookFor.getResFileDir()));
        }
    }
}