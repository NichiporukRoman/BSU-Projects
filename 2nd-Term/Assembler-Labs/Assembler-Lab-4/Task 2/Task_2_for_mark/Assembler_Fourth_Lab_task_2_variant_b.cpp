        #define _USE_MATH_DEFINES
        #include <iostream>
        #include <iomanip>
        #include <cmath>



        double result(0), result_c, pi(M_PI), expr(0), down_exp(0),_10(10), x(1);
        __int32 accuracy(6), accuracy_num(1), result_for_compare(0), result_c_for_compare;
        unsigned __int32 k(0);

        int main() {
            result_c = pow(pi, 2)/8;
            result_c_for_compare = std::round(result_c* pow(10, accuracy));
            __asm{
                xor ecx, ecx

        accuracy_counter:
                cmp ecx, accuracy
                je start
                inc ecx
                mov eax, accuracy_num
                mov ebx, 10
                mul ebx
                mov accuracy_num, eax
                jmp accuracy_counter

        start:
                xor ecx, ecx


        Tailor_Series:
                xor edx, edx
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

                add edx, ecx
                mov k, edx

                fild k
                fild k
                fadd
                fld1
                fsub
                fst down_exp
                finit
                fld down_exp
                fld down_exp
                fmul
                fst down_exp
                finit


                fld1
                fld down_exp
                fdiv
                fst expr
                finit

                fld result
                fld expr
                fadd
                fst result
                finit
        jmp Tailor_Series


        End_:
                mov k, ecx
            }
            std::cout <<std::setprecision(accuracy+1) << result << std::endl << k;
            return 0;
        }
