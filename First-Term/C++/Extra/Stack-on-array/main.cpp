#include <iostream>

#include "stack.h"

int main() {
    int p;
    Stack stack;
    stack << 12;
    stack.Print_stack();
    stack.Peek(2);
    stack.New_value(2, 3);
    stack.Print_stack();
    stack.Comparison(3, 2);
    stack >> p;
    stack[1];
    Stack b;
    return 0;

}

