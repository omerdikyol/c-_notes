#include <iostream>
#include "Person.h"
#include "Tweeter.h"
#include <memory>

// Casting
// Casting is the process of converting one data type into another. In C++, there are four main types of casts:
// 1. C-style cast: (type)expression: This is the most flexible but also the most dangerous type of cast.
// 2. static_cast: static_cast<type>(expression): This is a safer alternative to C-style casting.
// 3. dynamic_cast: dynamic_cast<type>(expression): This is used for casting between polymorphic types (classes with virtual functions).
// 4. const_cast: const_cast<type>(expression): This is used to add or remove const or volatile qualifiers.

int main() {
    // Create a Person object using a shared_ptr
    std::shared_ptr<Person> personSharedPtr = std::make_shared<Person>("Alice", "Smith", 789);

    // Casting examples
    // 1. C-style cast
    int a = 10;
    double b = (double)a; // C-style cast
    std::cout << "C-style cast: " << b << std::endl;

    // 2. static_cast
    double c = static_cast<double>(a); // static_cast
    std::cout << "static_cast: " << c << std::endl;

    // 3. dynamic_cast
    Person* personDynamicPtr = new Tweeter("Eve", "Adams", 404, "@eveadams");
    Tweeter* tweeterDynamicPtr = dynamic_cast<Tweeter*>(personDynamicPtr); // dynamic_cast
    if (tweeterDynamicPtr) {
        std::cout << "dynamic_cast successful: ";
        tweeterDynamicPtr->PrintInfo();
    } else {
        std::cout << "dynamic_cast failed" << std::endl;
    }
    delete personDynamicPtr;

    // 4. const_cast
    const int d = 20;
    int* e = const_cast<int*>(&d); // const_cast
    *e = 30;
    std::cout << "const_cast: " << *e << std::endl;

    // 5. reinterpret_cast
    uintptr_t f = reinterpret_cast<uintptr_t>(personSharedPtr.get()); // reinterpret_cast
    std::cout << "reinterpret_cast: " << f << std::endl;
}