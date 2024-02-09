from utilities import sig, logical_xor
# I1 = 1, I2 = 0

w = [2.7, 0.78, -0.12, 0.5, 6, -1]

H1input = 1 * w[0] + 0 * w[2]
H1output = sig(H1input)

H2input = 1 * w[1] + 0 * w[3]
H2output = sig(H2input)

O1input = H1output * w[4] + H2output * w[5]
O1output1 = sig(O1input)

O1ideal1 = (logical_xor(1, 0))

print("RESULT (1 0): " + str(round(O1output1, 2)))

# I1 = 1, I2 = 1

w = [0, 0, -4, 1, -26, -11]

H1input = 1 * w[0] + 1 * w[2]
H1output = sig(H1input)

H2input = 1 * w[1] + 1 * w[3]
H2output = sig(H2input)

O1input = H1output * w[4] + H2output * w[5]
O1output2 = sig(O1input)

O1ideal2 = (logical_xor(1, 1))

print("RESULT (1 1): " + str(round(O1output2, 2)))

# I1 = 0, I2 = 0

w = [0, 0, 0, 0, -13, 1]

H1input = 0 * w[0] + 0 * w[2]
H1output = sig(H1input)

H2input = 0 * w[1] + 0 * w[3]
H2output = sig(H2input)

O1input = H1output * w[4] + H2output * w[5]
O1output3 = sig(O1input)

O1ideal3 = (logical_xor(0, 0))

print("RESULT (0 0): " + str(round(O1output3, 2)))

# I1 = 0, I2 = 1

w = [0.78, 2.7, 0.5, -0.12, 1, 10]

H1input = 0 * w[0] + 1 * w[2]
H1output = sig(H1input)

H2input = 0 * w[1] + 1 * w[3]
H2output = sig(H2input)

O1input = H1output * w[4] + H2output * w[5]
O1output4 = sig(O1input)

O1ideal4 = (logical_xor(0, 1))

print("RESULT (0 1): " + str(round(O1output4, 2)))

MSE = (pow(O1ideal1 - O1output1, 2) +
       pow(O1ideal2 - O1output2, 2) +
       pow(O1ideal3 - O1output3, 2) +
       pow(O1ideal4 - O1output4, 2)) / 4

print("MSE: " + str(round(MSE, 2)))
