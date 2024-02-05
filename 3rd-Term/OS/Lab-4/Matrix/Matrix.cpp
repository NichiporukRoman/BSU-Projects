#include "Matrix.h"

Matrix::Matrix(std::vector<std::vector<double >> matrix) {
    _matrix = std::move(matrix);
}

void Matrix::blockMultiply(const Matrix& m1, const Matrix& m2, Matrix& resultBlock, BufferedChannel<std::pair<int, int>>& channel, int number){
    int size = m1.getSize();
    std::pair<int, int> cords = channel.Recieve().first;
    for (int i = cords.first; i < std::min(cords.first+ number, size); ++i) {
        for (int j = cords.second; j < std::min(cords.second + number, size); ++j) {
            for (int k = 0; k < size; ++k) {
                resultBlock._matrix[i][j] += m1._matrix[i][k] * m2._matrix[k][j];
            }
        }
    }
}


Matrix Matrix::matrixBlockMultiply(Matrix m1, Matrix m2, int number, int numOfThreads){
    int size = m1.getSize();
    std::vector<std::vector<double>> res(size, std::vector<double>(size,0));
    Matrix result = Matrix(res);
    int count = 0;
    std::list<std::thread> threads;
    BufferedChannel<std::pair<int, int>> channel(pow(size/number + 1,2));
    for (int i = 0; i < size; i += number) {
        for (int j = 0; j < size; j += number){
            channel.Send(std::pair(i, j));
        }
    }
    for (int i = 0; i < size; i += number) {
        for (int j = 0; j < size; j += number){
            if (count < numOfThreads){
                threads.emplace_back(blockMultiply, std::ref(m1), std::ref(m2), std::ref(result), std::ref(channel), number);
                count++;
            } else{
                threads.front().join();
                threads.pop_front();
                threads.emplace_back(blockMultiply, std::ref(m1), std::ref(m2), std::ref(result), std::ref(channel), number);
            }
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
