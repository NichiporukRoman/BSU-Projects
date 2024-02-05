#include <iostream>
#include <vector>
#include <windows.h>
#include <mutex>
#include <math.h>
#include "buffered_channel.h"
#include <list>

class Matrix {
public:
    explicit Matrix(std::vector<std::vector<double>> matrix);
    explicit Matrix() = default;
    ~Matrix() = default;

    std::vector<std::vector<double>> getMatrix() const;
    int getSize() const;

    static void blockMultiply(const Matrix& m1, const Matrix& m2, Matrix& resultBlock, size_t iCord, size_t jCord, size_t number);
    static Matrix matrixBlockMultiply(Matrix m1, Matrix m2, int number);

    static DWORD WINAPI Call(LPVOID args){
        Args *castedArgs = (Args*)args;
        blockMultiply(castedArgs -> m1, castedArgs -> m2, castedArgs -> result, castedArgs -> i, castedArgs -> j, castedArgs ->number);
        ExitThread(0);
    }

    static void writeMatrix(Matrix matrix){
        for (const auto &line : matrix._matrix){
            for (auto &item : line){
                std::cout << item << " ";
            }
            std::cout << std::endl;
        }
    }

    struct Args{
        Args(const Matrix &m1, const Matrix &m2, Matrix &result, size_t i, size_t j, size_t number)
                : m1(m1), m2(m2), result(result), i(i), j(j), number(number)  {}
        const Matrix &m1;
        const Matrix &m2;
        Matrix &result;
        size_t i;
        size_t j;
        size_t number;
    };

private:
    std::vector<std::vector<double>> _matrix;
};