#include "number.h"
namespace Number {
    const Number ZERO = Number(0);
    const Number ONE = Number(1);

    Number::Number(double value) : value_(value) {}

    double Number::GetNumber() const{
        return value_;
    }
    Number Number::operator+(const Number& other) const {
        return Number(value_ + other.value_);
    }

    Number Number::operator-(const Number& other) const {
        return Number(value_ - other.value_);
    }

    Number Number::operator*(const Number& other) const {
        return Number(value_ * other.value_);
    }

    Number Number::operator/(const Number& other) const {
        return Number(value_ / other.value_);
    }
    Number Number::operator=(const Number&) const {
        return Number(value_);
    }
    Number Number::operator=(double value) const {
        return Number(value);
    }

}
