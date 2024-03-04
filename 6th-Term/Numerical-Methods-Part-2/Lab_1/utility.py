import math
import os
import subprocess

import newton_interpolation
import spline

a = -3
b = 3
degrees = [2, 4, 8, 16]


def f1(x):
    return math.cos(x);


def d2f1(x):
    return -math.cos(x);


def f2(x):
    return math.fabs(x) - 1


def d2f2(x):
    return 0


def forward_run_through(b, c, a, vector):
    n = len(b)
    vector[0] /= c[0]
    b[0] /= -c[0]
    for i in range(1, n):
        b[i] /= -(c[i] + a[i - 1] * b[i - 1])
        vector[i] = (vector[i] - a[i - 1] * vector[i - 1]) / (c[i] + a[i - 1] * b[i - 1])
    vector[n] = (vector[n] - a[n - 1] * vector[n - 1]) / (c[n] + a[n - 1] * b[n - 1])


def reverse_run_through(b, vector):
    n = len(b)
    solution = [0] * (n + 1)
    solution[n] = vector[n]
    for i in range(n - 1, -1, -1):
        solution[i] = b[i] * solution[i + 1] + vector[i]
    return solution


def solve_system_using_run_through_method(b, c, a, vector):
    forward_run_through(b, c, a, vector)
    return reverse_run_through(b, vector)


def write(filename, function, l, r):
    with open(filename, 'w') as file:
        for i in range(int((r - l) / 0.01) + 1):
            x = l + i * 0.01
            file.write(f"{x} {function(x)}\n")


def create_folders():
    folders = ["task1", "task2", "task3", "real"]
    for folder in folders:
        if not os.path.exists(folder):
            os.makedirs(folder)


def run():
    create_folders()
    write("real/f1.txt", f1, a, b)
    write("real/f2.txt", f2, a, b)
    for deg in degrees:
        x1 = newton_interpolation.get_equal_points(deg, a, b)
        x2 = newton_interpolation.get_chebyshev_points(deg, a, b)
        y1_1 = []
        y2_1 = []
        y1_2 = []
        y2_2 = []
        for i in range(len(x1)):
            y1_1.append(f1(x1[i]))
            y2_1.append(f2(x1[i]))
            y1_2.append(f1(x2[i]))
            y2_2.append(f2(x2[i]))
        poly1_1 = newton_interpolation.create_polynomial(x1, y1_1)
        poly2_1 = newton_interpolation.create_polynomial(x1, y2_1)
        poly1_2 = newton_interpolation.create_polynomial(x2, y1_2)
        poly2_2 = newton_interpolation.create_polynomial(x2, y2_2)
        write("task1/poly1_" + str(deg) + "_deg.txt", poly1_1, a, b)
        write("task1/poly2_" + str(deg) + "_deg.txt", poly2_1, a, b)
        write("task2/poly1_" + str(deg) + "_deg.txt", poly1_2, a, b)
        write("task2/poly2_" + str(deg) + "_deg.txt", poly2_2, a, b)
        functions1 = spline.get_spline(x1, f1, d2f1)
        functions2 = spline.get_spline(x1, f2, d2f2)
        for i in range(len(functions1)):
            write("task3/spline1_" + str(i) + "_" + str(deg + 1) + "_deg.txt", functions1[i], x1[i], x1[i + 1])
            write("task3/spline2_" + str(i) + "_" + str(deg + 1) + "_deg.txt", functions2[i], x1[i], x1[i + 1])


def make_plots():
    subprocess.run(["plot.exe", "real/f1.txt", "task1/poly1_2_deg.txt"])
    subprocess.run(["plot.exe", "real/f1.txt", "task1/poly1_4_deg.txt"])
    subprocess.run(["plot.exe", "real/f1.txt", "task1/poly1_8_deg.txt"])
    subprocess.run(["plot.exe", "real/f1.txt", "task1/poly1_16_deg.txt"])
    subprocess.run(["plot.exe", "real/f2.txt", "task1/poly2_2_deg.txt"])
    subprocess.run(["plot.exe", "real/f2.txt", "task1/poly2_4_deg.txt"])
    subprocess.run(["plot.exe", "real/f2.txt", "task1/poly2_8_deg.txt"])
    subprocess.run(["plot.exe", "real/f2.txt", "task1/poly2_16_deg.txt"])
    subprocess.run(["plot.exe", "real/f1.txt", "task2/poly1_2_deg.txt"])
    subprocess.run(["plot.exe", "real/f1.txt", "task2/poly1_4_deg.txt"])
    subprocess.run(["plot.exe", "real/f1.txt", "task2/poly1_8_deg.txt"])
    subprocess.run(["plot.exe", "real/f1.txt", "task2/poly1_16_deg.txt"])
    subprocess.run(["plot.exe", "real/f2.txt", "task2/poly2_2_deg.txt"])
    subprocess.run(["plot.exe", "real/f2.txt", "task2/poly2_4_deg.txt"])
    subprocess.run(["plot.exe", "real/f2.txt", "task2/poly2_8_deg.txt"])
    subprocess.run(["plot.exe", "real/f2.txt", "task2/poly2_16_deg.txt"])

    subprocess.call("plot.exe real/f1.txt task3/spline1_0_3_deg.txt task3/spline1_1_3_deg.txt", shell=True)
    subprocess.call("plot.exe real/f1.txt task3/spline1_0_5_deg.txt task3/spline1_1_5_deg.txt task3/spline1_2_5_deg.txt task3/spline1_3_5_deg.txt", shell=True)
    subprocess.call("plot.exe real/f1.txt task3/spline1_0_9_deg.txt task3/spline1_1_9_deg.txt task3/spline1_2_9_deg.txt task3/spline1_3_9_deg.txt task3/spline1_4_9_deg.txt task3/spline1_5_9_deg.txt task3/spline1_6_9_deg.txt task3/spline1_7_9_deg.txt", shell=True)
    subprocess.call("plot.exe real/f1.txt task3/spline1_0_17_deg.txt task3/spline1_1_17_deg.txt task3/spline1_2_17_deg.txt task3/spline1_3_17_deg.txt task3/spline1_4_17_deg.txt task3/spline1_5_17_deg.txt task3/spline1_6_17_deg.txt task3/spline1_7_17_deg.txt task3/spline1_8_17_deg.txt task3/spline1_9_17_deg.txt task3/spline1_10_17_deg.txt task3/spline1_11_17_deg.txt task3/spline1_12_17_deg.txt task3/spline1_13_17_deg.txt task3/spline1_14_17_deg.txt task3/spline1_15_17_deg.txt", shell=True)
    subprocess.call("plot.exe real/f2.txt task3/spline2_0_3_deg.txt task3/spline2_1_3_deg.txt", shell=True)
    subprocess.call("plot.exe real/f2.txt task3/spline2_0_5_deg.txt task3/spline2_1_5_deg.txt task3/spline2_2_5_deg.txt task3/spline2_3_5_deg.txt", shell=True)
    subprocess.call("plot.exe real/f2.txt task3/spline2_0_9_deg.txt task3/spline2_1_9_deg.txt task3/spline2_2_9_deg.txt task3/spline2_3_9_deg.txt task3/spline2_4_9_deg.txt task3/spline2_5_9_deg.txt task3/spline2_6_9_deg.txt task3/spline2_7_9_deg.txt", shell=True)
    subprocess.call("plot.exe real/f2.txt task3/spline2_0_17_deg.txt task3/spline2_1_17_deg.txt task3/spline2_2_17_deg.txt task3/spline2_3_17_deg.txt task3/spline2_4_17_deg.txt task3/spline2_5_17_deg.txt task3/spline2_6_17_deg.txt task3/spline2_7_17_deg.txt task3/spline2_8_17_deg.txt task3/spline2_9_17_deg.txt task3/spline2_10_17_deg.txt task3/spline2_11_17_deg.txt task3/spline2_12_17_deg.txt task3/spline2_13_17_deg.txt task3/spline2_14_17_deg.txt task3/spline2_15_17_deg.txt", shell=True)
