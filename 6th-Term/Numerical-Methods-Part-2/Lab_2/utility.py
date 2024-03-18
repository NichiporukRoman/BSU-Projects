import math
import formulas


def f1(x):
    return math.sinh(2*x)*math.cosh(2*x)


def f2_numerator(x):
    return math.pow(math.sin(x), 2)


def f2(x):
    return f2_numerator(x) / math.sqrt(1 - math.pow(x, 2))


def calculate_error_using_runge_rule(i1, i2, p):
    return abs(i1 - i2) / (pow(2, p) - 1)


def run_task1():
    exact_integral = 555378.4940026
    a = 1
    b = 4
    eps = 1e-7
    p = 2
    N = 1
    error = 1
    while error > eps:
        i1 = formulas.calculate_using_trapezoidal_formula(a, b, N)
        N *= 2
        i2 = formulas.calculate_using_trapezoidal_formula(a, b, N)
        error = calculate_error_using_runge_rule(i1, i2, p)
    step_size = (b - a) / N
    print("Approximate value of the integral:", formulas.calculate_using_trapezoidal_formula(a, b, N))
    print("Exact value of the integral:", exact_integral)
    print("Step:", step_size)


def run_task2():
    a = -1.0
    b = 1.0
    print("Number of nodes\tHADA\tformula of average rectangles")
    for n in range(1, 21):
        nystrom_result = formulas.calculate_using_hada(a, b, n)
        rectangle_result = formulas.calculate_using_rectangle_formula(a, b, n)
        print(n, "\t\t\t", nystrom_result, "\t", rectangle_result)
