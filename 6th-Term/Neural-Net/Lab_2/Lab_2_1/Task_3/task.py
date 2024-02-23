from decimal import getcontext, Decimal


def get_last_digit(number):
    last_digit = number % 10
    return last_digit


def get_fractional_part(x):
    decimal_x = Decimal(str(x))
    fractional_part = decimal_x - Decimal(int(x))
    return fractional_part


def get_first_decimal_digit(x):
    fractional_part = x - int(x)
    decimal_digit = int(fractional_part * 10)
    return decimal_digit


def round_ru(x):
    integer_part = int(x)
    fractional_part = x - integer_part

    if fractional_part < 0.5:
        return integer_part
    else:
        return integer_part + 1


print('Last Digit:', get_last_digit(1213136))
print('Fractional Part:', get_fractional_part(12.312321312))
print('First Decimal Digit:', get_first_decimal_digit(12.312321312))
print('Rounded:', round_ru(12.512321312))
