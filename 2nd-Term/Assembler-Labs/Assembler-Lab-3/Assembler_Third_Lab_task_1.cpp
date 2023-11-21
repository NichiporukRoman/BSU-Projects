#include <iostream>

int main() {
    unsigned __int32 a(2), a_in_power_of_12(0), a_in_power_of_8(0), x(0), result(0), result_c(0);
    result_c = pow(a, 12) + pow(a, 8) + a;
    __asm {
        mov ecx, 12
        mov x, 1
        Start_of_count_a_in_power_of_12:
        cmp ecx, 0
            jz End_of_count_a_in_power_of_12
            sub ecx, 1
            mov eax, x
            mul a
            mov x, eax
            jmp Start_of_count_a_in_power_of_12
            End_of_count_a_in_power_of_12 :
        mov eax, x
            mov a_in_power_of_12, eax

            mov ecx, 8
            mov x, 1
            Start_of_count_a_in_power_of_8 :
            cmp ecx, 0
            jz End_of_count_a_in_power_of_8
            sub ecx, 1
            mov eax, x
            mul a
            mov x, eax
            jmp Start_of_count_a_in_power_of_8
            End_of_count_a_in_power_of_8 :
        mov eax, x
            mov a_in_power_of_8, eax

            mov eax, result
            add eax, a
            add eax, a_in_power_of_8
            add eax, a_in_power_of_12
            mov result, eax
    }
    std::cout << "asm: " << result << std::endl;
    std::cout << "c++: " << result_c << std::endl;
}