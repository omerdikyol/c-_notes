#include <iostream>
#include "Complex.h"

int main() {
    // Arithmetic Operators
    int a = 10, b = 5;
    std::cout << "Arithmetic Operators:" << std::endl;
    std::cout << "a + b = " << (a + b) << std::endl; // Addition
    std::cout << "a - b = " << (a - b) << std::endl; // Subtraction
    std::cout << "a * b = " << (a * b) << std::endl; // Multiplication
    std::cout << "a / b = " << (a / b) << std::endl; // Division
    std::cout << "a % b = " << (a % b) << std::endl; // Modulus
    std::cout << "++a = " << ++a << std::endl;        // Increment
    std::cout << "--b = " << --b << std::endl;        // Decrement
    std::cout << "a++ = " << a++ << std::endl;        // Post-increment
    std::cout << "b-- = " << b-- << std::endl;        // Post-decrement

    // Shortcuts
    std::cout << "\nShortcuts:" << std::endl;
    a += b; // Equivalent to a = a + b
    std::cout << "a += b: " << a << std::endl;
    a -= b; // Equivalent to a = a - b
    std::cout << "a -= b: " << a << std::endl;
    a *= b; // Equivalent to a = a * b
    std::cout << "a *= b: " << a << std::endl;
    a /= b; // Equivalent to a = a / b
    std::cout << "a /= b: " << a << std::endl;

    // Comparison Operators
    std::cout << "\nComparison Operators:" << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl; // Equal to
    std::cout << "a != b: " << (a != b) << std::endl; // Not equal to
    std::cout << "a > b: " << (a > b) << std::endl;   // Greater than
    std::cout << "a < b: " << (a < b) << std::endl;   // Less than
    std::cout << "a >= b: " << (a >= b) << std::endl; // Greater than or equal to
    std::cout << "a <= b: " << (a <= b) << std::endl; // Less than or equal to
    
    // Logical Operators
    bool c = true, d = false;
    std::cout << "\nLogical Operators:" << std::endl;
    std::cout << "c && d: " << (c && d) << std::endl; // Logical AND
    std::cout << "c || d: " << (c || d) << std::endl; // Logical OR
    std::cout << "!c: " << (!c) << std::endl;         // Logical NOT

    // Bitwise Operators
    int x = 6, y = 3; // 6 = 110, 3 = 011 in binary
    std::cout << "\nBitwise Operators:" << std::endl;
    
    // AND: Compares each bit of x and y. Result bit is 1 if both bits are 1.
    std::cout << "x & y = " << (x & y) << " // 110 & 011 = 010 (2 in decimal)" << std::endl;
    
    // OR: Compares each bit of x and y. Result bit is 1 if at least one bit is 1.
    std::cout << "x | y = " << (x | y) << " // 110 | 011 = 111 (7 in decimal)" << std::endl;
    
    // XOR: Compares each bit of x and y. Result bit is 1 if the bits are different.
    std::cout << "x ^ y = " << (x ^ y) << " // 110 ^ 011 = 101 (5 in decimal)" << std::endl;
    
    // NOT: Inverts all the bits of x. Result is the one's complement of x.
    std::cout << "~x = " << (~x) << " // ~110 = 001 (in 2's complement form, -7 in decimal)" << std::endl;
    
    // Left shift: Shifts the bits of x to the left by 1 position. Each shift left multiplies by 2.
    std::cout << "x << 1 = " << (x << 1) << " // 110 << 1 = 1100 (12 in decimal)" << std::endl;
    
    // Right shift: Shifts the bits of x to the right by 1 position. Each shift right divides by 2.
    std::cout << "x >> 1 = " << (x >> 1) << " // 110 >> 1 = 011 (3 in decimal)" << std::endl;

    Complex c1(3.0, 4.0);
    Complex c2(1.0, 2.0);
    Complex c3 = c1 + c2;

    std::cout << "\nComplex number addition:" << std::endl;
    std::cout << "c1.real = " << c1.GetReal() << ", c1.imaginary = " << c1.GetImaginary() << std::endl;
    std::cout << "c2.real = " << c2.GetReal() << ", c2.imaginary = " << c2.GetImaginary() << std::endl;
    std::cout << "c3.real = " << c3.GetReal() << ", c3.imaginary = " << c3.GetImaginary() << std::endl;

    // Complex number comparison
    std::cout << "\nComplex number comparison:" << std::endl;
    std::cout << "c1 < c2: " << (c1 < c2) << std::endl;
    std::cout << "c1 < 5.0: " << (c1 < 5.0) << std::endl;
    std::cout << "5.0 < c1: " << (5.0 < c1) << std::endl;

    Complex c4 = c1 - c2;
    std::cout << "\nComplex number subtraction:" << std::endl;
    std::cout << "c4.real = " << c4.GetReal() << ", c4.imaginary = " << c4.GetImaginary() << std::endl;

    return 0;
}