#include <iostream>
#include <vector>

// Define a new name for an existing type
typedef unsigned long ulong;
typedef std::vector<int> IntVector;

// Define a struct and use typedef to create an alias for it
struct Point {
    int x;
    int y;
};
typedef struct Point Point;

// Define a typedef for a function pointer
typedef int (*FuncPtr)(int, int);

int main() {
    // typedef 

    // Using the typedef alias for unsigned long
    // ulong largeNumber = 1234567890;
    // std::cout << "Large number: " << largeNumber << std::endl;

    // Using the typedef alias for std::vector<int>
    // IntVector numbers = {1, 2, 3, 4, 5};
    // for (int num : numbers) {
    //     std::cout << num << " ";
    // }
    // std::cout << std::endl;

    // -----------------------------------------------

    // typedef for struct and function pointers

    // Using the typedef alias for struct Point
    // Point p1;
    // p1.x = 10;

    // Define a typedef for a function pointer
    // typedef int (*FuncPtr)(int, int);

    // Define a function that matches the function pointer type
    // int add(int a, int b) {
    //     return a + b;
    // }

    // Use the function pointer typedef
    // FuncPtr func = add;
    // int result = func(5, 10);
    // std::cout << "Result of function pointer call: " << result << std::endl;

    // -----------------------------------------------

    // Using void pointers

    // They can point to any type of data, but you need to cast them to the correct type before using
    // void* voidPtr;
    // int a = 10;
    // voidPtr = &a;

    // Casting void pointer back to int pointer
    // int* intPtr = static_cast<int*>(voidPtr);
    // std::cout << "Value pointed to by voidPtr: " << *intPtr << std::endl;

    // -----------------------------------------------

    // C Style Arrays

    // int arr[5] = {1, 2, 3, 4, 5};
    // int arr2[2][3] = {{1, 2, 3}, {4, 5, 6}};

    // int* arr3 = new int[4];
    // arr3[0] = 1;
    // arr3[1] = 2;
    // *(arr3+2) = 3;
    // *(arr3+3) = 4;

    // int localsize = sizeof(arr) / sizeof(arr[0]);
    // int freesize = sizeof(arr3) / sizeof(arr3[0]);

    // -----------------------------------------------

    // C Style Strings

    // char str[] = "Hello, World!";
    // char* str2 = "Hello, World!";

    // char str3[6] = {'H', 'e', 'l', 'l', 'o', '\0'};

    // char* str4 = new char[6];
    // str4[0] = 'H';
    // str4[1] = 'e';
    // str4[2] = 'l';
    // str4[3] = 'l';
    // str4[4] = 'o';
    // str4[5] = '\0';

    // -----------------------------------------------

    return 0;
}