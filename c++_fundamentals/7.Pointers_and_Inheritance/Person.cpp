#include "Person.h"
#include <iostream>

using namespace std; // This is a using directive. It tells the compiler that we're using the std namespace in this file, so we don't have to prefix standard library types with std::

Person::Person(const std::string& firstName, const std::string& lastName, int id)
    : firstName(firstName), lastName(lastName), id(id) {}

std::string Person::GetName() const {
    return firstName + " " + lastName;
}

void Person::PrintInfo() const {
    std::cout << "Name: " << GetName() << ", ID: " << id << std::endl;
}