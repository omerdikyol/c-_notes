#include <iostream>
#include <string>

/**
 * @brief Entry point of the program.
 * 
 * This function demonstrates the usage of various variable types in C++.
 * 
 * Variable types used:
 * - int: Integer variable, used to store whole numbers.
 *      Size: Typically 4 bytes, Range: -2,147,483,648 to 2,147,483,647.
 * - float: Floating point variable, used to store single-precision decimal numbers.
 *      Size: 4 bytes, Range: Approximately 1.2E-38 to 3.4E+38.
 * - double: Double precision floating point variable, used to store double-precision decimal numbers.
 *      Size: 8 bytes, Range: Approximately 2.3E-308 to 1.7E+308.
 *      Difference between float and double: float has 32 bits, double has 64 bits.
 * - long double: Extended precision floating point variable, used to store extended-precision decimal numbers.
 *     Size: 10 bytes, Range: Approximately 3.4E-4932 to 1.1E+4932.
 * - char: Character variable, used to store a single character.
 *      Size: 1 byte, Range: -128 to 127 or 0 to 255 (depends on whether it's signed or unsigned).
 * - bool: Boolean variable, used to store true or false values.
 *      Size: 1 byte, Range: true or false.t
 * - std::string: String variable, used to store sequences of characters (strings).
 * 
 * - Unsigned types: unsigned int, unsigned long, unsigned long long, etc. 
 *     These types are used to store only positive values.
 * - Signed types: signed int, signed long, signed long long, etc.
 *    These types are used to store both positive and negative values.
 * 
 * Automatic Type Deduction:
 * - C++11 introduced the auto keyword for automatic type deduction.
 * - The auto keyword automatically deduces the type of a variable based on the value assigned to it.
 * - The auto keyword is useful when the type of a variable is complex or when the type is not known.
 * - Example: auto x = 5; // x is deduced as an integer.
 * 
 * Casting:
 * - Casting is used to convert a variable from one type to another.
 * - There are two types of casting in C++: implicit and explicit.
 * - Implicit casting is done automatically by the compiler.
 * - Explicit casting is done manually by the programmer using casting operators.
 * - Examples of casting operators: static_cast, dynamic_cast, const_cast, reinterpret_cast.
 */

int main() {
    // Integer variable: 
    int grade(90);
    int newGrade{95};
    int age = 25;
    std::cout << "Age: " << age << std::endl;
    int newAge;

    newAge = age + 5;
    std::cout << "New Age: " << newAge << std::endl;

    // Floating point variable
    float height = 5.9;
    std::cout << "Height: " << height << std::endl;
    float newHeight(6.1);
    std::cout << "New Height: " << newHeight << std::endl;

    // Double variable
    double weight = 70.5;
    std::cout << "Weight: " << weight << std::endl;
    double newWeight{75.0};
    std::cout << "New Weight: " << newWeight << std::endl;

    // Create integer from double
    int intWeight = weight; // Implicit casting
    std::cout << "Integer Weight (implicit cast): " << intWeight << std::endl;

    // Explicit casting using static_cast
    int explicitIntWeight = static_cast<int>(weight);
    std::cout << "Integer Weight (explicit cast): " << explicitIntWeight << std::endl;

    // Character variable
    char grade = 'A';
    std::cout << "Grade: " << grade << std::endl;

    // Boolean variable
    bool isStudent = true;
    std::cout << "Is student: " << std::boolalpha << isStudent << std::endl;
    bool isGraduate = !isStudent;
    std::cout << "Is graduate: " << std::boolalpha << isGraduate << std::endl;

    // Automatic type deduction
    auto x = 5; // x is deduced as an integer
    auto y = 5.5; // y is deduced as a double
    auto z = "Hello"; // z is deduced as a const char*
    auto w = true; // w is deduced as a bool
    auto p = 3L; // p is deduced as a long
    auto q = 1'000'000'000'000; // q is deduced as a long long
    auto r = 0xFF; // r is deduced as an integer (hexadecimal) = 255
    auto s = 0b1010; // s is deduced as an integer (binary) = 10

    // String variable
    std::string name = "John Doe";
    std::cout << "Name: " << name << std::endl;
    std::string newName("Jane Doe");
    std::cout << "New Name: " << newName << std::endl;

    // Casting
    double d = 3.14;
    int i = static_cast<int>(d); // Explicit casting
    std::cout << "Double: " << d << ", Integer: " << i << std::endl;
    
    // The program waits for the user to press Enter before exiting.
    std::cout << "Press Enter to continue...";
    std::cin.get();

    return 0;
}
