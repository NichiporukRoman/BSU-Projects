#include "num.h"

namespace Number {
    const Number ZERO = Number(0);
    const Number ONE = Number(1);

    Number::Number(double value) : value_(value) {}

    double Number::GetNumber() const{
        return value_;
    }
    Number Number::operator+(const Number& other){
        return Number(value_ + other.value_);
    }

    Number Number::operator-(const Number& other){
        return Number(value_ - other.value_);
    }

    Number Number::operator*(const Number& other){
        return Number(value_ * other.value_);
    }

    Number Number::operator/(const Number& other){
        return Number(value_ / other.value_);
    }
    Number Number::operator=(const Number&){
        return Number(value_);
    }
    Number Number::operator=(double value){
        return Number(value);
    }

}