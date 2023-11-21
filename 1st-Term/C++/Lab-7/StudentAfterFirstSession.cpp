#include "StudentAfterFirstSession.h"

#include <string>
#include <vector>

StudentAfterFirstSession::StudentAfterFirstSession(char *name, int course, int group, int record_book_number)
        : Student(name, course, group, record_book_number), first_session_marks_(std::vector<int>()) {}

StudentAfterFirstSession::StudentAfterFirstSession(char* name, int course, int group, int record_book_number, const std::vector<int>& marks)
        : Student(name, course, group, record_book_number), first_session_marks_(marks) {}

StudentAfterFirstSession::StudentAfterFirstSession(const Student& student)
        : StudentAfterFirstSession(student.name_, student.course_, student.group_, student.kRecordBookNumber_) {}

StudentAfterFirstSession::StudentAfterFirstSession(const StudentAfterFirstSession& student)
        : Student(student), first_session_marks_(student.first_session_marks_) {}

const std::vector<int> StudentAfterFirstSession::GetFirstSessionMarks() const {
    return first_session_marks_;
}

void StudentAfterFirstSession::SetFirstSessionMarks(const std::vector<int> &firstSessionMarks) {
    first_session_marks_ = firstSessionMarks;
}

double StudentAfterFirstSession::GetMeanMark() const {
    double marks_sum = 0;
    for (int i : first_session_marks_) {
        marks_sum += i;
    }
    return marks_sum / first_session_marks_.size();
}

double GetMeanMarkOfGroup(int group, const std::vector<StudentAfterFirstSession>& students) {
    double marks_sum = 0;
    int students_count = 0;
    for (const StudentAfterFirstSession student : students) {
        if (student.GetGroup() != group) continue;

        marks_sum += student.GetMeanMark();
        ++students_count;
    }

    return marks_sum / students_count;
}

namespace {
    std::string ToString(std::vector<int> vector) {
        std::string result;
        for (int i : vector) {
            result += std::to_string(i) + ", ";
        }
        result.pop_back();
        result.pop_back();

        return result;
    }
}

std::ostream &operator<<(std::ostream &out, const StudentAfterFirstSession &student) {
  out << (Student&) student;
  out << "\tMarks for first session: " << ToString(student.GetFirstSessionMarks()) << "\n\t";
  out << "Mean mark: " << std::to_string(student.GetMeanMark()) << "\n";
  return out;
}
