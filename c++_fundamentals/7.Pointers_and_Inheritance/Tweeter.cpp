#include "Tweeter.h"
#include <iostream>

Tweeter::Tweeter(const std::string& firstName, const std::string& lastName, int id, const std::string& twitterHandle)
    : Person(firstName, lastName, id), twitterHandle(twitterHandle) {}

std::string Tweeter::GetTwitterHandle() const {
    return twitterHandle;
}

void Tweeter::PrintInfo() const {
    Person::PrintInfo();
    std::cout << "Twitter Handle: " << twitterHandle << std::endl;
}