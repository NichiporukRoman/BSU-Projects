#include "gtest/gtest.h"
#include "Fraction.h"

TEST(Sum, Sum1) {
    Fraction fraction1(1, 2);
    Fraction fraction2(3, 4);
    fraction1.Sum(fraction2);
    EXPECT_EQ(fraction1.Numerator(), 5);
    EXPECT_EQ(fraction1.Denominator(), 4);
}

TEST(Sum, Sum2) {
    Fraction fraction1(1, 2);
    int a = 1;
    fraction1.Sum(a);
    EXPECT_EQ(fraction1.Numerator(), 3);
    EXPECT_EQ(fraction1.Denominator(), 2);
}

TEST(Sum, Sum3) {
    Fraction fraction1(1, 2);
    Fraction fraction2(-3, 4);
    fraction1.Sum(fraction2);
    EXPECT_EQ(fraction1.Numerator(), -1);
    EXPECT_EQ(fraction1.Denominator(), 4);
}

TEST(Sum, Sum4) {
    Fraction fraction1(1, 5);
    int a = -7;
    fraction1.Sum(a);
    EXPECT_EQ(fraction1.Numerator(), -34);
    EXPECT_EQ(fraction1.Denominator(), 5);
}

TEST(Normalize, Normalize) {
    Fraction fraction1(12, 18);
    fraction1.Normalize();
    EXPECT_EQ(fraction1.Numerator(), 2);
    EXPECT_EQ(fraction1.Denominator(), 3);
}

TEST(Multiply, Multiply1) {
    Fraction fraction1(1, 2);
    Fraction fraction2(3, 4);
    fraction1.Multiply(fraction2);
    EXPECT_EQ(fraction1.Numerator(), 3);
    EXPECT_EQ(fraction1.Denominator(), 8);
}

TEST(Multiply, Multiply2) {
    Fraction fraction1(1, 2);
    int b = 7;
    fraction1.Multiply(b);
    EXPECT_EQ(fraction1.Numerator(), 7);
    EXPECT_EQ(fraction1.Denominator(), 2);

}

TEST(Multiply, Multiply3) {
    Fraction fraction1(5, 4);
    int b = -3;
    fraction1.Multiply(b);
    EXPECT_EQ(fraction1.Numerator(), -15);
    EXPECT_EQ(fraction1.Denominator(), 4);
}
TEST(Divine, Divine1) {
    Fraction fraction1(1, 2);
    int b = 7;
    fraction1.Divide(b);
    EXPECT_EQ(fraction1.Numerator(), 1);
    EXPECT_EQ(fraction1.Denominator(), 14);

}

TEST(Divine, Divine2) {
    Fraction fraction1(1, 2);
    Fraction fraction2(7, 8);
    fraction1.Divide(fraction2);
    EXPECT_EQ(fraction1.Numerator(), 4);
    EXPECT_EQ(fraction1.Denominator(), 7);

}

TEST(Divine, Divine3) {
    Fraction fraction1(-2, 3);
    Fraction fraction2(7, 8);
    fraction1.Divide(fraction2);
    EXPECT_EQ(fraction1.Numerator(), -16);
    EXPECT_EQ(fraction1.Denominator(), 21);

}

TEST(Divine, Divine4) {
    Fraction fraction1(3, 2);
    int b = -14;
    fraction1.Divide(b);
    EXPECT_EQ(fraction1.Numerator(), -3);
    EXPECT_EQ(fraction1.Denominator(), 28);

}