#ifndef UNTITLED4_STUDENTAFTERSECONDSESSION_H
#define UNTITLED4_STUDENTAFTERSECONDSESSION_H

#include <vector>

#include "StudentAfterFirstSession.h"

class StudentAfterSecondSession : public StudentAfterFirstSession {
public :
    StudentAfterSecondSession() = delete;

    StudentAfterSecondSession(char* name, int course, int group, int record_book_number);

    StudentAfterSecondSession(
            char* name, int course, int group, int record_book_number,
            const std::vector<int>& first_session_marks);

    StudentAfterSecondSession(
            char* name, int course, int group, int record_book_number,
            const std::vector<int>& first_session_marks, const std::vector<int>& second_session_marks);

    explicit StudentAfterSecondSession(const StudentAfterFirstSession& student);
    StudentAfterSecondSession(const StudentAfterSecondSession& student);

    const std::vector<int> GetSecondSessionMarks() const;

    void SetSecondSessionMarks(const std::vector<int> &secondSessionMarks);

    double GetMeanMark() const override;

protected:
    std::vector<int> second_session_marks_;
};

std::ostream &operator<<(std::ostream &out, const StudentAfterSecondSession &student);

#endif //UNTITLED4_STUDENTAFTERSECONDSESSION_H
