#include "Fraction.h"

int main()
{
    Fraction a(1, 2);
    Fraction b(6, 110);
    a.Divide(b);
    a.Divide(1);
    a.Print();
}