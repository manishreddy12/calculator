#include "calculator.h"
#include <iostream>
#include <cmath>
#include <limits>
#include <string>
#include <cstdlib>


//hello
long long factorial(int n) {
    if (n < 0) {
        std::cout << "Error: Factorial is not defined for negative numbers." << std::endl;
        return 0; 
    }
    if (n > 20) { // Prevent overflow for long long
        std::cout << "Error: Input too large for factorial." << std::endl;
        return 0;
    }
    if (n == 0 || n == 1) return 1;
    long long result = 1;
    for (int i = 2; i <= n; ++i) result *= i;
    return result;
}

double squareRoot(double x) {
    if (x < 0) {
        std::cout << "Error: Cannot calculate the square root of a negative number." << std::endl;
        return 0; 
    }
    return std::sqrt(x);
}

double naturalLog(double x) {
    if (x <= 0) {
        std::cout << "Error: Natural logarithm is undefined for x <= 0." << std::endl;
        return 0; 
    }
    return std::log(x);
}

double power(double base, double exponent) {
    return std::pow(base, exponent);
}

void processExpression(const std::string& expr) {
    try {
        if (expr.find("sqrt(") == 0) {
            double num = std::stod(expr.substr(5, expr.length() - 6));
            std::cout << "sqrt(" << num << ") = " << squareRoot(num) << std::endl;
        } else if (expr.find("ln(") == 0) {
            double num = std::stod(expr.substr(3, expr.length() - 4));
            std::cout << "ln(" << num << ") = " << naturalLog(num) << std::endl;
        } else if (expr.find("pow(") == 0) {
            size_t comma_pos = expr.find(',');
            double base = std::stod(expr.substr(4, comma_pos - 4));
            double exp = std::stod(expr.substr(comma_pos + 1, expr.length() - comma_pos - 2));
            std::cout << base << "^" << exp << " = " << power(base, exp) << std::endl;
        } else if (expr.find('!') != std::string::npos) {
            int num = std::stoi(expr.substr(0, expr.find('!')));
            long long result = factorial(num);
            if (result != 0 || num == 0) {
                 std::cout << num << "! = " << result << std::endl;
            }
        } else {
            std::cout << "Error: Invalid or unsupported expression format." << std::endl;
        }
    } catch (const std::exception& e) {
        std::cout << "Error: Invalid number format in expression." << std::endl;
    }
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
                if (std::cin >> x) std::cout << "Result: " << squareRoot(x) << std::endl;
                break;
            case 2:
                int n;
                std::cout << "Enter non-negative integer (x) for factorial: ";
                if (std::cin >> n) std::cout << "Result: " << factorial(n) << std::endl;
                break;
            case 3:
                std::cout << "Enter number (x > 0) for natural log: ";
                if (std::cin >> x) std::cout << "Result: " << naturalLog(x) << std::endl;
                break;
            case 4:
                std::cout << "Enter base (x): ";
                if (!(std::cin >> x)) break;
                std::cout << "Enter exponent (b): ";
                if (std::cin >> y) std::cout << "Result: " << power(x, y) << std::endl;
                break;
            case 5:
                std::cout << "Exiting calculator.\n";
                return 0;
            default:
                std::cout << "Invalid choice.\n";
        }
    }
}