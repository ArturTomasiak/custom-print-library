#include "src/print.h"

int main() {
    char* test = "hello world!";
    double result = 4.321;
    print_color(YELLOW);
    print("INFO: ");
    print_color(WHITE);
    print("function succeeded, result: ", result, "\n");
    print_color(RESET);
    print(test);
}