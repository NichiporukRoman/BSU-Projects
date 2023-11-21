#include <iostream>
#include <iomanip>

double result(0), result_c, x(2), expr(0), upper_exp(1);
__int32 accuracy(7), accuracy_num(1), result_for_compare(0), result_c_for_compare;
__int32 k(0);

int main() {
    result_c = log(x);
    result_c_for_compare = std::round(result_c * pow(10, accuracy));
    __asm {
    xor ecx, ecx
    accuracy_counter :
    cmp ecx, accuracy
    je start
    inc ecx
    mov eax, accuracy_num
    mov ebx, 10
    mul ebx
    mov accuracy_num, eax
    jmp accuracy_counter

    start :
    xor ecx, ecx
    fld x
    fld1
    fsub
    fst x
    finit
    mov ebx, 2


    Tailor_Series :
    fld result
    fild accuracy_num
    fmul
    frndint
    fist result_for_compare
    finit
    mov eax, result_for_compare
    cmp eax, result_c_for_compare
    je End_
    inc ecx

    xor edx, edx
    add edx, ecx
    mov k, edx

    fld upper_exp
    fld x
    fmul
    fst upper_exp
    finit

    fld upper_exp
    fild k
    fdiv
    fst expr
    finit

    xor eax, eax
    xor edx, edx
    add eax, ecx
    div ebx
    cmp edx, 1
    je pozitive
    jmp negative

    pozitive :
    fld result
    fld expr
    fadd
    fst result
    finit
    jmp Tailor_Series

    negative :
    fld result
    fld expr
    fsub
    fst result
    finit
    jmp Tailor_Series

    End_ :
    mov k, ecx
    }
    std::cout << std::setprecision(accuracy) << result << std::endl << "Number of Interations: " << k;
    return 0;
}
