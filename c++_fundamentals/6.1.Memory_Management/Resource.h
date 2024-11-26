/**
 * @file Resource.h
 * @brief C++ Program to demonstrate manual memory management and the use of the free store for dynamic memory allocation.
 *
 * This file contains a class `Resource` that manages an integer pointer with manual memory allocation and deallocation.
 * It also demonstrates the use of the free store (heap) for dynamic memory allocation and the importance of proper memory management.
 *
 * Manual Memory Management:
 * In C++, manual memory management involves explicitly allocating and deallocating memory using `new` and `delete` operators.
 * This allows for dynamic memory allocation at runtime, but it also requires careful handling to avoid memory leaks and dangling pointers.
 *
 * Free Store:
 * The free store, also known as the heap, is a region of memory used for dynamic memory allocation.
 * Memory allocated on the free store persists until it is explicitly deallocated using `delete` or `delete[]`.
 * Proper management of free store memory is crucial to ensure efficient use of resources and to prevent memory-related issues.
 *
 * The `Resource` class:
 * - Acquires memory for an integer pointer in its constructor.
 * - Implements a copy constructor to perform a deep copy, avoiding double deletion.
 * - Deallocates the memory in its destructor.
 * - Provides methods to set and get the value of the managed integer.
 * - Includes a method `AddResource` to reallocate the integer pointer with a new value.
 */

#pragma once
#include <iostream>

class Resource {
public:
    Resource() {
        p = new int; // We used new to allocate memory on the free store which is not deallocated until we call delete
        std::cout << "Resource acquired\n";
    }

    // Copy constructor: deep copy of the resource is made to avoid double deletion of the same memory address when the object goes out of scope
    Resource(const Resource& other) {
        p = new int(*other.p);
        std::cout << "Resource copied\n";
    }

    ~Resource() {
        delete p;
        std::cout << "Resource destroyed\n";
    }

    void setValue(int value) {
        *p = value;
    }

    int getValue() const {
        return *p;
    }
    
    void AddResource(int value) {
        delete p;
        p = new int(value);
        std::cout << "Resource acquired\n";
    }

private:
    int* p;
};