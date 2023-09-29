#ifndef UNTITLED12_Stack_H
#define UNTITLED12_Stack_H

#include <cstdint>
#include "ostream"

class Stack {
public:
    Stack();

    void Push(int value);

    size_t Size() const;

    int Top() const;

    int Pop();

    void Print_stack();

    void Peek(int index);

    void New_value(int index, int Value);

    void Comparison(int index_1, int index_2);

    void operator<<(int value);

    void operator>>(int &to);

    Stack &operator=(const Stack &two);

    int &operator[](int index);

    friend std::ostream operator<<(std::ostream &stream, const Stack &stack);

    bool operator==(const Stack &other);

    bool operator<(const Stack &other);

    std::string ToString() const;

private:
    void Enlarge();

    size_t size_{0};
    size_t capacity_;
    int *values_;

};

#endif //STACK_H_
