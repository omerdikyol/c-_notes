#include <iostream>

int main() {
    // if statement
    // The if statement allows you to execute a block of code only if a specified condition is true.
    int x = 10;
    if (x > 5) {
        std::cout << "x is greater than 5" << std::endl;
    }

    if (x > 5)
        std::cout << "x is greater than 5" << std::endl;

    int a = 20;
    if (a < 30) {
        std::cout << "a is less than 30" << std::endl;
    } else {
        std::cout << "a is not less than 30" << std::endl;
    }

    int b = 15;
    if (b == 15) {
        std::cout << "b is 15" << std::endl;
    } else if (b > 15) {
        std::cout << "b is greater than 15" << std::endl;
    } else {
        std::cout << "b is less than 15" << std::endl;
    }

    // while loop
    // The while loop repeatedly executes a block of code as long as a specified condition is true.
    int y = 0;
    while (y < 5) {
        std::cout << "y is " << y << std::endl;
        y++;
    }

    // while loop with break and continue
    int n = 0;
    while (n < 10) {
        if (n == 5) {
            n++;
            continue; // Skip the rest of the code inside the loop for the current iteration
        }
        if (n == 2) {
            break; // Exit the loop when n is 8
        }
        std::cout << "n is " << n << std::endl;
        n++;
    }

    // Check if a user-inputted number is prime using while loop
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    bool isPrime = true;
    int i = 2;

    if (num <= 1) {
        isPrime = false;
    } else {
        while (i <= num / 2) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
            i++;
        }
    }

    if (isPrime) {
        std::cout << num << " is a prime number" << std::endl;
    } else {
        std::cout << num << " is not a prime number" << std::endl;
    }

    // do-while loop
    // The do-while loop is similar to the while loop, except that the condition is checked at the end of the loop.
    int d = 0;
    do {
        std::cout << "d is " << d << std::endl;
        d++;
    } while (d < 5);

    // for loop
    // The for loop is used to repeat a block of code a known number of times.
    for (int i = 0; i < 5; i++) { // Initialization; Condition; Increment
        std::cout << "i is " << i << std::endl;
    }

    // for loop with break and continue
    for (int j = 0; j < 10; j++) {
        if (j == 5) {
            continue; // Skip the rest of the code inside the loop for the current iteration
        }
        if (j == 8) {
            break; // Exit the loop when j is 8
        }
        std::cout << "j is " << j << std::endl;
    }

    // Check if a user-inputted number is prime using for loop
    int number;
    std::cout << "Enter another number: ";
    std::cin >> number;

    bool prime = true;

    if (number <= 1) {
        prime = false;
    } else {
        for (int k = 2; k <= number / 2; k++) {
            if (number % k == 0) {
                prime = false;
                break;
            }
        }
    }

    if (prime) {
        std::cout << number << " is a prime number" << std::endl;
    } else {
        std::cout << number << " is not a prime number" << std::endl;
    }

    // switch statement
    // The switch statement allows you to execute one block of code out of many based on the value of a variable.
    int z = 2;
    switch (z) {
        case 1:
            std::cout << "z is 1" << std::endl;
            break;
        case 2:
            std::cout << "z is 2" << std::endl;
            break;
        case 3:
            std::cout << "z is 3" << std::endl;
            break;
        case 4:
        case 5:
            std::cout << "z is 4 or 5" << std::endl;
            break;
        default:
            std::cout << "z is not 1, 2, or 3" << std::endl;
            break;
    }

    // Immediate if statement
    // The immediate if statement is a shorthand way of writing an if-else statement in a single line.
    int m = 10;
    std::string result = (m > 5) ? "m is greater than 5" : "m is not greater than 5";
    std::cout << result << std::endl;

    return 0;
}
