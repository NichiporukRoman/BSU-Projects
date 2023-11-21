#include "gtest/gtest.h"
#include "Calculator.h.h"

Stack<int> stack;
Calc* ex = new Calc();
std::string c;

TEST(Simple, Sum){
c = "127+5";
ASSERT_EQ(ex->calculate(c), 132);
}

TEST(Simple, InfMin){
c = "-49755";
ASSERT_EQ(ex->calculate(c), -49755);
}

TEST(Simple, Min){
c = "7-5";
ASSERT_EQ(ex->calculate(c), 2);
}

TEST(Simple, Division){
c = "123/43";
ASSERT_EQ(ex->calculate(c), (double) 123/43);
}

TEST(Simple, Multiplication){
c = "5*120";
ASSERT_EQ(ex->calculate(c), 600);
}

TEST(SimpleDouble, Sum){
c = "55.244242+56.34565";
ASSERT_EQ(ex->calculate(c), 111.589892);
}

TEST(SimpleDouble, Min){
c = "54.4307-985.955435";
ASSERT_EQ(ex->calculate(c), (double) 54.4307-985.955435);
}

TEST(SimpleDouble, Div){
c = "5707/45.5";
ASSERT_EQ(ex->calculate(c), (double) 5707/45.5);
}

TEST(SimpleDouble, Mult){
c = "7.7*89.6";
ASSERT_EQ(ex->calculate(c),(double) 7.7*89.6);
}

TEST(Bigger, int) {
c = "7*34-(8+9)";
ASSERT_EQ(ex->calculate(c), 221);
}
TEST(Bigger, Double){
c = "57*45-5*(25+72.34)";
ASSERT_EQ(ex->calculate(c), 2078.3);
}

TEST(Bigger, DoubleMin){
c = "7*34--(8+9.1)";
ASSERT_EQ(ex->calculate(c), 255.1);
}

TEST(First, Brakets){
c = "(58*45-70)*5";
ASSERT_EQ(ex->calculate(c), 12700);
}

TEST(First, Minus){
c = "-(7*34--(8+9.1))";
ASSERT_EQ(ex->calculate(c), -255.1);
}

TEST(Stack, Push){
stack << 4;
stack << 13;
ASSERT_EQ(13, stack.Top());
}

TEST(Stack, ElementByNum){
stack.Push(7);
stack.Push(56);
stack.Push(54);
stack.Push(3);
ASSERT_EQ(stack[3], 54);
}

