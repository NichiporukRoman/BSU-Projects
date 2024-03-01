def count_previous_occurrences(text):
    words = text.split()
    word_count = {}

    counts = []
    for word in words:
        count = word_count.get(word, 0)
        counts.append(count)
        word_count[word] = count + 1

    return word_count


def find_synonym(dictionary, word):
    synonym = dictionary.get(word)
    reverse_dictionary = {v: k for k, v in dictionary.items()}
    word_ = reverse_dictionary.get(word)
    if word_:
        return word_
    elif synonym:
        return synonym
    else:
        return "Синоним не найден"


def find_most_frequent_word(text):
    values = count_previous_occurrences(text)
    value = max(values.values())
    reverse_dictionary = {v: k for k, v in values.items()}
    return "{" + reverse_dictionary.get(value) + ": " + str(value) + "}"


def frequent_sorted_words(text):
    values = count_previous_occurrences(text)
    sorted_words = sorted(values.items(), key=lambda x: (-x[1], x[0]))
    return sorted_words


text = "это пример текста это текста это"
result = count_previous_occurrences(text)
print(result)


dictionary = {
    'apple': 'яблоко',
    'car': 'машина',
    'house': 'дом',
    'tree': 'дерево',
    'book': 'книга'
}

word = input()
print(find_synonym(dictionary, word))


text = "это пример текста это это"
print(find_most_frequent_word(text))


n = int(input())
lines = [input() for _ in range(n)]
text = ' '.join(lines)
print(frequent_sorted_words(text))
