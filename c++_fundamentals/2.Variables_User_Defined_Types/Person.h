#ifndef PERSON_H // This is a header guard. It prevents the header from being included more than once.
#define PERSON_H

#include <string>

// Don't use using namespace in header files. It's better to use it in the .cpp files.

class Person
{
// Declare the members of the class as private. This is called encapsulation.
private:
    std::string firstName; 
    std::string lastName;
    int arbitraryNumber;

// Declare the constructor and destructor as public. This is the interface of the class.
public:
    Person(std::string first, std::string last, int arbitrary);
    ~Person();
    std::string getName();
};

#endif // PERSON_H