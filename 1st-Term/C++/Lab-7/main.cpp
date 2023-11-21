#include "Student.h"
#include "StudentAfterFirstSession.h"
#include "StudentAfterSecondSession.h"

using namespace std;

int main() {
  Student student("abc", 2, 2, 2);
  StudentAfterFirstSession student_after_first_session(student);
  return 0;
}
