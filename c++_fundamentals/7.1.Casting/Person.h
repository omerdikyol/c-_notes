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
    int id;

// Declare the constructor and destructor as public. This is the interface of the class.
public:
    Person(const std::string& firstName, const std::string& lastName, int id);
    virtual ~Person() = default; // Virtual destructor to ensure proper cleanup of derived classes
    std::string GetName() const;
    virtual void PrintInfo() const; // Virtual function to allow overriding in derived classes
};

#endif // PERSON_H