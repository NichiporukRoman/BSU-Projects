#include <iostream>
#include <bitset>
int main() {
    const int n = 4;
    unsigned __int32 counter(0), helper(0), helper2(0);
    unsigned __int32 Array[n]={0b00010000000000010000000000000000,
                      0b00100000000000001000000000000000,
                      0b01000000000000000000001000000000,
                      0b10000000000000000000000010000000};
//    std::cout << std::endl;
//    for (int i = 0; i < n; i++) {
//        std::cin >> Array[i];
//    }
    __asm {
    xor ecx, ecx
    mov ecx, n
    mov counter, ecx

    Start_of_prog :
    mov ecx, counter
    xor ebx, ebx
    dec ebx
    cmp ecx, 0
    je End_of_prog

    dec ecx
    mov counter, ecx
    xor ecx, ecx
    mov ecx, n

    running :
    cmp ecx, 1
    je Start_of_prog
    xor eax, eax
    xor edx, edx
    inc ebx
    dec ecx
    add eax, Array[4 * ebx]
    inc ebx
    add edx, Array[4 * ebx]
    dec ebx

    shl eax, 5
    shr eax, 5
    shr eax, 7
    add helper, eax
    shl eax, 26
    shr eax, 26
    add helper2, eax
    mov eax, helper
    shr eax, 8
    shl eax, 6
    add eax, helper2
    finit
    fldz
    fist helper
    fldz
    fist helper2

    shl edx, 5
    shr edx, 5
    shr edx, 7
    add helper, edx
    shl edx, 26
    shr edx, 26
    add helper2, edx
    mov edx, helper
    shr edx, 8
    shl edx, 6
    add edx, helper2
    finit
    fldz
    fist helper
    fldz
    fist helper2

    cmp eax, edx
    jng running

    mov eax, Array[4 * ebx]
    inc ebx
    mov edx, Array[4 * ebx]
    dec ebx
    mov Array[4 * ebx], edx
    inc ebx
    mov Array[4 * ebx], eax
    dec ebx

    jmp running
    End_of_prog :

    }
    for (int i = 0; i < n; i++) {
        std::cout << std::bitset<32>(Array[i]) << std::endl;
    }
    return 0;
}