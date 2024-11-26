#include <iostream>
#include <vector>
#include <algorithm>

// Lambdas are anonymous functions that can be defined inline
// They can capture local variables by value or reference
// They can be used with STL algorithms

int main() {
    // Basic lambda definition and usage
    auto greet = []() { // [] is the lambda capture list, it captures all local variables by value
        std::cout << "Hello, World!" << std::endl;
    };
    greet();

    // Lambda with parameters
    auto add = [](int a, int b) -> int { // -> int is the return type of the lambda function
        return a + b;                    // a and b are the parameters to the lambda function
    };                                   // The return type can be omitted if the lambda has only one return statement
    std::cout << "Sum: " << add(5, 3) << std::endl;

    // Lambda capturing local variables by value
    int x = 10;
    auto captureByValue = [x]() { // x is captured by value (copied), any changes to x inside the lambda will NOT reflect outside
        std::cout << "Captured by value: " << x << std::endl;
    };
    captureByValue();

    // Lambda capturing local variables by reference
    auto captureByReference = [&x]() { // x is captured by reference, any changes to x inside the lambda will reflect outside
        x += 5;
        std::cout << "Captured by reference: " << x << std::endl;
    };
    captureByReference();
    std::cout << "Modified x: " << x << std::endl;

    // Lambda capturing all local variables by value
    int a = 1, b = 2;
    auto captureAllByValue = [=]() { // [=] captures all local variables by value
        std::cout << "Captured all by value: a = " << a << ", b = " << b << std::endl;
    };
    captureAllByValue();
    std::cout << "Unmodified a: " << a << ", Unmodified b: " << b << std::endl;

    // Lambda capturing all local variables by reference
    auto captureAllByReference = [&]() { // [&] captures all local variables by reference
        a += 3;
        b += 4;
        std::cout << "Captured all by reference: a = " << a << ", b = " << b << std::endl;
    };
    captureAllByReference();
    std::cout << "Modified a: " << a << ", Modified b: " << b << std::endl;

    // Lambda with mutable keyword and capturing by value
    int z = 30;
    auto mutableLambdaByValue = [z]() mutable { // mutable keyword allows changing the value of captured variables
        z += 10;
        std::cout << "Inside mutable lambda by value: " << z << std::endl;
    };
    mutableLambdaByValue();
    std::cout << "Outside mutable lambda by value: " << z << std::endl;

    // Lambda used with STL algorithms
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::for_each(numbers.begin(), numbers.end(), [](int n) { // [] is the lambda capture list, it captures all local variables by value
        std::cout << n << " ";                                // n is the parameter to the lambda function
    });
    std::cout << std::endl;

    // Lambda with mutable keyword
    int y = 20;
    auto mutableLambda = [y]() mutable {
        y += 10;
        std::cout << "Inside mutable lambda: " << y << std::endl;
    };
    mutableLambda();
    std::cout << "Outside mutable lambda: " << y << std::endl;

    return 0;
}