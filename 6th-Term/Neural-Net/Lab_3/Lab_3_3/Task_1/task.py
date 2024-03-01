def write_last_names_to_file(last_names, file_name):
    with open(file_name, "w") as file:
        for last_name in last_names:
            file.write(last_name + "\n")


def write_full_names_to_file(last_names, names, file_name):
    with open(file_name, "w") as file:
        for last_name, name in zip(last_names, names):
            file.write(last_name + " " + name + "\n")


def print_file_content(file_name):
    with open(file_name, "r") as file:
        content = file.read()
        print(content)


def print_file_content_numerated(file_name):
    with open(file_name, "r") as file:
        for idx, line in enumerate(file, start=1):
            print(str(idx), line.strip())


def print_file_content_initials_numerated(file_name):
    with open(file_name, "r") as file:
        for idx, line in enumerate(file, start=1):
            strings = str(line).split(" ")
            print(str(idx), strings[0], strings[1][0] + ".")


last_names = ["Аленников", "Березко", "Бушлякова", "Видевич"]
names = ["Борис", "Иван", "Маргарита", "Александр"]

write_last_names_to_file(last_names, "group.txt")
print_file_content_numerated("group.txt")
write_full_names_to_file(last_names, names, "group_with_names.txt")
print_file_content_numerated("group_with_names.txt")
print_file_content_initials_numerated("group_with_names.txt")
