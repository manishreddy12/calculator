CXX = g++
CXXFLAGS = -std=c++17 -Wall
LDFLAGS = -lm
TEST_LIBS = -lgtest -lgtest_main -lpthread

SRC = src/calculator.cpp
MAIN = src/main.cpp
TEST = tests/test_calculator.cpp

all: calculator test

calculator: $(SRC) $(MAIN)
	$(CXX) $(CXXFLAGS) $(SRC) $(MAIN) -o calculator $(LDFLAGS)

test: $(SRC) $(TEST)
	$(CXX) $(CXXFLAGS) $(SRC) $(TEST) -o test_calculator $(TEST_LIBS)

clean:
	rm -f calculator test_calculator
