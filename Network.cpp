#include <iostream>
#include "Network.hpp"

int Network::findID(std::string usrn)
{
    for(int i = 0; i < numUsers; i++)
    {
        if(profiles[i].getUsername() == usrn)
        {
            return i;
        }
    }
    return -1;   
}

Network::Network()
{
    for(int x = 0; x < MAX_USERS; x++)
    {
        for(int y = 0; y < MAX_USERS; y++)
        {
            following[x][y] = false;
        }
    }
    numUsers = 0;
}

bool Network::addUser(std::string usrn, std::string dspn)
{
    bool alphaNumeric = true;
    for(int i = 0; i < usrn.length(); i++)
    {
        if(!isalnum(usrn[i]))
        {
            alphaNumeric = false;
        }
    }
    if(usrn.length() > 0 && alphaNumeric && findID(usrn) == -1 && numUsers < MAX_USERS)
    {
        Profile p1(usrn, dspn);
        profiles[numUsers] = p1;
        numUsers++;
        return true;
    }
    return false;
}

bool Network::follow(std::string usrn1, std::string usrn2)
{
    if(findID(usrn1) != -1 && findID(usrn2) != -1)
    {
        following[findID(usrn1)][findID(usrn2)] = true;
        return true;
    }
    return false;
}

void Network::printDot()
{
    std::cout << "disgraph {\n";
    for(int i = 0; i < numUsers; i++)
    {
        std::cout << "   \"@" + profiles[i].getUsername() + "\"\n";
    }
    std::cout << "\n";

    for(int x = 0; x < numUsers; x++)
    {
        for(int y = 0; y < numUsers; y++)
        {
            if(following[x][y] == true)
            {
                std::cout << "   \"@" << profiles[x].getUsername() << "\" -> ""\"@" << profiles[y].getUsername() << "\"\n";  
            }
        }
    }
    std::cout << "}\n";
}