#include <iostream>
#include "Average.h"

// Template
// A template in C++ is a feature that allows functions and classes to operate with generic types.
// This enables you to write a function or a class that can work with any data type without being rewritten for each type.

// Template Function to return the maximum of two values
template <typename T> // T is a template type that will be replaced by the actual data type
T max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    int a = 10, b = 20;
    std::cout << "Max of " << a << " and " << b << " is " << max(a, b) << std::endl;

    double c = 10.5, d = 20.5;
    std::cout << "Max of " << c << " and " << d << " is " << max(c, d) << std::endl;

    char e = 'a', f = 'z';
    std::cout << "Max of " << e << " and " << f << " is " << max(e, f) << std::endl;

    // Using the Average template class
    Average<int> avgInt(a, b);
    std::cout << "Average of " << a << " and " << b << " is " << avgInt.getAverage() << std::endl;

    Average<double> avgDouble(c, d);
    std::cout << "Average of " << c << " and " << d << " is " << avgDouble.getAverage() << std::endl;

    // Using the Average template specialization for char type
    Average<char> charAvg('a', 'c');
    std::cout << "Average of 'a' and 'c' (char): " << charAvg.getAverage() << std::endl;

    return 0;
}

