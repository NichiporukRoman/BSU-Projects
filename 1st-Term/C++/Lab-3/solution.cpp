#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime> 
#include <chrono>
#include <iomanip>
using namespace std;

int sign(int a) {
	return a >= 0 ? 1 : -1;
}

int main() {
	vector<vector<int>> matrix(10, vector<int>(10, 0));
	vector<int> sum_of_columns(10);

	srand(time(0));

	for (size_t i = 0; i < matrix.size(); i++)
	{
		for (size_t j = 0; j < matrix.front().size(); j++)
		{
			matrix[i][j] = rand() - rand() / 4;
			if ((i + j) % 2 == 0) {
				matrix[i][j] = 10;
			}
		}
	}

	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			sum_of_columns[j] += matrix[i][j];
		}
	}

	cout << "Matrix at the start:" << endl;
	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			cout << setw(7) << right << matrix[i][j] << fixed;
		}
		cout << endl;
	}
	cout << endl;

	cout << "Sum of elements in columns at the start:" << endl;
	for (size_t i = 0; i < 10; i++)
	{
		cout << setw(7) << right << sum_of_columns[i] << fixed;
	}
	cout << endl;
	cout << endl;

	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 10 - 1 - i; j++)
		{
			if (sum_of_columns[j] > sum_of_columns[j + 1])
			{
				int temp = sum_of_columns[j];
				sum_of_columns[j] = sum_of_columns[j + 1];
				sum_of_columns[j + 1] = temp;

				vector<int> temp2 = matrix[j];
				matrix[j] = matrix[j + 1];
				matrix[j + 1] = temp2;
			}
		}
	}

	cout << "Matrix at the end:" << endl;
	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			cout << setw(7) << right << matrix[i][j] << fixed;
		}
		cout << endl;
	}
	cout << endl;

	cout << "Sum of elements in columns at the end:" << endl;
	for (size_t i = 0; i < 10; i++)
	{
		cout << setw(7) << right << sum_of_columns[i] << fixed;
	}
	cout << endl;
	cout << endl;

	int index_of_needed_column = -1;
	for (size_t i = 0; i < 10; i++)
	{
		int column_sign = 1;
		for (size_t j = 0; j < 10; j++)
		{
			column_sign *= sign(matrix[j][i]);
			if (column_sign == -1) break;
		}
		if (column_sign == 1) {
			index_of_needed_column = i;
			break;
		}
	}

	if (index_of_needed_column == -1) {
		cout << "There is no columns with all non-negative elements";
	} else {
		cout << "Index of first column with all non-negative elements: " << index_of_needed_column;
	}
	cout << endl;

	return 0;
}