#pragma once // This is a preprocessor directive that tells the compiler to include this file only once in the compilation process

#include <string>
#include "Person.h"

class Tweeter : public Person // Tweeter is a subclass of Person, so it inherits all of Person's members
{
    private:
        std::string twitterhandle;

    public:
        Tweeter(std::string first, std::string last, int arbitrary, std::string handle);
        ~Tweeter();
};