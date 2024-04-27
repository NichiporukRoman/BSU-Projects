from Lab_3.Code.implicit_euler_method import *
from Lab_3.Code.runge_kutta_method_4th_order import *
from Lab_3.Code.utility import *
from Lab_3.Code.input_data import *


x_values, y_values = implicit_euler(f, x_values, u0, h, num_steps)
display_data(x_values, y_values,
             'Solving a system of differential equations using the implicit Euler method')

y_imt_right = y_values[-1]

x_values, y_values = runge_kutta_fourth_order(f, h, u0, x_values)
display_data(x_values, y_values,
             'Solving a system of differential equations using the 4th order Runge-Kutta method')

y_rk_right = y_values[-1]

print("Modulus of the difference of solutions at the rightmost point of the interval: ",
      abs(y_imt_right-y_rk_right))
