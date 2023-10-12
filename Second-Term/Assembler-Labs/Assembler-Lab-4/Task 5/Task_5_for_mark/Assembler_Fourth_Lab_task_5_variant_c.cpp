#include <iostream>
//f(x) = a^x
double a(10), result(1), x(0), mantis(0);
__int32 power(0);
int main() {
    std::cout << "Put yours X:";
    std::cin >> x;
    __asm {
        xor ecx, ecx
        fld a
        fld1
        fsub
        fst a
        finit

        fld x
        fld a
        FYL2XP1
        fst x
        finit

        fld x
        frndint
        fist power
        finit

        fld x
        fild power
        fsub
        fst mantis
        finit

        fild power
        fld1
        fscale
        fst result
        finit

        fld mantis
        F2XM1
        fld1
        fadd
        fld result
        fmul
        fst result
        finit
    }
    std::cout << "f(x)=" << result;
    return 0;
}
