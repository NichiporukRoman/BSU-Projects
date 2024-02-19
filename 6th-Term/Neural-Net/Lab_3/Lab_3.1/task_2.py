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

# maybe it's not right
def find_cube_colors(N, M, colors_a, colors_b):
    colors_a = set(colors_a)  # Множество для цветов кубиков Ани
    colors_b = set(colors_b)  # Множество для цветов кубиков Бори

    common_colors = sorted(colors_a & colors_b)  # Пересечение множеств colors_a и colors_b, отсортированное
    only_colors_a = sorted(colors_a - colors_b)  # Разность множеств colors_a и colors_b, отсортированная
    only_colors_b = sorted(colors_b - colors_a)  # Разность множеств colors_b и colors_a, отсортированная

    return common_colors, only_colors_a, only_colors_b


list1 = [1, 2, 3, 4, 5]
list2 = [4, 5, 6, 7, 8]
print('Elements In Two Lists:', get_count_of_two_lists(list1, list2))
input_string = "1 2 3 2 4 3 5"
results = check_previous_numbers(input_string)
print(results)
N, M = map(int, input().split())

colors_a = []
for _ in range(N):
    color = int(input())  # Anna
    colors_a.append(color)

colors_b = []
for _ in range(M):
    color = int(input())  # Borya
    colors_b.append(color)

result = find_cube_colors(N, M, colors_a, colors_b)
common_colors, only_colors_a, only_colors_b = result

# Выводим результаты
print('Number of common cubes:', len(common_colors))
print('Color of common cubes:', common_colors)
print("Number of Anna's cubes:", len(only_colors_a))
print("Color of Anna's cubes:", only_colors_a)
print("Number of Borya's cubes:", len(only_colors_b))
print("Color of Borya's cubes:", only_colors_b)
