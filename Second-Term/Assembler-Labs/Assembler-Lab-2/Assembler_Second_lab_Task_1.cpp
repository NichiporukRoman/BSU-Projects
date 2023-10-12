#include <iostream>
#include <cmath>

int main() {
unsigned __int32 x(2), x_in_2(0), x_in_3(0), x_in_5(0);
unsigned __int32 Primer_1_Result(1), Primer_2_Result(1),Primer_3_Result(1);
unsigned __int32 Primer_1_Result_C(1), Primer_2_Result_C(1),Primer_3_Result_C(1);
   __asm{

       mov EBX, 2
       mov EAX, 1

   Start_of_2:
       CMP EBX, 0
       jz End_of_2
       sub EBX, 1
       mul x
       jmp Start_of_2
   End_of_2:
       mov x_in_2, EAX


       mov EBX, 3
       mov EAX, 1

   Start_of_3:
       CMP EBX, 0
       jz End_of_3
       sub EBX, 1
       mul x
       jmp Start_of_3
   End_of_3:
       mov x_in_3, EAX


       mov EBX, 5
       mov EAX, 1

   Start_of_5:
       CMP EBX, 0
       jz End_of_5
       sub EBX, 1
       mul x
       jmp Start_of_5
   End_of_5:
       mov x_in_5, EAX

Primer_1:
       mov EBX, 2
       mov EAX, x_in_2
       sub EAX, 4
       mul EBX
       add EAX, x_in_5
       add EAX, x
       div x_in_3
       mov Primer_1_Result, EAX

Primer_2:
       mov EAX, x_in_2
       mov EBX, 4
       mul EBX
       sub EAX, 1
       mov EBX, x
       add EBX, 3
       mul EBX
       mov EBX, EAX
       mov EAX, 2
       mul x
       mov Primer_2_Result, EAX
       mov EAX, EBX
       mov EBX, Primer_2_Result
       div EBX
       mov Primer_2_Result, EAX

Primer_3:
       mov EAX, x_in_2
       mov EBX, 16
       mul EBX
       sub EAX, 1
       mov EBX, 4
       div EBX
       mov Primer_3_Result, EAX

   }
   std::cout << "Assembler Primer 1 Result = " << Primer_1_Result << " | ";
   Primer_1_Result_C = (pow(x,5) + 2 * (pow(x, 2) - 4) + x)/(pow(x, 3));
   std::cout << "C++ Primer Result = " << Primer_1_Result_C << "   ";
   if (Primer_1_Result == Primer_1_Result_C){std::cout << "They are same";}
   std::cout << std::endl;

   std::cout << "Assembler Primer 2 Result = " << Primer_2_Result << " | ";
   Primer_2_Result_C = (2*x - 1)*(2*x + 1)*(x + 3)/(2 * x);
   std::cout << "C++ Primer 2 Result = " << Primer_2_Result_C << "   ";
   if (Primer_2_Result == Primer_2_Result_C){std::cout << "They are same";}
   std::cout << std::endl;

   std::cout << "Assembler Primer 3 Result = " << Primer_3_Result << " | ";
   Primer_3_Result_C = (4*x-1)*(4*x+1)/4;
   std::cout << "C++ Primer 3 Result = " << Primer_3_Result_C << "   ";
   if (Primer_3_Result == Primer_3_Result_C){std::cout << "They are same";}
   std::cout << std::endl;
    return 0;
}
