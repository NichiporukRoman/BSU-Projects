import utility


def get_spline(x, f, d2f):
    n = len(x)
    h = x[1] - x[0]
    vector = [0] * n
    ac = [0] * (n - 1)
    cc = [0] * n
    bc = [0] * (n - 1)
    matrix = [[0] * n for _ in range(n)]
    cc[0] = 1
    cc[n - 1] = 1
    vector[0] = d2f(x[0])
    vector[n - 1] = d2f(x[n - 1])
    for i in range(1, n - 1):
        vector[i] = 6 * ((f(x[i + 1]) - f(x[i])) / h - (f(x[i]) - f(x[i - 1])) / h)
        ac[i - 1] = h
        cc[i] = 2 * (h + h)
        bc[i] = h
    c = utility.solve_system_using_run_through_method(bc, cc, ac, vector)
    functions = []
    for i in range(1, n):
        temp = i
        functions.append(lambda point, f=f, c=c, x=x, h=h, temp=temp: \
            f(x[temp]) + ((f(x[temp]) - f(x[temp - 1])) / h + c[temp] * h / 3 + c[temp - 1] * h / 6) * (point - x[temp]) + \
            c[temp] / 2 * (point - x[temp]) * (point - x[temp]) + \
            (c[temp] - c[temp - 1]) / (6 * h) * (point - x[temp]) * (point - x[temp]) * (point - x[temp]))

    return functions
