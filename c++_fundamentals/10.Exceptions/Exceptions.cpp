#include <iostream>
#include <stdexcept>
#include <vector>
#include <limits>

// Exceptions are a way to handle errors in C++ programs. They allow you to separate error handling code from normal code.
// Exceptions are thrown using the throw keyword and caught using the try-catch block.
// The try block contains the code that might throw an exception, and the catch block contains the code that handles the exception.
// If an exception is thrown in the try block, the program will jump to the catch block, skipping the rest of the code in the try block.

// std::exception is the base class for all standard C++ exceptions. It has a virtual function called what() that returns a C-style string describing the exception.
// logic_error:
//  - domain_error
//  - invalid_argument
//  - length_error
//  - out_of_range
// runtime_error:
//  - overflow_error
//  - underflow_error
//  - range_error

int main() {
    try {
        std::vector<int> vec{1, 2, 3};
        std::cout << vec.at(5) << std::endl; // This will throw an out_of_range exception
    } catch (const std::out_of_range &e) {
        std::cout << "Caught an out_of_range error: " << e.what() << std::endl;
    }

    try {
        int* arr = new int[5];
        delete[] arr;
        std::cout << arr[10] << std::endl; // Accessing deleted memory, undefined behavior
    } catch (const std::exception &e) {
        std::cout << "Caught an exception: " << e.what() << std::endl;
    }

    try {
        int a = 10;
        int b = 0;
        std::cout << a / b << std::endl;
    } catch (const std::runtime_error &e) {
        std::cout << "Caught a runtime error: " << e.what() << std::endl;
    }

    try {
        std::string().at(1); // Accessing an empty string, will throw a std::out_of_range which is a type of std::logic_error
    } catch (const std::logic_error &e) {
        std::cout << "Caught a logic error: " << e.what() << std::endl;
    }

    try {
        int max = std::numeric_limits<int>::max(); // Maximum value of int (#include <limits>)
        int result = max + 1; // This will cause an overflow
        std::cout << result << std::endl;
    } catch (const std::overflow_error &e) {
        std::cout << "Caught an overflow error: " << e.what() << std::endl;
    }

    try {
        int min = std::numeric_limits<int>::min();
        int result = min - 1; // This will cause an underflow
        std::cout << result << std::endl;
    } catch (const std::underflow_error &e) {
        std::cout << "Caught an underflow error: " << e.what() << std::endl;
    }

    // Exception hierarchy: Try to catch the most specific exception first
    try {
        throw std::runtime_error("This is a runtime error");
    } catch (const std::runtime_error &e) {
        std::cout << "Caught a runtime error: " << e.what() << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Caught an exception: " << e.what() << std::endl;
    } catch (...) {
        std::cout << "Caught an unknown exception" << std::endl;
    }

    // Throwing exceptions: You can throw any type of object as an exception
    
    // Throwing a string
    try {
        throw std::string("This is a string exception");
    } catch (const std::string &e) {
        std::cout << "Caught a string exception: " << e << std::endl;
    }

    // Throwing an exception object
    try {
        throw std::runtime_error("This is a runtime error");
    } catch (const std::runtime_error &e) {
        std::cout << "Caught a runtime error: " << e.what() << std::endl;
    }

    // Throwing a custom exception
    class CustomException : public std::exception {
    public:
        const char* what() const noexcept override {
            return "This is a custom exception";
        }
    };

    try {
        throw CustomException();
    } catch (const CustomException &e) {
        std::cout << "Caught a custom exception: " << e.what() << std::endl;
    }

    // Unwind stack: When an exception is thrown, the program will unwind the stack, calling destructors for all objects in scope until it finds a matching catch block.
    // If no matching catch block is found, the program will terminate.
    try {
        std::cout << "Before throwing exception" << std::endl;
        throw std::runtime_error("This is a runtime error");
        std::cout << "After throwing exception" << std::endl; // This will not be executed
    } catch (const std::runtime_error &e) {
        std::cout << "Caught a runtime error: " << e.what() << std::endl;
    }

    return 0;
}