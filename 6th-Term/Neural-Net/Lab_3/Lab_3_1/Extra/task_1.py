def count_nonzero_digits(number):
    number_str = str(number)
    count = 0
    for digit in number_str:
        if digit != '0':
            count += 1
    return count


print(count_nonzero_digits(1010101010))
print(count_nonzero_digits(0000))
print(count_nonzero_digits(111))
