#include <iostream>

int main() {
    __int32 Numerator(-145), Denominator(5), Numerator_c(0), Denominator_c(0), Numerator_abs(0), x(0), result(0), result_c(0);
    Numerator_abs = abs(Numerator);
    Numerator_c = Numerator;
    Denominator_c = Denominator;

    for (int i = Denominator; i > 0; i--) {
        if (Numerator % i == 0 && Denominator % i == 0) {
            result_c = i;
            break;
        }
    }

    __asm {
        xor eax, eax
        add eax, Numerator
        js minus
        jmp all_ok
        minus :
        neg eax
            mov Numerator_abs, eax
            jmp out_
            mov edx, 1
            mov x, edx
            all_ok :
        mov Numerator_abs, eax
            mov edx, 0
            jmp out_
            mov x, edx
            out_ :
        mov eax, Numerator_abs
            mov ebx, Denominator
            begin :
        cmp eax, ebx
            je end_
            jg greater
            sub ebx, eax
            jmp begin
            greater :
        sub eax, ebx
            jmp begin
            end_ :
        mov result, eax
            xor edx, edx
            mov eax, Numerator_abs
            idiv result
            xor edx, edx
            mov x, eax

            xor eax, eax
            add eax, Numerator
            js minus1
            jmp all_ok1
            minus1 :
        mov eax, x
            neg eax
            mov Numerator, eax
            jmp out__
            all_ok1 :
        mov eax, x
            mov Numerator, eax
            jmp out__
            out__ :
        mov Numerator, eax
            mov eax, Denominator
            idiv result
            mov Denominator, eax


    }
    std::cout << "asm: " << Numerator << " / " << Denominator << std::endl;
    std::cout << "c++: " << Numerator_c / result_c << " / " << Denominator_c / result_c << std::endl;

    return 0;
}