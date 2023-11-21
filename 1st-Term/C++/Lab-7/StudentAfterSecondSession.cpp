#include "StudentAfterSecondSession.h"

#include <string>
#include <vector>

StudentAfterSecondSession::StudentAfterSecondSession(char* name, int course, int group, int record_book_number)
        : StudentAfterFirstSession(name, course, group, record_book_number),
          second_session_marks_(std::vector<int>()) {}

StudentAfterSecondSession::StudentAfterSecondSession(
        char* name, int course, int group, int record_book_number,
        const std::vector<int>& first_session_marks)
        : StudentAfterFirstSession(name, course, group, record_book_number, first_session_marks),
          second_session_marks_(std::vector<int>()) {}

StudentAfterSecondSession::StudentAfterSecondSession(
        char* name, int course, int group, int record_book_number,
        const std::vector<int>& first_session_marks, const std::vector<int>& second_session_marks)
        : StudentAfterFirstSession(name, course, group, record_book_number, first_session_marks),
          second_session_marks_(second_session_marks) {}

StudentAfterSecondSession::StudentAfterSecondSession(const StudentAfterFirstSession& student)
        : StudentAfterFirstSession(student),
          second_session_marks_(std::vector<int>()){}

StudentAfterSecondSession::StudentAfterSecondSession(const StudentAfterSecondSession& student)
        : StudentAfterFirstSession(student), second_session_marks_(student.second_session_marks_) {}

const std::vector<int> StudentAfterSecondSession::GetSecondSessionMarks() const {
    return second_session_marks_;
}

void StudentAfterSecondSession::SetSecondSessionMarks(const std::vector<int> &secondSessionMarks) {
    second_session_marks_ = secondSessionMarks;
}

double StudentAfterSecondSession::GetMeanMark() const {
    double marks_sum = 0;
    for (int i : first_session_marks_) {
        marks_sum += i;
    }
    for (int i : second_session_marks_) {
        marks_sum += i;
    }
    return marks_sum / (first_session_marks_.size() + second_session_marks_.size());
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

std::ostream &operator<<(std::ostream &out, const StudentAfterSecondSession &student) {
  out << (Student&) student;
  out << "\tMarks for first session: " << ToString(student.GetFirstSessionMarks()) << "\n\t";
  out << "Marks for second session: " << ToString(student.GetSecondSessionMarks()) << "\n\t";
  out << "Mean mark: " << std::to_string(student.GetMeanMark()) << "\n";
  return out;
}