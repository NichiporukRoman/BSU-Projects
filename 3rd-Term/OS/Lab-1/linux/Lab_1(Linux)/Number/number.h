#ifndef NUMBER_H
#define NUMBER_H

namespace Number {

    class Number {
    public:
        Number(double value);

        Number() = default;

        ~Number() = default;

        Number operator+(const Number &) const;

        Number operator-(const Number &) const;

        Number operator/(const Number &) const;

        Number operator*(const Number &) const;

        double GetNumber() const;

        Number operator=(const Number &) const;

        Number operator=(double value) const;

    private:
        double value_;
    };
}

#endif //NUMBER_H