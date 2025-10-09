#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string> // Add for std::string usage

// Core math functions
long long factorial(int n);
double squareRoot(double x);
double naturalLog(double x);
double power(double base, double exponent);

// New function to handle string expressions
void processExpression(const std::string& expression);

// Entry point for interactive calculator
int app_main();

#endif