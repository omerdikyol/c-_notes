#include "Tweeter.h"
#include <iostream>

Tweeter::Tweeter(std::string first, std::string last, int arbitrary, std::string handle)
        : Person(first, last, arbitrary), twitterhandle(handle) // Call the base class constructor to initialize the base class members
{
    std::cout << "constructing tweeter " << twitterhandle << std::endl;
}

Tweeter::~Tweeter()
{
    std::cout << "destructing tweeter " << twitterhandle << std::endl;
}