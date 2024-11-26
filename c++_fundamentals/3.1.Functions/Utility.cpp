#include "Utility.h"
#include <iostream>

using namespace std;

bool IsPrime(int x) {
    if (x <= 1) {
        return false;
    } else {
        for (int i = 2; i <= x / 2; i++) {
            if (x % i == 0) {
                return false;
            }
        }
    }
    return true;
}

bool IsTwoMorePrime(int& x) { // Pass by reference: the function can modify the argument
    return IsPrime(x + 2);
}