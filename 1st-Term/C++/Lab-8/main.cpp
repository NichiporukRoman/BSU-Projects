#include <iostream>
#include "Calculator.h"
#include "stack.h"
#include <string>
int main() {
    std::string expression;
    std::cin >> expression;
    std::cout << Calculator::Calculate(expression)<< std::endl;;
    return 0;
}
