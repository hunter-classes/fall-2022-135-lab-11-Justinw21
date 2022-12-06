#include <iostream>
#include "Profile.hpp"
#include "Network.hpp"
int main()
{
    //Task A
    Profile p1("marco", "Marco");    
    std::cout << p1.getUsername() << std::endl; // marco
    std::cout << p1.getFullName() << std::endl; // Marco (@marco)

    p1.setDisplayName("Marco Rossi"); 
    std::cout << p1.getUsername() << std::endl; // marco
    std::cout << p1.getFullName() << std::endl; // Marco Rossi (@marco)
    
    Profile p2("tarma1", "Tarma Roving");    
    std::cout << p2.getUsername() << std::endl; // tarma1
    std::cout << p2.getFullName() << std::endl; // Tarma Roving (@tarma1)

    //Task B
    Network nw;
    std::cout << nw.addUser("mario", "Mario") << std::endl;     // true (1)
    std::cout << nw.addUser("luigi", "Luigi") << std::endl;     // true (1)

    std::cout << nw.addUser("mario", "Mario2") << std::endl;    // false (0)
    std::cout << nw.addUser("mario 2", "Mario2") << std::endl;  // false (0)
    std::cout << nw.addUser("mario-2", "Mario2") << std::endl;  // false (0)

    for(int i = 2; i < 20; i++)
    {
        std::cout << nw.addUser("mario" + std::to_string(i), 
        "Mario" + std::to_string(i)) << std::endl;   // true (1)
    }
    std::cout << nw.addUser("yoshi", "Yoshi") << std::endl;     // false (0)

    //Task C
    Network nw1;
    // add three users
    nw1.addUser("mario", "Mario");
    nw1.addUser("luigi", "Luigi");
    nw1.addUser("yoshi", "Yoshi");

    // make them follow each other
    nw1.follow("mario", "luigi");
    nw1.follow("mario", "yoshi");
    nw1.follow("luigi", "mario");
    nw1.follow("luigi", "yoshi");
    nw1.follow("yoshi", "mario");
    nw1.follow("yoshi", "luigi");

    // add a user who does not follow others
    nw1.addUser("wario", "Wario");
    
    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        std::string usrn = "mario" + std::to_string(i);
        std::string dspn = "Mario " + std::to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    nw1.follow("mario2", "luigi");

    nw1.printDot();
}