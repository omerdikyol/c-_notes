#ifndef UTILITY_H
#define UTILITY_H

// Free functions: functions that are not members of a class

bool IsPrime(int x);

bool IsTwoMorePrime(int& x); // Pass by reference: the function can modify the argument

// int& BadFunction(); // This function returns a reference to a local variable, which is a bad practice

#endif // UTILITY_H