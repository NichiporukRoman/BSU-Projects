def get_count_of_two_lists(list1_, list2_):
    return len(list(list1_ + list2_))


def check_previous_numbers(input_string_):
    numbers = input_string_.split()
    seen_numbers = {}
    results_ = []

    for number in numbers:
        if number in seen_numbers:
            results_.append("YES")
        else:
            results_.append("NO")
            seen_numbers[number] = True

    return results_


def find_cube_colors(N, M, colors_anya, colors_borya):
    colors_anya = set(colors_anya)
    colors_borya = set(colors_borya)

    both = sorted(colors_anya & colors_borya)

    anya_only = sorted(colors_anya - colors_borya)

    borya_only = sorted(colors_borya - colors_anya)

    return len(both), both, len(anya_only), anya_only, len(borya_only), borya_only


list1 = [1, 2, 3, 4, 5]
list2 = [4, 5, 6, 7, 8]
print('Elements In Two Lists:', get_count_of_two_lists(list1, list2))
input_string = "1 2 3 2 4 3 5"
results = check_previous_numbers(input_string)
print(results)
