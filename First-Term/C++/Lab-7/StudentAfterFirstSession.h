#ifndef UNTITLED4_STUDENTAFTERFIRSTSESSION_H
#define UNTITLED4_STUDENTAFTERFIRSTSESSION_H

#include <vector>

#include "Student.h"

class StudentAfterFirstSession : public Student {
public :
    StudentAfterFirstSession() = delete;

    StudentAfterFirstSession(char* name, int course, int group, int record_book_number);
    StudentAfterFirstSession(char* name, int course, int group, int record_book_number, const std::vector<int>& marks);
    explicit StudentAfterFirstSession(const Student& student);
    StudentAfterFirstSession(const StudentAfterFirstSession& student);

    const std::vector<int> GetFirstSessionMarks() const;

    void SetFirstSessionMarks(const std::vector<int> &firstSessionMarks);

    virtual double GetMeanMark() const;

protected:
    std::vector<int> first_session_marks_;
};

double GetMeanMarkOfGroup(int group, const std::vector<StudentAfterFirstSession>& students);

std::ostream &operator<<(std::ostream &out, const StudentAfterFirstSession &student);

#endif //UNTITLED4_STUDENTAFTERFIRSTSESSION_H
