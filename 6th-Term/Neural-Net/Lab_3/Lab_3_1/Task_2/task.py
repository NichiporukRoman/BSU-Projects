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
def find_cube_colors(N, M, colors_a_, colors_b_):
    colors_a_ = set(colors_a_)  # Множество для цветов кубиков Ани
    colors_b_ = set(colors_b_)  # Множество для цветов кубиков Бори

    common_colors_ = sorted(colors_a_ & colors_b_)  # Пересечение множеств colors_a_ и colors_b_, отсортированное
    only_colors_a_ = sorted(colors_a_ - colors_b_)  # Разность множеств colors_a_ и colors_b_, отсортированная
    only_colors_b_ = sorted(colors_b_ - colors_a_)  # Разность множеств colors_b_ и colors_a, отсортированная

    return common_colors_, only_colors_a_, only_colors_b_


def find_possible_numbers(n, questions_):
    possible_numbers = set(range(1, n + 1))
    for question, answer in questions_:
        question_set = set(question)

        if answer == "NO":
            possible_numbers -= question_set
        else:
            possible_numbers &= question_set

    return sorted(possible_numbers)


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


print('Number of common cubes:', len(common_colors))
print('Color of common cubes:', common_colors)
print("Number of Anna's cubes:", len(only_colors_a))
print("Color of Anna's cubes:", only_colors_a)
print("Number of Borya's cubes:", len(only_colors_b))
print("Color of Borya's cubes:", only_colors_b)


questions = [([1, 2, 3], "YES"), ([4, 5, 6], "NO"), ([2, 4], "YES")]
result = find_possible_numbers(10, questions)
print(result)
