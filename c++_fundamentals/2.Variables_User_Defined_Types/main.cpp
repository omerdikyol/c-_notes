#include "Person.h"
#include "Tweeter.h"
#include "Status.h"
#include <iostream>

using std::string; // This is a using declaration. It tells the compiler that we're using the std::string type in this file

int main()
{
    // First Kate Gregory is constructed, // then Someone Else is constructed, then Someone Else is destructed, then Kate Gregory is destructed
    Person p1("Kate", "Gregory", 123);
    {
        Person p2("Someone", "Else", 456);
    }

    // First Ali Gol is constructed, then Ahmet Kaya is constructed,
    // then tweeter @ahmetkaya is constructed, then tweeter @ahmetkaya is destructed,
    // then Ahmet Kaya is destructed, then Ali Gol is destructed
    Person p3("Ali", "Gol", 456);
    {
        Tweeter t1("Ahmet", "Kaya", 789, "@ahmetkaya");
        std::cout << t1.getName() << std::endl;
    } // t1 is destructed here, it's scope is limited to the block

    std::cout << p1.getName() << std::endl;

    // Define a variable of type Status and assign a value to it
    Status s = Pending;
    s = Approved;

    return 0;
}