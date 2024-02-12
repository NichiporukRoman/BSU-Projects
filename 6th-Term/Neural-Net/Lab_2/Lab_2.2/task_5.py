import random


def get_even_numbers_by_index(A):
    return A[::2]


def get_elements_greater_previous(numbers):
    result = []
    for i in range(1, len(numbers)):
        if numbers[i] > numbers[i - 1]:
            result.append(numbers[i])
    return result


def swap_min_max(numbers):
    min_index = numbers.index(min(numbers))
    max_index = numbers.index(max(numbers))
    numbers[min_index], numbers[max_index] = numbers[max_index], numbers[min_index]


def count_elements_greater_neighbors(numbers):
    count = 0
    for i in range(1, len(numbers) - 1):
        if numbers[i] > numbers[i - 1] and numbers[i] > numbers[i + 1]:
            count += 1
    return count


def find_longest_sequence(arr):
    max_length = 0
    max_start = 0
    max_end = 0

    current_length = 0
    current_start = 0

    for i in range(len(arr)):
        if arr[i] == 1:
            current_length += 1
            if current_length == 1:
                current_start = i
            if current_length > max_length:
                max_length = current_length
                max_start = current_start
                max_end = i
        else:
            current_length = 0

    return max_start, max_end


print('Even ID Numbers: ', get_even_numbers_by_index([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]))
print('Elements Greater Previous: ', get_elements_greater_previous([1, 3, 5, 2, 4, 7, 6, 9]))
print('Number Of Elements Greater Neighbors: ', count_elements_greater_neighbors([1, 3, 5, 2, 4, 7, 6, 9]))

numbers = [1, 3, 5, 2, 4, 7, 6, 9]
swap_min_max(numbers)
print('Swapped Min Max Array: ', numbers)

arr = [random.choice([0, 1]) for _ in range(20)]
print(arr)
start, end = find_longest_sequence(arr)
print("First ID:", start, "Last ID:", end)
