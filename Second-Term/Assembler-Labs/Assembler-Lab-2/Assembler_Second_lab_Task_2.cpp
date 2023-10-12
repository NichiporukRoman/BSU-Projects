#include <iostream>

int main() {

    unsigned __int32 number(1), number_in_power_of_2(0), number_of_decades(0), ten_in_power_of_number_of_decades(0);
    unsigned __int32 ten(10), result(0), x(0);

    __asm{

    mov EAX, number
    mul number
    mov number_in_power_of_2, EAX

    mov EAX, number
    mov EBX, 0

    Start_of_first_cicle:
    CMP EAX, 0
    jz Out_of_first_cicle
    div ten
    mov x, EAX
    add EBX, 1
    mov EDX, 0
    mov EAX, x
    jmp Start_of_first_cicle
    Out_of_first_cicle:

    mov number_of_decades, EBX
    mov EBX, number_of_decades
    mov EAX, 1


    Start_of_second_cicle:
    CMP EBX, 0
    jz Out_of_second_cicle
    sub EBX, 1
    mul ten
    jmp Start_of_second_cicle
    Out_of_second_cicle:

    mov ten_in_power_of_number_of_decades, EAX
    mov EBX, ten_in_power_of_number_of_decades
    mov EAX, number_in_power_of_2

    div EBX
    mov EBX, number

    Start_of_third_cicle:
    CMP EDX, EBX
    jz Automorphic
    jmp Not_Automorphic
    Automorphic:
    mov EAX, 1
    jmp End_of_program
    Not_Automorphic:
    mov EAX, 0
    jmp End_of_program
    End_of_program:
    mov result, EAX
    }
    if(result == 1){
        std::cout << "Number is Automorphic" << std::endl;
    }
    else{
        std::cout << "Number is not Automorphic" << std::endl;
    }
    return 0;
