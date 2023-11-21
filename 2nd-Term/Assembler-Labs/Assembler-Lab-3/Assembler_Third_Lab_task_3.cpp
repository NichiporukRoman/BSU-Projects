#include <iostream>

int main() {
    unsigned __int32 operand1(0), operand2(1), operand_next(0), number(0), operand1_c(0), operand2_c(1);
    const unsigned __int32  n(47);
    unsigned __int32 Fibonacci_sequence_asm[n];
    unsigned __int32 Fibonacci_sequence_c[n];
    for (int i = 0; i < n; i++) {
        Fibonacci_sequence_asm[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        Fibonacci_sequence_c[i] = 0;
    }
    for (int i = 1; i < n; i++) {
        Fibonacci_sequence_c[i] = number;
        number = operand1_c + operand2_c;
        operand1_c = operand2_c;
        operand2_c = number;

    }

    __asm {
        mov eax, 0
        mov ecx, 0
        mov ebx, 0
        mov edx, 0
        add ecx, n
        Start_of_cicle :
        mov edx, operand1
            add eax, operand2

            add eax, edx
            jc End_of_cicle
            mov Fibonacci_sequence_asm[ebx], edx
            add ebx, 4
            mov edx, operand2
            mov operand1, edx
            mov operand2, eax
            mov eax, 0
            mov edx, 0
            sub ecx, 1
            cmp ecx, 0
            jz The_real_end_of_cicle
            jmp Start_of_cicle
            End_of_cicle :
        mov Fibonacci_sequence_asm[ebx], edx
            The_real_end_of_cicle :
    }
    std::cout << "asm | c++" << std::endl;
    for (int i = 0; i < n; i++) {
        if (Fibonacci_sequence_asm[i + 1] != 0)
        {
            std::cout << Fibonacci_sequence_asm[i] << " | ";
            std::cout << Fibonacci_sequence_asm[i];
            std::cout << std::endl;
        }
        else {
            i = n - 1;
        }
    }
    std::cout << std::endl;
    return 0;
}