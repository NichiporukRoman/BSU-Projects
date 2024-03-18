import math

import utility


def calculate_using_trapezoidal_formula(a, b, n):
    h = (b - a) / n
    integral = 0.5 * (utility.f1(a) + utility.f1(b))
    for i in range(1, n):
        integral += utility.f1(a + i * h)
    return h * integral


def calculate_using_hada(a, b, n):
    sum_ = 0.0
    for i in range(n + 1):
        sum_ += utility.f2_numerator(math.cos(math.pi * (2 * i + 1) / 2 / (n + 1)))
    return sum_ * math.pi / (n + 1)


def calculate_using_rectangle_formula(a, b, N):
    h = (b - a) / N
    sum_ = 0.0
    for i in range(N):
        sum_ += utility.f2(a + i * h + h / 2.0)
    return h * sum_
