#include <iostream>

int main()
{
    double a, b, c;
    double down(-10), upper(10), middle;
    double fdown(0), fupper(0), fmiddle(0), answer(0);
    double zero(0), two(2), eleven(11), ten(10);
    double accuracy(0), root(0), checker(0), exp(1);
    int there_is_root(1), accuracy_int(0);

    std::cout << "Enter a:";
    std::cin >> a;
    std::cout << std::endl;
    std::cout << "Enter b:";
    std::cin >> b;
    std::cout << std::endl;
    std::cout << "Enter c:";
    std::cin >> c;
    std::cout << std::endl;
    std::cout << "Enter your accuracy:";
    std::cin >> accuracy_int;
    std::cout << std::endl;

    __asm
    {
        finit
        xor ecx, ecx
Accuracy_counter:
        cmp ecx, accuracy_int
        je out_
        inc ecx
        fld exp
        fdiv ten
        fstp exp
        jmp Accuracy_counter
out_:
        fld exp
        fstp accuracy
Global_start:
Count_start:
        finit
        fld down
        fmul down
        fmul a
        fld down
        fadd eleven
        fstp exp
        fld b
        fdiv exp
        fstp exp
        fadd exp
        fadd c
        fstp fdown

        fld upper
        fmul upper
        fmul a
        fld upper
        fadd eleven
        fstp exp
        fld b
        fdiv exp
        fstp exp
        fadd exp
        fadd c
        fstp fupper
        fld fupper
        fcom zero
        fstsw ax
        sahf
        je root_upper

        fld down
        fadd upper
        fdiv two
        fstp middle
        fld middle
        fmul middle
        fmul a
        fld middle
        fadd eleven
        fstp exp
        fld b
        fdiv exp
        fstp exp
        fadd exp
        fadd c
        fstp fmiddle

            fld fdown
            fcom zero
            fstsw ax
            sahf
            je root_down

            fld fupper
            fcom zero
            fstsw ax
            sahf
            je root_upper

            fld fmiddle
            fcom zero
            fstsw ax
            sahf
            je root_middle
Count_end:

            fld fmiddle
            fmul fdown
            fcom zero
            fstsw ax
            sahf
            jc first_variant
            jmp second_variant

first_variant:
            fld middle
            fstp upper
            jmp accuracy_checker
second_variant:
            fld middle
            fstp down
            jmp accuracy_checker

accuracy_checker:
    fld upper
    fsub down
    fstp checker
    fld checker
    fcom accuracy
    fstsw ax
    sahf
    jc root_found
    jmp Global_start

root_middle:
        fld middle
        fstp root
        jmp Global_end
root_down:
        fld down
        fstp root
        jmp Global_end
root_upper:
        fld upper
        fstp root
        jmp Global_end
root_found:
        fld down
        fadd upper
        fdiv two
        fstp root

        fld root
        fmul root
        fmul a
        fld root
        fadd eleven
        fstp exp
        fld b
        fdiv exp
        fstp exp
        fadd exp
        fadd c
        fstp answer

        fld answer
        fcom accuracy
        fstsw ax
        sahf
        jc Global_end
no_root_found:
        dec there_is_root
Global_end:
    }
    if (there_is_root == 1)
    {
        std::cout << "There is a root. Answer:" << root;
    }
    else
    {
        std::cout << "There is no root";
        exit (0);
    }
    return 0;
}