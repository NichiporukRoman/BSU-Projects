#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
class Matrix {
public:
    explicit Matrix(std::vector<std::vector<double>> matrix);
    explicit Matrix() = default;
    ~Matrix() = default;

    std::vector<std::vector<double>> getMatrix() const;
    int getSize() const;

    static void blockMultiply(const Matrix& m1, const Matrix& m2, Matrix& resultBlock, int iCord, int jCord, int number);
    static Matrix matrixBlockMultiply(Matrix m1, Matrix m2, int number);

    static void writeMatrix(Matrix matrix){
        for (const auto &line : matrix._matrix){
            for (auto &item : line){
                std::cout << item << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    std::vector<std::vector<double>> _matrix;
};
