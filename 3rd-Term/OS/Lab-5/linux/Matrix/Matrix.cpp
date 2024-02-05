#include "Matrix.h"

Matrix::Matrix(std::vector<std::vector<double >> matrix) {
    _matrix = std::move(matrix);
}
std::mutex mutex;

void Matrix::blockMultiply(const Matrix& m1, const Matrix& m2, Matrix& resultBlock, size_t iCord, size_t jCord, size_t number){
    size_t size = m1.getSize();
    for (size_t i = iCord; i < std::min(iCord+ number, size); ++i) {
        for (size_t j = jCord; j < std::min(jCord + number, size); ++j) {
            for (int k = 0; k < size; ++k) {
                mutex.lock();
                resultBlock._matrix[i][j] += m1._matrix[i][k] * m2._matrix[k][j];
                mutex.unlock();
            }
        }
    }
}

Matrix Matrix::matrixBlockMultiply(Matrix m1, Matrix m2, int number){
    std::vector<std::vector<double>> res(5, std::vector<double>(5,0));
    size_t countOfBlocks = m1.getSize() % number == 0 ? m1.getSize() / number : m1.getSize() / number + 1;
    Matrix result = Matrix(res);
    std::vector<pthread_t> threads(countOfBlocks * countOfBlocks);
    pthread_attr_t attr;
    int currentThreadIndex = 0;
    int size = m1.getSize();
    for (int i = 0; i < size; i += number) {
        for (int j = 0; j < size; j += number){
            pthread_create(&threads[currentThreadIndex++], NULL, Matrix::Call, new Args(m1, m2, result, i, j, number));
        }
    }


    for (pthread_t &thread : threads)
    {
        pthread_join(thread, NULL);
    }
    return result;
}

int Matrix::getSize() const {
    return this->_matrix.size();
}

std::vector<std::vector<double>> Matrix::getMatrix() const{
    return this->_matrix;
}

void writeMatrix(Matrix matrix){
    for (const auto &line : matrix.getMatrix()){
        for (auto &item : line){
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
}