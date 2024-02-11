def max_of_3(a, b, c):
    return max(a, b, c)


def how_many_numbers_are_equals(a, b, c):
    if a == b == c:
        return 3
    elif a == b or a == c or b == c:
        return 2
    else:
        return 0


def is_leap_year(year):
    if year % 4 == 0 and (year % 100 != 0 or year % 400 == 0):
        return True
    else:
        return False


def can_rook_move(start_col, start_row, end_col, end_row):
    if start_col == end_col or start_row == end_row:
        return "YES"
    else:
        return "NO"


a = input("a: ")
b = input("b: ")
c = input("c: ")
print(max_of_3(a, b, c))
print(how_many_numbers_are_equals(a, b, c))

year = input("year: ")
print(is_leap_year(int(year)))

start_col = input("start_col: ")
start_row = input("start_row: ")
end_col = input("end_col: ")
end_row = input("end_row: ")
print(can_rook_move(start_col, start_row, end_col, end_row))
