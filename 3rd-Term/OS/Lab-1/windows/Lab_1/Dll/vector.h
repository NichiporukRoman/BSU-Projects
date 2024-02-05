#ifndef DLL_VECTOR_H
#define DLL_VECTOR_H

#include "/home/roman/CLionProjects/Lab_1/NumLib/num.h"

namespace vector {

    class Vector {
    public:
        typedef Number::Number Number;
        Vector(Number x, Number y);
        Vector() = default;
        ~Vector() = default;

        double GetAngle();
        double GetRadius();
        Number GetX();
        Number GetY();
        Vector operator+(const Vector& other);
    private:
        Number x_;
        Number y_;
    };

    extern const Vector ONE_ONE;
    extern const Vector ZERO_ZERO;

}

#endif //DLL_VECTOR_H
