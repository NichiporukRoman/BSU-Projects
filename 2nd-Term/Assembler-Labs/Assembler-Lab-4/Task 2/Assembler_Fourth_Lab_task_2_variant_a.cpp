#include <iostream>
#include <iomanip>
int main() {
__int64 result_max, result_c_max;
__int32 k(0), number(5),counter(0);
double exp(0), result(0), k_2(0), pi(3.14159265359);
double result_c = (pi*pi)/12;
Start_if:
result_max=result*pow(10,number+1) ;
result_c_max = result_c*pow(10,number+1);
    if(result_max == result_c_max) {
        std::cout << counter << "    " << std::setprecision(number)<< result << "     " << std::setprecision(number)<< result_c;
        return 0;
    }

    else{
        __asm{


        xor eax, eax
        xor ebx, ebx
        xor edx, edx
        xor ecx, ecx
        mov ecx, counter

        start:

        finit
        inc ecx

        add edx, ecx
        mov k, edx
        xor edx, edx

        fild k
        fild k
        fmul
        fst k_2

        fld1
        fld k_2
        fdiv
        fst exp

        add eax, ecx
        mov ebx, 2
        div ebx
        xor eax, eax
        xor ebx, ebx
        cmp edx, 1
        je pozitive
        jmp negativ

        negativ:
        fld result
        fld exp
        fsub
        fst result
        xor edx, edx
        jmp End_
        pozitive:
        fld result
        fld exp
        fadd
        fst result
        xor edx, edx
        jmp End_
        End_:
            mov counter, ecx
        }
    }
    goto Start_if;
}