#include "calculator.h"

int main() {
    return app_main();
}


/*
    to run only calc.cpp: g++ src/main.cpp src/calculator.cpp -o calculator -lm
./calculator
    to run tests: ./test_calculatorg++ tests/test_calculator.cpp src/calculator.cpp -lgtest -lgtest_main -lpthread -o test_calculator
./test_calculator

*/