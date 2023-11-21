//variant 11
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double epsilon, x;

    int num;
    cout << "Enter number of signs after comma:" << endl;
    cin >> num;
    cout << fixed << setprecision(num);

    int k;
    cout << "Enter integer k > 1:" << endl;
    cin >> k;
    epsilon = 1 / (pow(10, k));

    cout << "Enter any x:" << endl;
    cin >> x;

    double manuallyComputed = (exp(x) - exp(-x)) / 2;
    cout << "Manually computed : " << manuallyComputed << endl;

    double nextTerm = x;
    double result = 0;
    int stepen = 1;
    while (abs(nextTerm) > epsilon) {
        result += nextTerm;
        nextTerm = nextTerm * x * x / (stepen + 1) / (stepen + 2);
        stepen += 2;
    }
    cout << "epsilon = " << epsilon << endl;
    cout << "last term = " << nextTerm << endl;
    cout << "general sum = " << result << endl;

    return 0;
}
