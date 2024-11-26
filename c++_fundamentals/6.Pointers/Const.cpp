#include <iostream>

// Const: a keyword that specifies that the value of a variable cannot be changed.
// Const pointer: a pointer that cannot change the address it points to.
// Example: const int* ptr;
// Pointer to const: a pointer that cannot change the value it points to.
// Example: int const* ptr;
// Const pointer to const: a pointer that cannot change the address or the value it points to.
// Example: const int* const ptr;

void printValue(const int* ptr) {
    // *ptr = 20; // Error: cannot modify a const int
    std::cout << "Value: " << *ptr << std::endl;
}

void printReference(const int& ref) {
    // ref = 30; // Error: cannot modify a const int reference
    std::cout << "Reference to const int: " << ref << std::endl;
}

int main() {
    int value = 10;
    const int constantValue = 15;

    // Pointer to a constant integer
    const int* ptrToConst = &value;
    // *ptrToConst = 20; // Error: cannot modify a const int
    std::cout << "Pointer to const int: " << *ptrToConst << std::endl;
    std::cout << "Value: " << value << std::endl;

    // Constant pointer to an integer
    int* const constPtr = &value;
    *constPtr = 20; // Allowed: can modify the value
    std::cout << "Constant pointer to int: " << *constPtr << std::endl;
    std::cout << "Value: " << value << std::endl;

    // Constant pointer to a constant integer
    const int* const constPtrToConst = &constantValue;
    // *constPtrToConst = 25; // Error: cannot modify a const int
    std::cout << "Constant pointer to const int: " << *constPtrToConst << std::endl;
    std::cout << "ConstantValue: " << constantValue << std::endl;

    printValue(&constantValue);
    printReference(constantValue);

    // Const with indirection
    const int* ptr = &value; // Pointer to a constant integer
    int* const ptr2 = &value; // Constant pointer to an integer
    const int* const ptr3 = &value; // Constant pointer to a constant integer

    return 0;
}