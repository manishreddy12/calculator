#include <gtest/gtest.h>
#include <cmath>

// Forward declarations of the functions from src/calculator.cpp
long long factorial(int n);
double squareRoot(double x);
double naturalLog(double x);
double power(double base, double exponent);

// Test Suite for Square Root
TEST(ScientificCalculatorTest, SquareRootValid) {
    ASSERT_NEAR(squareRoot(4.0), 2.0, 1e-9);
    ASSERT_NEAR(squareRoot(16.0), 4.0, 1e-9);
    ASSERT_NEAR(squareRoot(9.0), 3.0, 1e-9);
    ASSERT_NEAR(squareRoot(0.0), 0.0, 1e-9);
    ASSERT_NEAR(squareRoot(2.0), 1.414213562, 1e-9);
}

TEST(ScientificCalculatorTest, SquareRootInvalid) {
    // Should handle negative input (returns 0 and prints error to cerr)
    ASSERT_EQ(squareRoot(-4.0), 0.0);
}

// Test Suite for Factorial
TEST(ScientificCalculatorTest, FactorialValid) {
    ASSERT_EQ(factorial(0), 1);
    ASSERT_EQ(factorial(1), 1);
    ASSERT_EQ(factorial(5), 120);
    ASSERT_EQ(factorial(10), 3628800);
}

TEST(ScientificCalculatorTest, FactorialInvalid) {
    // Should handle negative input (returns 0 and prints error to cerr)
    ASSERT_EQ(factorial(-1), 0);
}

// Test Suite for Natural Logarithm
TEST(ScientificCalculatorTest, NaturalLogValid) {
    ASSERT_NEAR(naturalLog(1.0), 0.0, 1e-9);
    ASSERT_NEAR(naturalLog(2.718281828), 1.0, 1e-9); // ln(e)
}

TEST(ScientificCalculatorTest, NaturalLogInvalid) {
    // Should handle zero and negative input (returns 0 and prints error)
    ASSERT_EQ(naturalLog(0.0), 0.0);
    ASSERT_EQ(naturalLog(-1.0), 0.0);
}

// Test Suite for Power Function
TEST(ScientificCalculatorTest, PowerFunction) {
    ASSERT_NEAR(power(2.0, 3.0), 8.0, 1e-9);
    ASSERT_NEAR(power(5.0, 0.0), 1.0, 1e-9);
    ASSERT_NEAR(power(4.0, 0.5), 2.0, 1e-9); // Square root
    ASSERT_NEAR(power(10.0, -1.0), 0.1, 1e-9);
}

// The main function to run all tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}