# Solve
from utilities import sig, logical_xor

I = [1, 0]
w = [0.45, 0.78, -0.12, 0.13, 1.5, -2.3]
b = [4, -8, 3]

H1input = I[0] * w[0] + I[1] * w[2] + b[0]
H1output = sig(H1input)

H2input = I[0] * w[1] + I[1] * w[3] + b[1]
H2output = sig(H2input)

O1input = H1output * w[4] + H2output * w[5] + b[2]
O1output = sig(O1input)

O1ideal = (logical_xor(I[0], I[1]))
MSE = (pow(O1ideal - O1output, 2)) / 1

print('RESULT:', str(round(O1output, 2)))
print('MSE:', str(round(MSE, 2)))
