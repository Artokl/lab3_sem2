#ifndef RECTANGULARMATRIX_H
#define RECTANGULARMATRIX_H

#include "ArraySequence.h"
#include "Abs.h"

template <typename T>
class Matrix {
private:
    MutableArraySequence<MutableArraySequence<T> *> data;
    unsigned int Rows;
    unsigned int Cols;
public:
    Matrix(unsigned int rows, unsigned int cols) {
        if (rows == 0 || cols == 0) {
            throw std::invalid_argument("invalid size");
        }
        this->Cols = cols;
        this->Rows = rows;
        for (int i = 0; i < Rows; ++i) {
            MutableArraySequence<T> *row = new MutableArraySequence<T> (Cols);
            data.Append(row);
        }
    }
    explicit Matrix(const T* array, unsigned int rows, unsigned int cols) {
        if (rows == 0 || cols == 0) {
            throw std::invalid_argument("invalid size");
        }
        this->Cols = cols;
        this->Rows = rows;
        for (unsigned int i = 0; i < Rows; ++i) {
            MutableArraySequence<T> *row = new MutableArraySequence<T>;
            for (int j = 0; j < Cols; ++j) {
                row->Append(array[i * Cols + j]);
            }
            data.Append(row);
        }
    }
    Matrix(const Matrix<T> &matrix): Rows(matrix.Rows), Cols(matrix.Cols) {
        for (int i = 0; i < Rows; ++i) {
            MutableArraySequence<T> *row = new MutableArraySequence<T>;
            for (int j = 0; j < Cols; ++j) {
                row->Append(matrix(i, j));
            }
            data.Append(row);
        }
    }

    T Get(int row, int col) {
        if (row >= Rows && col >= Cols) {
            throw std::invalid_argument("wrong size");
        }
        return data.Get(row)->Get(col);
    }
    unsigned int getRows() const {
        return Rows;
    }

    unsigned int getCols() const {
        return Cols;
    }

    Matrix <T> *MatrixSum(const Matrix<T> &matrix) {
        if (Rows != matrix.getRows() || Cols != matrix.getCols()) {
            throw std::invalid_argument("different sizes");
        }
        Matrix<T> *result = new Matrix<T>(Rows, Cols);
        for (int i = 0; i < Rows; ++i) {
            for (int j = 0; j < Cols; ++j) {
                result->data.Get(i)->Swap((*this)(i, j) + matrix(i, j), j);
            }
        }
        return result;
    }
    Matrix <T> *MatrixMultiOnScalar(const T &scalar) {
        Matrix<T> *result = new Matrix<T>(Rows, Cols);
        for (int i = 0; i < Rows; ++i) {
            for (int j = 0; j < Cols; ++j) {
                result->data.Get(i)->Swap((*this)(i, j) * scalar, j);
            }
        }
        return result;
    }
    double MatrixNorm() const {
        double sum = 0;
        for (int i = 0; i < Rows; ++i) {
            for (int j = 0; j < Cols; ++j) {
                double Now = Abs((*this)(i, j));
                sum += Now * Now;
            }
        }
        return sqrt(sum);
    }
    void swapRows(int row1, int row2) {
        if (row1 >= Rows && row2 >= Rows) {
            throw std::invalid_argument("wrong size");
        }
        for (int j = 0; j < Cols; ++j) {
            T temp = (*this)(row1, j);
            this->data.Get(row1)->Swap((*this)(row2, j), j);
            this->data.Get(row2)->Swap(temp, j);
        }
    }
    void multiplyRow(int row, const T& scalar) {
        if (row >= Rows) {
            throw std::invalid_argument("wrong size");
        }
        for (int j = 0; j < Cols; ++j) {
            this->data.Get(row)->Swap((*this)(row, j) * scalar, j);
        }
    }
    void addRows(int row1, int row2, const T& scalar) {
        if (row1 >= Rows && row2 >= Rows) {
            throw std::invalid_argument("wrong size");
        }
        for (int j = 0; j < Cols; ++j) {
            this->data.Get(row1)->Swap((*this)(row1, j) + (*this)(row2, j) * scalar, j);
        }
    }
    void swapCols(int col1, int col2) {
        if (col1 >= Cols && col2 >= Cols) {
            throw std::invalid_argument("wrong size");
        }
        for (int i = 0; i < Rows; ++i) {
            T temp = (*this)(i, col1);
            this->data.Get(i)->Swap((*this)(i, col2), col1);
            this->data.Get(i)->Swap(temp, col2);
        }
    }
    void multiplyCol(int col, const T& scalar) {
        if (col >= Cols) {
            throw std::invalid_argument("wrong size");
        }
        for (int i = 0; i < Rows; ++i) {
            this->data.Get(i)->Swap((*this)(i, col) * scalar, col);
        }
    }
    void addCols(int col1, int col2, const T& scalar) {
        if (col1 >= Cols && col2 >= Cols) {
            throw std::invalid_argument("wrong size");
        }
        for (int i = 0; i < Rows; ++i) {
            this->data.Get(i)->Swap((*this)(i, col1) + (*this)(i, col2) * scalar, col1);
        }
    }

    ~Matrix() {
        for (int i = 0; i < Rows; i++) {
            delete data.Get(i);
        }
        Rows = 0;
        Cols = 0;
    }

    T operator()(int row, int col) const {
        if (row >= Rows && col >= Cols) {
            throw std::invalid_argument("wrong size");
        }
        return data.Get(row)->Get(col);
    }

    T operator()(int row, int col) {
        if (row >= Rows && col >= Cols) {
            throw std::invalid_argument("wrong size");
        }
        return data.Get(row)->Get(col);
    }
    Matrix<T> *operator+(const Matrix<T> &other) {
        Matrix <T> *Res = this->MatrixSum(other);
        return Res;
    }

    Matrix<T> *operator*(const T &scalar) {
        Matrix<T> *Res = this->MatrixMultiOnScalar(scalar);
        return Res;
    }
    Matrix operator=(Matrix<T> &matrix) {
        Matrix <T> Res = new Matrix<T>(matrix);
        return Res;
    }
};

template <typename T> void MatrixShow(Matrix<T> &matrix) {
    for (int i = 0; i < matrix.getRows(); ++i) {
        for (int j = 0; j < matrix.getCols(); ++j) {
            std::cout << (matrix)(i, j) << " ";
        }
        std::cout << std::endl;
    }
}
template <typename T> void MatrixShow(Matrix<T> *matrix) {
    for (int i = 0; i < matrix->getRows(); ++i) {
        for (int j = 0; j < matrix->getCols(); ++j) {
            std::cout << (*matrix)(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

#endif //RECTANGULARMATRIX_H