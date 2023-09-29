#include <fstream>
#include <string>

using namespace std;

bool IsConsistsOfOnlySpaces(string& s) {
  for (char c : s) {
    if (c != ' ') return false;
  }
  return true;
}

void PrintNewGroup(int space_count, int first_index, int last_index, ofstream& out) {
  out << "Group of strings with " << space_count << " spaces :" << endl;
  out << "\tFirst line index: " << first_index << endl;
  out << "\tLast line index: " << last_index << endl;
  out << endl;
}

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");
  string last_input;
  bool was_previous_string_correct = false;
  int previous_string_size;
  int group_start_index = 0;
  int string_index = -1;

  if (in.eof()) return 0;

  do {
    getline(in, last_input);
    ++string_index;

    if (!IsConsistsOfOnlySpaces(last_input))
    {
      if (was_previous_string_correct)
      {
        PrintNewGroup(previous_string_size, group_start_index, string_index - 1, out);
      }
      was_previous_string_correct = false;
    } else {
      if (was_previous_string_correct)
      {
        if (last_input.size() != previous_string_size) 
        {
          PrintNewGroup(previous_string_size,
                        group_start_index,
                        string_index - 1,
                        out);
          group_start_index = string_index;
        }
      } else {
        group_start_index = string_index;
      }
      was_previous_string_correct = true;
    }

    previous_string_size = last_input.size();
    was_previous_string_correct = IsConsistsOfOnlySpaces(last_input);
  } while (!in.eof());

  if (was_previous_string_correct) {
    PrintNewGroup(previous_string_size, group_start_index, string_index, out);
  }

  return 0;
}