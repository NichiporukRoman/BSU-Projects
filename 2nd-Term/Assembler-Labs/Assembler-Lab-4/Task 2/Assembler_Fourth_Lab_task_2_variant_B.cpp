#include <iostream>
#include <iomanip>
int main() {
    __int64 result_max, result_c_max;
    __int32 k(0), number(1),counter(0);
    double exp(0), result(0), k_2(0), pi(3.14159265359);
    double result_c = (pi*pi)/8;
    Start_if:
    result_max=result*pow(10,number) ;
    result_c_max = result_c*pow(10,number);
    if(result_max == result_c_max) {
        std::cout << counter << "    " << std::setprecision(number+1)<< result << "     " << std::setprecision(number+1)<< result_c;
        return 0;
    }

    else{
        __asm{


        xor eax, eax
        xor ebx, ebx
        xor edx, edx
        xor ecx, ecx
        mov ecx, counter

        finit
        inc ecx

        add edx, ecx
        mov k, edx
        xor edx, edx

        fild k
        fild k
        fadd
        fst k_2

        fld k_2
        fld1
        fsub
        fst exp

        fld exp
        fld exp
        fmul
        fst exp

        fld1
        fld exp
        fdiv
        fst exp


        fld result
        fld exp
        fadd
        fst result
        mov counter, ecx
        }
    }
    goto Start_if;
}