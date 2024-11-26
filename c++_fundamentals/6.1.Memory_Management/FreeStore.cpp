#include <iostream>
#include "Resource.h"

int main() {
    {
        Resource res;
        res.setValue(42);
        std::cout << "Value: " << res.getValue() << std::endl;
    } // Resource goes out of scope and memory is deallocated here

    {
        int* arr = new int[5];
        int* p2 = arr;

        for (int i = 0; i < 5; ++i) {
            arr[i] = i * 10;
        }

        for (int i = 0; i < 5; ++i) {
            std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
        }

        delete[] arr;
    } // Array memory is deallocated here

    //delete p2; // Error: since arr is deleted, p2 is now a dangling pointer, which cannot be deleted

    Resource res1;
    res1.setValue(100);
    std::cout << "res1 Value: " << res1.getValue() << std::endl;

    Resource res2 = res1; // Copy constructor is called
    std::cout << "res2 Value after copy: " << res2.getValue() << std::endl;

    res2.setValue(200);
    std::cout << "res2 Value after modification: " << res2.getValue() << std::endl;
    std::cout << "res1 Value after res2 modification: " << res1.getValue() << std::endl;

    res1.AddResource(300);
    std::cout << "res1 Value after AddResource: " << res1.getValue() << std::endl;

    return 0;
}