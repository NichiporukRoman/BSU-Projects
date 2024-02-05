#pragma once

#include "pch.h"
#include "framework.h"

namespace Number
{

    class Number
    {
    public:
        Number(double value);
        Number() = default;
        ~Number() = default;

        Number operator+(const Number&);
        Number operator-(const Number&);
        Number operator/(const Number&);
        Number operator*(const Number&);
        double GetNumber() const;
        Number operator=(const Number&);
        Number operator=(double value);
    private:
        double value_;
    };
    extern const Number ONE;
    extern const Number ZERO;
}