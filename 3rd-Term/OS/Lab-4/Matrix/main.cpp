#include <iostream>
#include "Matrix.h"
#include <thread>

void syncTests(Matrix& a, Matrix& b){
    auto start = std::chrono::high_resolution_clock::now();
    Matrix startResult = Matrix::matrixBlockMultiply(a, b, 2, 1);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    for (int i = 1; i <= a.getMatrix().size(); ++i) {
        start = std::chrono::high_resolution_clock::now();
        Matrix result = Matrix::matrixBlockMultiply(a, b, i, 75);
        end = std::chrono::high_resolution_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        std::cout << "For block size " << i << ":" <<  elapsed.count() << std::endl;
    }

}

int main() {
    std::vector<double> line = std::vector<double>({7, 11, 92, 3, 5});
    std::vector<double> line1 = std::vector<double>({6, 47, 1, 52, 94});
    std::vector<double> line2 = std::vector<double>({4, 43, 87, 36, 22});
    std::vector<double> line3 = std::vector<double>({8, 45, 98, 67, 23});
    std::vector<double> line4 = std::vector<double>({90, 13, 23, 76, 56});
    std::vector<std::vector<double>> matrix1 = std::vector<std::vector<double>>({line, line1, line2, line3, line4});

    std::vector<double> line5 = std::vector<double>({78, 87, 74, 35, 59});
    std::vector<double> line6 = std::vector<double>({93, 60, 30, 29, 54});
    std::vector<double> line7 = std::vector<double>({62, 95, 83, 1, 48});
    std::vector<double> line8 = std::vector<double>({12, 73, 70, 24, 86});
    std::vector<double> line9 = std::vector<double>({7, 12, 43, 5, 95});
    std::vector<std::vector<double>> matrix2 = std::vector<std::vector<double>>({line5, line6, line7, line8, line9});

    Matrix mx1 = Matrix(matrix1);
    Matrix mx2 = Matrix(matrix2);

    syncTests(mx1, mx2);
}
