#include "stack.h"
#include <iostream>

size_t Stack::Size() const {
    return size_;
}

Stack::Stack() : capacity_(16), values_(new int[capacity_]) {}

void Stack::Push(int value) {
    if (size_ == capacity_) {
        Enlarge();
    }
    values_[size_] = value;
    size_++;
}

int Stack::Top() const {
    return values_[size_ - 1];
}

void Stack::Enlarge() {
    int new_capacity = capacity_ << 1;
    int *new_values = new int[new_capacity << 1];
    std::copy(values_, values_ + capacity_, new_values);
    delete[] values_;
    values_ = new_values;
    capacity_ = new_capacity;
}

int Stack::Pop() {
    --size_;
    return values_[size_];
}

std::string Stack::ToString() const {
    return std::string();
}

void Stack::Print_stack() {
    std::cout << "All elements of stack are:" << std::endl;
    for (int i = 0; i < size_; i++) {
        std::cout << "[" << values_[i] << "] ";
    };
    std::cout << std::endl;
}

void Stack::Peek(int index) {
    std::cout << "The element Number " << index << " is: " << values_[index - 1] << std::endl;
}

void Stack::New_value(int index, int Value) {
    values_[index - 1] = Value;
    std::cout << values_[index - 1] << std::endl;
}

void Stack::Comparison(int index_1, int index_2) {
    if (values_[index_1 - 1] == values_[index_2 - 1]) {
        std::cout << values_[index_1 - 1] << " = " << values_[index_2 - 1] << std::endl;
    } else {
        if ((values_[index_1 - 1] - values_[index_2 - 1]) > 0) {
            std::cout << values_[index_1 - 1] << " > " << values_[index_2 - 1] << std::endl;
        } else { std::cout << values_[index_1 - 1] << " < " << values_[index_2 - 1] << std::endl; }
    }
};

void Stack::operator<<(int value) {
    Push(value);
};

void Stack::operator>>(int &to) {
    to = Top();
    Pop();
}

Stack &Stack::operator=(const Stack &two) {
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

int &Stack::operator[](int index) {
    return values_[index];
}

bool Stack::operator==(const Stack &other){
    if(other.size_ != size_) {
        return false;
    }
    for (int i = 0; i < size_; ++i) {
        if (values_[i] != other.values_[i]) {
            return false;
        }
    }

    return true;
}

bool Stack::operator<(const Stack &other){
    if(other.size_ != size_) {
        return size_ < other.size_;
    }
    for (int i = 0; i < size_; ++i) {
        if (values_[i] != other.values_[i]) {
            return values_[i] < other.values_[i];
        }
    }

    return true;
}