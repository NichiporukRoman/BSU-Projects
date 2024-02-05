#include <iostream>
#include <vector>
#include <math.h>
#include <pthread.h>
#include <mutex>
class Matrix {
public:
    explicit Matrix(std::vector<std::vector<double>> matrix);
    explicit Matrix() = default;
    ~Matrix() = default;

    std::vector<std::vector<double>> getMatrix() const;
    int getSize() const;

    static void blockMultiply(const Matrix& m1, const Matrix& m2, Matrix& resultBlock, size_t iCord, size_t jCord, size_t number);
    static Matrix matrixBlockMultiply(Matrix m1, Matrix m2, int number);

    static void writeMatrix(Matrix matrix){
        for (const auto &line : matrix._matrix){
            for (auto &item : line){
                std::cout << item << " ";
            }
            std::cout << std::endl;
        }
    }

    struct Args
    {
        Args(const Matrix &m1, const Matrix &m2, Matrix &result, size_t iCord, size_t jCord, size_t number) : m1(m1), m2(m2), result(result), iCord(iCord), jCord(jCord), number(number)
        {
        }
        const Matrix &m1;
        const Matrix &m2;
        Matrix &result;
        size_t iCord;
        size_t jCord;
        size_t number;
    };

    static void* Call(void* args)
    {
        Args *castedArgs = (Args *)args;
        blockMultiply(castedArgs->m1, castedArgs->m2, castedArgs->result, castedArgs->iCord, castedArgs->jCord, castedArgs->number);
        pthread_exit(NULL);
    }

private:
    std::vector<std::vector<double>> _matrix;
};