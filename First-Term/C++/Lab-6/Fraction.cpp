#include <iostream>

#include "utils.h"

#include "Fraction.h"

using namespace std;

Fraction::Fraction( int p) : numerator (p), denominator (1){}
Fraction::Fraction(int numerator, int denominator){
    if (denominator == 0) {
        cout << "division by zero" << endl;
        exit(1);
    }
    this->numerator =  numerator;
    this->denominator = denominator;
    Normalize();
}

Fraction::Fraction(const Fraction& copy){
    this->numerator = copy.numerator;
    this->denominator = copy.denominator;
}

int Fraction::Numerator() const {
    return numerator;
}

int Fraction::Denominator() const {
    return denominator;
}

void Fraction::Sum(int term){
    numerator = numerator + denominator * term;
}

void Fraction::Sum(Fraction second) {
    int new_numerator = numerator * second.denominator + second.numerator * denominator;
    int new_denominator = denominator * second.denominator;
    numerator = new_numerator;
    denominator = new_denominator;
    Normalize();
}

void Fraction::Multiply(Fraction factor) {
    this->numerator *= factor.numerator;
    this->denominator *= factor.denominator;
    Normalize();
}

void Fraction::Divide(int divider) {
    if (divider == 0) {
        cout << "division by zero" << endl;
        exit(1);
    }
    denominator *= divider;
    Normalize();
}

void Fraction::Divide(Fraction second) {
    if (second.numerator == 0) {
        cout << "division by zero" << endl;
        exit(1);
    }
    numerator *= second.denominator;
    denominator *= second.numerator;
    Normalize();
}

void Fraction::Normalize(){
    int divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

void Fraction::Print() const{
    if (numerator < 0) {
        cout << "-";
    }
    cout << numerator;
    if (denominator != 1) {
        cout << "/" << denominator;
    }
}