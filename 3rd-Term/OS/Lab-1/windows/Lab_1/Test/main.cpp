#include <iostream>
#include "/home/roman/CLionProjects/Lab_1/Dll/vector.h"

int main()
{
    vector::Vector i(Number::Number(1), Number::Number(3));
    std::cout << i.GetAngle() << "\n" << i.GetRadius() << "\n";
    vector::Vector j(Number::Number(45), Number::Number(3));
    vector::Vector g = i + j;
    std::cout << g.GetAngle() << "\n" << g.GetRadius() << "\n";

}
