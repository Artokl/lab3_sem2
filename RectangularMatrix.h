#ifndef RECTANGULARMATRIX_H
#define RECTANGULARMATRIX_H

#ifndef MATRIX_H
#define MATRIX_H

#include <cassert>
#include "ArraySequence.h"
#include "Abs.h"

template <typename T, unsigned int Rows, unsigned int Cols>
class Matrix {
private:
    MutableArraySequence<MutableArraySequence<T>> data;

public:
    Matrix() {
        for (int i = 0; i < Rows; ++i) {
            MutableArraySequence<T> row(Cols);
            data.Append(row);
        }
    }

    explicit Matrix(const T* array) {
        for (unsigned int i = 0; i < Rows; ++i) {
            MutableArraySequence<T> row;
            for (unsigned int j = 0; j < Cols; ++j) {
                row.Append(array[i * Cols + j]);
            }
            data.Append(row);
        }
    }

    T operator()(int row, int col) const {
        assert(row < Rows && col < Cols);
        return data.Get(row).Get(col);
    }

    T operator()(int row, int col) {
        assert(row < Rows && col < Cols);
        return data.Get(row).Get(col);
    }
    T Get(int row, int col) {
        assert(row < Rows && col < Cols);
        return data.Get(row).Get(col);
    }
    static int getRows() {
        return Rows;
    }

    static int getCols() {
        return Cols;
    }

    Matrix <T, Rows, Cols> MatrixSum(const Matrix<T, Rows, Cols> &matrix) {
        if (Rows != matrix.getRows() || Cols != matrix.getCols()) {
            throw std::invalid_argument("different sizes");
        }
        Matrix<T, Rows, Cols> result;
        for (int i = 0; i < Rows; ++i) {
            for (int j = 0; j < Cols; ++j) {
                result.data.Append((*this)(i, j) + matrix(i, j));
            }
        }
        return result;
    }

    Matrix <T, Rows, Cols> MatrixMultiOnScalar(const T &scalar) {
        Matrix<T, Rows, Cols> result;
        for (int i = 0; i < Rows; ++i) {
            for (int j = 0; j < Cols; ++j) {
                result(i, j) = (*this)(i, j) * scalar;
            }
        }
        return result;
    }

    Matrix<T, Rows, Cols> *operator+(const Matrix<T, Rows, Cols> &other) const {
        Matrix <T, Rows, Cols> *Res = this->MatrixSum(other);
        return Res;
    }

    Matrix<T, Rows, Cols> *operator*(const T &scalar) const {
        Matrix<T, Rows, Cols> *Res = this->MatrixMultiOnScalar(scalar);
        return Res;
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

    // Elementary row operations
    void swapRows(int row1, int row2) {
        assert(row1 < Rows && row2 < Rows);
        for (int j = 0; j < Cols; ++j) {
            std::swap((*this)(row1, j), (*this)(row2, j));
        }
    }

    void multiplyRow(int row, const T& scalar) {
        assert(row < Rows);
        for (int j = 0; j < Cols; ++j) {
            (*this)(row, j) *= scalar;
        }
    }

    void addRows(int row1, int row2, const T& scalar = T(1)) {
        assert(row1 < Rows && row2 < Rows);
        for (int j = 0; j < Cols; ++j) {
            (*this)(row1, j) += (*this)(row2, j) * scalar;
        }
    }

    // Elementary column operations
    void swapCols(int col1, int col2) {
        assert(col1 < Cols && col2 < Cols);
        for (int i = 0; i < Rows; ++i) {
            std::swap((*this)(i, col1), (*this)(i, col2));
        }
    }

    void multiplyCol(int col, const T& scalar) {
        assert(col < Cols);
        for (int i = 0; i < Rows; ++i) {
            (*this)(i, col) *= scalar;
        }
    }

    void addCols(int col1, int col2, const T& scalar = T(1)) {
        assert(col1 < Cols && col2 < Cols);
        for (int i = 0; i < Rows; ++i) {
            (*this)(i, col1) += (*this)(i, col2) * scalar;
        }
    }
};

template <typename T, unsigned int Rows, unsigned int Cols> void MatrixShow(Matrix<T, Rows, Cols> &matrix) {
    for (int i = 0; i < Rows; ++i) {
        for (int j = 0; j < Cols; ++j) {
            std::cout << (matrix)(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

#endif // MATRIX_H
#endif //RECTANGULARMATRIX_H
