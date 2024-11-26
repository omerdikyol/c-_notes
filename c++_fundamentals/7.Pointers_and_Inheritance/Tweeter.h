#ifndef TWEETER_H
#define TWEETER_H

#include <string>
#include "Person.h"

class Tweeter : public Person // Tweeter is a subclass of Person, so it inherits all of Person's members
{
    private:
        std::string twitterHandle;

    public:
        Tweeter(const std::string& firstName, const std::string& lastName, int id, const std::string& twitterHandle);
        std::string GetTwitterHandle() const;
        void PrintInfo() const;
};

#endif // TWEETER_H