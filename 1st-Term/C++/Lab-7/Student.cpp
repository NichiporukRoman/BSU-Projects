#include "Student.h"

Student::Student(char* name, int course, int group, int record_book_number)
        : name_(name), course_(course), group_(group), kRecordBookNumber_(record_book_number) {};

Student::Student(const Student& student)
        : name_(student.name_),
          course_(student.course_),
          group_(student.group_),
          kRecordBookNumber_(student.kRecordBookNumber_) {};

int Student::next_id_ = 0;

char *Student::GetName() const {
    return name_;
}

void Student::SetName(char *name) {
    Student::name_ = name;
}

int Student::GetCourse() const {
    return course_;
}

void Student::SetCourse(int course) {
    Student::course_ = course;
}

int Student::GetGroup() const {
    return group_;
}

void Student::SetGroup(int group) {
    Student::group_ = group;
}

int Student::GetRecordBookNumber() const {
    return kRecordBookNumber_;
}

int Student::GetId() const {
    return id;
}

std::ostream &operator<<(std::ostream &out, const Student &student) {
    out << "Student:" << "\n\t";
    out << "Name: " << student.GetName() << "\n\t";
    out << "Course: " << student.GetCourse() << "\n\t";
    out << "Group: " << student.GetGroup() << "\n\t";
    out << "Record book number: " << student.GetRecordBookNumber() << "\n\t";
    out << "Id: " << student.GetId() << "\n";
    return out;
}
