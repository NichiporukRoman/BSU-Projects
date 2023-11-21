#include <cmath>

#include "utils.h"

int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return a;
}