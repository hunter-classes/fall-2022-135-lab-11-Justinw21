#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Profile.hpp"
#include "Network.hpp"
#include <string>

TEST_CASE("TASK A")
{
    Profile p1("marco", "Marco");    
    CHECK(p1.getUsername() == "marco");
    CHECK(p1.getFullName() == "Marco (@marco)");
    p1.setDisplayName("Marco Rossi"); 
    CHECK(p1.getFullName() == "Marco Rossi (@marco)"); 
    Profile p2("tarma1", "Tarma Roving");    
    CHECK(p2.getUsername() == "tarma1");
    CHECK(p2.getFullName() == "Tarma Roving (@tarma1)");
}

TEST_CASE("TASK B + C")
{
    Network nw;

    CHECK(nw.addUser("first", "Justin"));
    CHECK(nw.addUser("second", "David"));

    CHECK(!nw.addUser("first", "Jeff"));
    CHECK(!nw.addUser("second", "Mike"));

    CHECK(nw.follow("first", "second"));
    CHECK(nw.follow("second", "first"));

    for(int i = 2; i < 20; i++)
    {
        std::cout << nw.addUser("mario" + std::to_string(i), 
        "Mario" + std::to_string(i)) << std::endl;   // true (1)
    }
    CHECK(!nw.addUser("Mom", "Dad"));
}
