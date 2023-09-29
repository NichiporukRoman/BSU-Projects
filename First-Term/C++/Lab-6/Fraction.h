#ifndef UNTITLED_FRACTION_H
#define UNTITLED_FRACTION_H

class Fraction {
public:
    Fraction( int p);

    Fraction(int numerator, int denominator);

    Fraction(const Fraction &copy);

    int Numerator() const;

    int Denominator() const;

    void Sum(int term);

    void Sum(Fraction second);

    void Multiply(Fraction factor);

    void Divide(int divider);

    void Divide(Fraction second);

    void Normalize();

    void Print() const;

private:
    int numerator;
    int denominator;
};


#endif //UNTITLED_FRACTION_H
