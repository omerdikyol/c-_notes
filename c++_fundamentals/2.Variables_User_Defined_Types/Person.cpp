
#include "Person.h"
#include <iostream>

using namespace std; // This is a using directive. It tells the compiler that we're using the std namespace in this file, so we don't have to prefix standard library types with std::

Person::Person(string first, string last, int arbitrary) // This is the definition of the constructor, no return type is specified.
    : firstName(first), lastName(last), arbitraryNumber(arbitrary) // This is a member initializer list. It initializes the members of the class.
{
    cout << "constructing " << firstName << " " << lastName << endl;
}

Person::~Person() // This is the definition of the destructor, no return type is specified.
{
    cout << "destructing " << firstName << " " << lastName << endl;
}

string Person::getName()
{
    return firstName + " " + lastName;
}