#include <iostream>
#include <cstdlib>
#include <ctime> 
#include <chrono>
using namespace std;

int main()
{
	const int n = 15;
	double arr[n] = {};
	int choosen;
	cout << "Enter 1 if you want to fill the array by yourself" << endl << "1. From keyboard" << endl << "2. Everything else to do it randomly" << endl << "Your choice: ";
	cin >> choosen;
	if (choosen == 1) {
		for (int i = 1; i < n; i++) {
			cin >> arr[i];
		}
	}
	else {
		srand(chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count());
	}
	srand(chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count());
	cout << "Scary sorted array: ";
	for (int i = 0; i < n; i++)
	{
		arr[i] = (double)rand() / RAND_MAX;
	}

	double min = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > min) {
			min = arr[i];
			cout << arr[i] << " | ";;
		}
	}

	cout << endl;
	int current_index_min = 0;
	int current_index_max = 0;
	min = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] < min) {
			min = arr[i];
			current_index_min = i;
		}
	}
	cout << "Minimum index: " << current_index_min << ", ";

	double max = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > max) {
			max = arr[i];
			current_index_max = i;
		}
	}
	cout << "Maximum index: " << current_index_max << endl;

	double result, intermediate_value = 1;
	if (current_index_min < current_index_max) {
		for (int i = current_index_min; i < current_index_max + 1; i++) {
			result = intermediate_value * arr[i];
			intermediate_value = result;
		}
	}
	else
	{
		for (int i = current_index_max; i < current_index_min + 1; i++) {
			result = intermediate_value * arr[i];
			intermediate_value = result;

		}
	}
	cout << "Product of values between minimum and maximum: " << result << endl;

	double prev = arr[1];
	double next = arr[3];
	bool found = true;
	while (found) {
		found = false;
		for (int i = 1; i < n - 2; i += 2) {
			prev = arr[i];
			next = arr[i + 2];
			if (prev > next) {
				arr[i] = next;
				arr[i + 2] = prev;
				found = true;
			}
		
		}
	}

	cout << "Interestingly sorted array: ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " | ";
	}
	cout << endl << endl << endl;
	return 0;
}