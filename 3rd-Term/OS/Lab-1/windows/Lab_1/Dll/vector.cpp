#ifndef UNTITLED2_LIBRARY_H
#define UNTITLED2_LIBRARY_H

#include "vector.h"
#include <cmath>
const double PI = acos(-1.0);
namespace vector {


    Vector::Vector(Number x, Number y) : x_(x), y_(y) {}

    double Vector::GetAngle(){
        double angle = atan(y_.GetNumber() / x_.GetNumber());
        return angle;
    }

    double Vector::GetRadius(){
        return sqrt(x_.GetNumber() * x_.GetNumber() + y_.GetNumber() * y_.GetNumber());
    }

    Number::Number Vector::GetX(){
        return x_;
    }

    Number::Number Vector::GetY(){
        return y_;
    }
    Vector Vector::operator+(const Vector& other){
        return Vector(x_ + other.x_, y_ + other.y_);
    }

    const Vector ZERO_ZERO = Vector(Number::ZERO, Number::ZERO);
    const Vector ONE_ONE = Vector(Number::ONE, Number::ONE);
}
#endif //UNTITLED2_LIBRARY_H