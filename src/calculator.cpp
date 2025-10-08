#include <iostream>
#include <cmath>
#include <limits>
#include <cstdlib>

// Function to calculate the factorial of a number
long long factorial(int n) {
    if (n < 0) {
        std::cerr << "Error: Factorial is not defined for negative numbers." << std::endl;
        return 0; 
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Function to calculate the square root (√x)
double squareRoot(double x) {
    if (x < 0) {
        std::cerr << "Error: Cannot calculate the square root of a negative number." << std::endl;
        return 0; 
    }
    return std::sqrt(x);
}

// Function to calculate the natural logarithm (ln(x))
double naturalLog(double x) {
    if (x <= 0) {
        std::cerr << "Error: Natural logarithm is undefined for x <= 0." << std::endl;
        return 0; 
    }
    return std::log(x);
}

// Function to calculate the power function (x^b)
double power(double base, double exponent) {
    return std::pow(base, exponent);
}

void displayMenu() {
    std::cout << "\nScientific Calculator Menu:\n";
    std::cout << "1. Square Root (sqrt(x))\n";
    std::cout << "2. Factorial (x!)\n";
    std::cout << "3. Natural Logarithm (ln(x))\n";
    std::cout << "4. Power Function (x^b)\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice (1-5): ";
}

int app_main() {
    int choice;
    double x, y;

    while (true) {
        displayMenu();
        if (!(std::cin >> choice)) {
            std::cerr << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                std::cout << "Enter number (x) for square root: ";
                if (std::cin >> x) {
                    double result = squareRoot(x);
                    if (result != 0 || x == 0) {
                        std::cout << "Result: sqrt(" << x << ") = " << result << std::endl;
                    }
                }
                break;
            case 2:
                int n;
                std::cout << "Enter non-negative integer (x) for factorial: ";
                if (std::cin >> n) {
                    long long result = factorial(n);
                    if (result != 0 || n == 0) {
                        std::cout << "Result: " << n << "! = " << result << std::endl;
                    }
                }
                break;
            case 3:
                std::cout << "Enter number (x > 0) for natural log: ";
                if (std::cin >> x) {
                    double result = naturalLog(x);
                    if (result != 0 || x == 1) {
                        std::cout << "Result: ln(" << x << ") = " << result << std::endl;
                    }
                }
                break;
            case 4:
                std::cout << "Enter base (x): ";
                if (!(std::cin >> x)) break;
                std::cout << "Enter exponent (b): ";
                if (std::cin >> y) {
                    double result = power(x, y);
                    std::cout << "Result: " << x << "^" << y << " = " << result << std::endl;
                }
                break;
            case 5:
                std::cout << "Exiting calculator.\n";
                return 0;
            default:
                std::cout << "Invalid choice.\n";
        }
    }
}