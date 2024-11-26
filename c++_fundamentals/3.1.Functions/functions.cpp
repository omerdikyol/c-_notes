#include <iostream>
#include "Utility.h"
#include "NumberChecker.h"

// Free Functions
// A function that is not a member of a class is called a free function.
// Functions defined in Utility.h and Utility.cpp are free functions.

// Member Functions
// A function that is a member of a class is called a member function.
// Functions defined in NumberChecker.h and NumberChecker.cpp are member functions.

int main(){
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;

    // Using Free Functions from Utility.h and Utility.cpp
    if (IsPrime(number)) { // Pass by value: the function will take a copy of the argument (number) so original value will not be modified
        std::cout << number << " is a prime number" << std::endl;
    } else {
        std::cout << number << " is not a prime number" << std::endl;
    }

    if (IsTwoMorePrime(number)) { // Pass by reference: the function will take the address of the argument (number) and modify it
        std::cout << number << " + 2 is a prime number" << std::endl;
    } else {
        std::cout << number << " + 2 is not a prime number" << std::endl;
    }

    // Using Member Functions from NumberChecker.cpp and NumberChecker.h
    // Create an instance of the class
    NumberChecker checker;
    // Call the member functions
    if (checker.IsEven(number)) {
        std::cout << number << " is an even number" << std::endl;
    } else {
        std::cout << number << " is an odd number" << std::endl;
    }

    if (checker.IsGood(number)) {
        std::cout << number << " is a good number" << std::endl;
    } else {
        std::cout << number << " is not a good number" << std::endl;
    }

    return 0;
}