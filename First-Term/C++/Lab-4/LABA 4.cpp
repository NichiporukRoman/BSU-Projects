#include <vector>
#include <iostream>

using namespace std;

bool HasInVector(const vector<char>& array, char search) {
	for (char element : array)
	{
		if (element == search) return true;
	}
	return false;
}

int strcspn(const vector<char>& s, const vector<char>& forbidden) {
	int result = 0;
	while (result < s.size() && !HasInVector(forbidden, s[result])) ++result;
	return result;
}

void Capitalize(vector<char>& s) {
	if (s.size() == 0) return;
	if (s[0] <= 'z' && s[0] >= 'a') s[0] = s[0] - 'a' + 'A';
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i - 1] == ' ' && (s[i] >= 'a' && s[i] <= 'z')) s[i] = s[i] - 'a' + 'A';
	}
}

vector<char> GetLine() {
	vector<char> s;
	char current;
	do {
		current = cin.get();
		s.push_back(current);
	} while (current != '\n');
	return s;
}

int main() {
	{
		vector<char> a, b;
		a = GetLine();
		b = GetLine();

		cout << strcspn(a, b) << endl;
	}
	{
		vector<char> a;
		a = GetLine();

		Capitalize(a);

		for (char c : a) cout << c;
		cout << endl;
	}
	return 0;
}