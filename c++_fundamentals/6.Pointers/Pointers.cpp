// Definition: A pointer is a variable that stores the memory address of another variable.

#include <iostream>

int main() {
    int var = 42; // Declare an integer variable
    int* ptr = &var; // Declare a pointer and assign it the address of var

    std::cout << "Value of var: " << var << std::endl;
    std::cout << "Address of var: " << &var << std::endl;
    std::cout << "Value of ptr: " << ptr << std::endl;
    std::cout << "Value pointed to by ptr: " << *ptr << std::endl;

    // Changing the value pointed to by the pointer
    *ptr = 100;
    std::cout << "New value of var: " << var << std::endl;
    std::cout << "New value pointed to by ptr: " << *ptr << std::endl;

    // Incrementing a pointer
    int arr[] = {10, 20, 30};
    int* p = arr;

    std::cout << "Value pointed to by p: " << *p << std::endl;
    p++; // Move to the next element in the array
    std::cout << "Value pointed to by p after increment: " << *p << std::endl;

    // Using pointer to access members of a struct
    struct Point {
        int x, y;
    };

    Point point = {5, 10};
    Point* pointPtr = &point;

    std::cout << "Point x: " << pointPtr->x << std::endl;
    std::cout << "Point y: " << pointPtr->y << std::endl;

    // Changing the value of the pointer itself
    int anotherVar = 200;
    ptr = &anotherVar;
    std::cout << "New value of ptr: " << ptr << std::endl;
    std::cout << "New value pointed to by ptr: " << *ptr << std::endl;

    // Using nullptr
    int* nullPtr = nullptr;
    if (nullPtr == nullptr) {
        std::cout << "nullPtr is null" << std::endl;
    }

    return 0;
}
