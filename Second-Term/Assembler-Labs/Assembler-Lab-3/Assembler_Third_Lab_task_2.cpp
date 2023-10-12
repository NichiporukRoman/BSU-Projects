#include <iostream>
#include <bitset>
// z = ax + by
int main() {
unsigned const __int32 z(50);
unsigned __int32 a(2), b(3), z_a(0), z_b(0), counter_x(0), answers(0);
unsigned __int32 x(0), y(0), a_mul_x(0), b_mul_y(0), result(0), counter(0);
    unsigned __int32 arr_x[z];
    unsigned __int32 arr_y[z];
    for (int i = 0; i < z; i++){
        arr_x[i] = 0;
        arr_y[i] = 0;
    }


__asm{
        xor ebx, ebx
Start:
        xor edx, edx
        mov eax, z
        div a
        mov z_a, eax
        xor edx, edx
        mov eax, z
        div b
        mov z_b, eax
        xor edx, edx

Start_for_x:
            xor eax, eax
            mov ecx, counter_x
            cmp ecx, z_a
            je End_
            add eax, ecx
            mov x, eax
            inc ecx
            mov counter_x, ecx
            xor ecx, ecx

Start_for_y:
            xor eax, eax
            cmp ecx, z_b
            je Start_for_x
            inc ecx
            add eax, ecx
            mov y, eax

            mov eax, x
            mul a
            xor edx, edx
            mov a_mul_x, eax
            mov eax, y
            mul b
            xor edx, edx
            mov b_mul_y, eax

            mov eax, a_mul_x
            add eax, b_mul_y

            cmp eax, z
            je answer
            jg Start_for_x
            jmp Start_for_y

answer:
            mov edx, answers
            inc edx
            mov answers, edx
            xor edx, edx

            mov eax, x
            mov arr_x[ebx*4], eax
            mov eax, y
            mov arr_y[ebx*4], eax
            xor eax, eax
            inc ebx
            jmp Start_for_x

End_:

    }

    for(int i = 0; i < z_a; i++){
        x = i;
        a_mul_x = a*x;
        result = z - a_mul_x;
        b_mul_y = result/b;
        b_mul_y = b_mul_y*b;
        if(b_mul_y == result){

            std::cout << "c++:  " << x << " | " << b_mul_y/b << "   asm: " << arr_x[counter] << " | " << arr_y[counter] << std::endl;
            counter++;
        }


    }
    std::cout <<"c++: " << counter << "   asm: " << answers << std::endl;
}
