#include <iostream>
#include "Person.h"
#include "Tweeter.h"
#include <memory>

int main() {
    // Create a Person object using a pointer
    Person* personPtr = new Person("John", "Doe", 123);
    std::cout << "Created Person: " << std::endl;
    personPtr->PrintInfo();

    // Create a Tweeter object using a pointer
    Tweeter* tweeterPtr = new Tweeter("Jane", "Doe", 456, "@janedoe");
    std::cout << "Created Tweeter: " << std::endl;
    tweeterPtr->PrintInfo();

    // Clean up memory
    delete personPtr;
    delete tweeterPtr;

    // Create a Person object using a shared_ptr
    std::shared_ptr<Person> personSharedPtr = std::make_shared<Person>("Alice", "Smith", 789);
    std::cout << "Created Person with shared_ptr: " << std::endl;
    personSharedPtr->PrintInfo(); // This will call the Person::PrintInfo() function

    // Create a Tweeter object using a shared_ptr
    std::shared_ptr<Tweeter> tweeterSharedPtr = std::make_shared<Tweeter>("Bob", "Smith", 101, "@bobsmith");
    std::cout << "Created Tweeter with shared_ptr: " << std::endl;
    tweeterSharedPtr->PrintInfo(); // This will call the Tweeter::PrintInfo() function

    // No need to manually clean up memory with shared_ptr

    // Object slicing: Create a Tweeter object and assign it to a Person object
    Person person = Tweeter("Charlie", "Brown", 202, "@charlieb");
    std::cout << "Created Tweeter assigned to Person (slicing): " << std::endl;
    person.PrintInfo(); // This will call the Person::PrintInfo() function

    // Polymorphism: Create a Tweeter object and assign it to a Person pointer
    Person* polymorphicPersonPtr = new Tweeter("Dave", "Clark", 303, "@daveclark");
    std::cout << "Created Tweeter assigned to Person pointer (polymorphism): " << std::endl;
    polymorphicPersonPtr->PrintInfo(); // This will call the Tweeter::PrintInfo() function

    // Clean up memory
    delete polymorphicPersonPtr;

    // Casting and Indirection: Create a Tweeter object and assign it to a Person pointer
    Tweeter tweeter = Tweeter("Eve", "White", 404, "@evewhite");
    Person* personFromTweeterPtr = &tweeter;
    std::cout << "Created Tweeter assigned to Person pointer (casting and indirection): " << std::endl;
    personFromTweeterPtr->PrintInfo(); // This will call the Person::PrintInfo() function

    return 0;
}
