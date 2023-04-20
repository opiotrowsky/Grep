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