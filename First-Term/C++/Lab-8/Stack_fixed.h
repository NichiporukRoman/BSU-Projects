#ifndef UNTITLED12_Stack_H
#define UNTITLED12_Stack_H

#include <cstdint>
#include <iostream>

template <class T>
class Stack {
public:
    Stack();

    void Comparison(int index_1, int index_2);

    void Push(T value);

    size_t Size() const;

    T Top() const;

    T Pop();

    void Print_stack();

    void Peek(int index);

    void New_value(int index, T Value);

    void Comparison(int index_1, T index_2);

    void operator<<(T value);

    void operator>>(T &to);

    Stack &operator=(const Stack &two);

    T &operator[](int index);

    friend std::ostream operator<<(std::ostream &stream, const Stack &Stack);

    bool operator==(const Stack &other);

    bool operator<(const Stack &other);

    bool operator>(const Stack &other);

    std::string ToString() const;

    bool Empty();
private:
    void Enlarge();

    size_t size_{0};
    size_t capacity_;
    T *values_;
};

template<class T>
size_t Stack<T>::Size() const {
    return size_;
}

template<class T>
Stack<T>::Stack() : capacity_(16), values_(new T[capacity_]) {}

template<class T>
void Stack<T>::Push(T value) {
    if (size_ == capacity_) {
        Enlarge();
    }
    values_[size_] = value;
    size_++;
}

template<class T>
T Stack<T>::Top() const {
    return values_[size_ - 1];
}

template<class T>
void Stack<T>::Enlarge() {
    int new_capacity = capacity_ << 1;
    T *new_values = new T[new_capacity << 1];
    std::copy(values_, values_ + capacity_, new_values);
    delete[] values_;
    values_ = new_values;
    capacity_ = new_capacity;
}

template<class T>
T Stack<T>::Pop() {
    --size_;
    return values_[size_];
}

template<class T>
std::string Stack<T>::ToString() const {
    return std::string();
}

template<class T>
void Stack<T>::Print_stack() {
    std::cout << "All elements of stack are:" << std::endl;
    for (int i = 0; i < size_; i++) {
        std::cout << "[" << values_[i] << "] ";
    };
    std::cout << std::endl;
}

template<class T>
void Stack<T>::Peek(int index) {
    std::cout << "The element Number " << index << " is: " << values_[index - 1] << std::endl;
}

template<class T>
void Stack<T>::New_value(int index, T Value) {
    values_[index - 1] = Value;
    std::cout << values_[index - 1] << std::endl;
}

template<class T>
void Stack<T>::Comparison(int index_1, int index_2) {
    if (values_[index_1 - 1] == values_[index_2 - 1]) {
        std::cout << values_[index_1 - 1] << " = " << values_[index_2 - 1] << std::endl;
    } else {
        if ((values_[index_1 - 1] - values_[index_2 - 1]) > 0) {
            std::cout << values_[index_1 - 1] << " > " << values_[index_2 - 1] << std::endl;
        } else { std::cout << values_[index_1 - 1] << " < " << values_[index_2 - 1] << std::endl; }
    }
};

template<class T>
void Stack<T>::operator<<(T value) {
    Push(value);
};

template<class T>
void Stack<T>::operator>>(T &to) {
    to = Top();
    Pop();
}

template<class T>
Stack<T> &Stack<T>::operator=(const Stack &two) {
    if (this == &two)
        return *this;
    size_ = two.size_;
    capacity_ = two.capacity_;
    delete[] values_;
    values_ = new int[capacity_];
    for (int i = 0; i < capacity_; ++i) {
        values_[i] = two.values_[i];
    }
    return *this;
}

template<class T>
T &Stack<T>::operator[](int index) {
    return values_[index];
}

template<class T>
bool Stack<T>::operator==(const Stack &other) {
    if (other.size_ != size_) {
        return false;
    }
    for (int i = 0; i < size_; ++i) {
        if (values_[i] != other.values_[i]) {
            return false;
        }
    }

    return true;
}

template<class T>
bool Stack<T>::operator<(const Stack &other) {
    if (other.size_ != size_) {
        return size_ < other.size_;
    }
    for (int i = 0; i < size_; ++i) {
        if (values_[i] != other.values_[i]) {
            return values_[i] < other.values_[i];
        }
    }

    return true;
}

template<class T>
bool Stack<T>::Empty() {
    return size_ == 0;
}

#endif //STACK_H_

