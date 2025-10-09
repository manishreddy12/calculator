#include "calculator.h"

// The main entry point for the executable
int main(int argc, char *argv[]) {
    // If a command-line argument is provided, process it.
    // This is how the Python web server will use the program.
    if (argc > 1) {
        processExpression(argv[1]);
    } else {
        // If no arguments are given, run the interactive menu
        // for local testing.
        app_main();
    }
    return 0;
}