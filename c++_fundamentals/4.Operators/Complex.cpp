#include "Complex.h"

// Operator overloading
// Operator overloading is a feature in C++ where a single operator can be used to perform different operations depending on the context.
// For example, the + operator can be used to add two numbers, concatenate two strings, or merge two arrays.
// The operator keyword is used to overload operators in C++.
// The syntax for overloading an operator is:
// return_type operator operator_symbol (parameters) { }
// The operator keyword is followed by the operator symbol that you want to overload.
// The operator symbol can be any of the C++ operators like +, -, *, /, %, =, ==, !=, <, >, etc.

// Operator overloading example
Complex::Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

// Overload + operator to add two Complex objects
Complex Complex::operator + (const Complex& obj) const {
    return Complex(real + obj.real, imag + obj.imag);
}

// Overload < operator to compare two Complex objects
bool Complex::operator < (const Complex& obj) const {
    return (real < obj.real) || (real == obj.real && imag < obj.imag);
}

// Overload < operator to compare a Complex object with a double
bool Complex::operator < (double value) const {
    return (real < value) || (real == value && imag < 0);
}

// Friend function to compare a double with a Complex object
bool operator < (double value, const Complex& obj) {
    return (value < obj.real) || (value == obj.real && 0 < obj.imag);
}

// Overload - operator to subtract two Complex objects
Complex Complex::operator - (const Complex& obj) const {
    return Complex(real - obj.real, imag - obj.imag);
}

// Getters
double Complex::GetReal() const {
    return real;
}

double Complex::GetImaginary() const {
    return imag;
}
