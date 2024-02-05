#include "Matrix.h"

    Matrix::Matrix(std::vector<std::vector<double >> matrix) {
    _matrix = std::move(matrix);
}

    void Matrix::blockMultiply(const Matrix& m1, const Matrix& m2, Matrix& resultBlock, int iCord, int jCord, int number){
        int size = m1.getSize();
        for (int i = iCord; i < std::min(iCord+ number, size); ++i) {
            for (int j = jCord; j < std::min(jCord + number, size); ++j) {
                for (int k = 0; k < size; ++k) {
                    resultBlock._matrix[i][j] += m1._matrix[i][k] * m2._matrix[k][j];
                }
            }
        }
}

    Matrix Matrix::matrixBlockMultiply(Matrix m1, Matrix m2, int number){
        std::vector<std::vector<double>> res(5, std::vector<double>(5,0));
        Matrix result = Matrix(res);
        std::vector<std::thread> threads;
        int size = m1.getSize();
        for (int i = 0; i < size; i += number) {
            for (int j = 0; j < size; j += number){
                threads.emplace_back(blockMultiply, std::ref(m1), std::ref(m2), std::ref(result), i, j, number);
            }
        }

        for (auto& t: threads) {
            t.join();
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