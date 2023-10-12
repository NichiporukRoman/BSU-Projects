#include <iostream>
#include <iomanip>
#include <cmath>
int main() {
    double result(0), result_c(0), exp(0), exp_in_power(1);
    double X(2);
    __int64 result_max(0), result_max_c(0);
    __int32 number(9), counter(0), k(0);
    result_c = log(X);
    result_max_c = round(result_c*pow(10, number));
    Start_if:
    exp_in_power=1;
    result_max= round(result*pow(10,number));
    if(result_max == result_max_c){
        std::cout << counter << "   " << std::setprecision(number) << result << "    " << std::setprecision(number) <<result_c;
        return 0;
    }
    else{
        __asm{
        finit
        xor ecx, ecx
        mov ecx, counter
        inc ecx
        xor eax, eax
        add eax, ecx
        mov k, eax
        xor eax, eax
        xor ebx, ebx
        xor edx, edx

        fld exp_in_power
        fild k
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
