#ifndef RECTANGULARMATRIX_H
#define RECTANGULARMATRIX_H

#include "ArraySequence.h"
#include "Complex.h"
#include "Abs.h"

template <typename T>
concept Arithmetic = requires(T a, T b) {
    { a + b } -> std::same_as<T>;
    { a * b } -> std::same_as<T>;
    { a - b } -> std::same_as<T>;
    { a / b } -> std::same_as<T>;
};

template <Arithmetic T>
class IMatrix {
public:
    IMatrix(size_t, size_t) {}
    IMatrix(const T*, size_t, size_t) {}
    IMatrix(const IMatrix<T>&) {}
    virtual ~IMatrix() = default;
};

template <Arithmetic T, size_t Rows, size_t Cols>
class Matrix: public IMatrix<T> {
private:
    MutableArraySequence<MutableArraySequence<T> *> data;
public:
    Matrix() : IMatrix<T>(Rows, Cols) {
        initialize();
    }

    explicit Matrix(const T* array) : IMatrix<T>(array, Rows, Cols) {
        initialize(array);
    }

    Matrix(const Matrix<T, Rows, Cols>& matrix) : IMatrix<T>(matrix) {
        initialize(matrix);
    }

    ~Matrix() override {
        for (size_t i = 0; i < Rows; i++) {
            delete data.Get(i);
        }
    }

    void initialize() {
        if (Rows == 0 || Cols == 0) {
            throw std::invalid_argument("invalid size");
        }
        for (size_t i = 0; i < Rows; ++i) {
            MutableArraySequence<T> *row = new MutableArraySequence<T>(Cols);
            data.Append(row);
        }
    }

    void initialize(const T* array) {
        if (Rows == 0 || Cols == 0) {
            throw std::invalid_argument("invalid size");
        }
        for (size_t i = 0; i < Rows; ++i) {
            MutableArraySequence<T> *row = new MutableArraySequence<T>;
            for (size_t j = 0; j < Cols; ++j) {
                row->Append(array[i * Cols + j]);
            }
            data.Append(row);
        }
    }

    void initialize(const Matrix<T, Rows, Cols>& matrix) {
        for (size_t i = 0; i < Rows; ++i) {
            MutableArraySequence<T> *row = new MutableArraySequence<T>;
            for (size_t j = 0; j < Cols; ++j) {
                row->Append(matrix(i, j));
            }
            data.Append(row);
        }
    }

    T Get(size_t row, size_t col) const {
        if (row >= Rows || col >= Cols) {
            throw std::invalid_argument("wrong size");
        }
        return data.Get(row)->Get(col);
    }

    Matrix<T, Rows, Cols> *Sum(const Matrix<T, Rows, Cols> &matrix) const {
        Matrix<T, Rows, Cols> *result = new Matrix<T, Rows, Cols>();
        for (size_t i = 0; i < Rows; ++i) {
            for (size_t j = 0; j < Cols; ++j) {
                result->data.Get(i)->Swap((*this)(i, j) + matrix(i, j), j);
            }
        }
        return result;
    }

    Matrix<T, Rows, Cols> *ScalarMultiplication(const T &scalar) const {
        Matrix<T, Rows, Cols> *result = new Matrix<T, Rows, Cols>();
        for (size_t i = 0; i < Rows; ++i) {
            for (size_t j = 0; j < Cols; ++j) {
                result->data.Get(i)->Swap((*this)(i, j) * scalar, j);
            }
        }
        return result;
    }

    double GetNorm() {
        double sum = 0;
        for (size_t i = 0; i < Rows; ++i) {
            for (size_t j = 0; j < Cols; ++j) {
                double Now = Abs((*this)(i, j));
                sum += Now * Now;
            }
        }
        return sqrt(sum);
    }

    void swapRows(size_t row1, size_t row2) {
        if (row1 >= Rows || row2 >= Rows) {
            throw std::invalid_argument("wrong size");
        }
        for (size_t j = 0; j < Cols; ++j) {
            T temp = (*this)(row1, j);
            this->data.Get(row1)->Swap((*this)(row2, j), j);
            this->data.Get(row2)->Swap(temp, j);
        }
    }

    void multiplyRow(size_t row, const T& scalar) {
        if (row >= Rows) {
            throw std::invalid_argument("wrong size");
        }
        for (size_t j = 0; j < Cols; ++j) {
            this->data.Get(row)->Swap((*this)(row, j) * scalar, j);
        }
    }

    void addRows(size_t row1, size_t row2, const T& scalar) {
        if (row1 >= Rows || row2 >= Rows) {
            throw std::invalid_argument("wrong size");
        }
        for (size_t j = 0; j < Cols; ++j) {
            this->data.Get(row1)->Swap((*this)(row1, j) + (*this)(row2, j) * scalar, j);
        }
    }

    void swapCols(size_t col1, size_t col2) {
        if (col1 >= Cols || col2 >= Cols) {
            throw std::invalid_argument("wrong size");
        }
        for (size_t i = 0; i < Rows; ++i) {
            T temp = (*this)(i, col1);
            this->data.Get(i)->Swap((*this)(i, col2), col1);
            this->data.Get(i)->Swap(temp, col2);
        }
    }

    void multiplyCol(size_t col, const T& scalar) {
        if (col >= Cols) {
            throw std::invalid_argument("wrong size");
        }
        for (size_t i = 0; i < Rows; ++i) {
            this->data.Get(i)->Swap((*this)(i, col) * scalar, col);
        }
    }

    void addCols(size_t col1, size_t col2, const T& scalar) {
        if (col1 >= Cols || col2 >= Cols) {
            throw std::invalid_argument("wrong size");
        }
        for (size_t i = 0; i < Rows; ++i) {
            this->data.Get(i)->Swap((*this)(i, col1) + (*this)(i, col2) * scalar, col1);
        }
    }

    T operator()(size_t row, size_t col) const {
        if (row >= Rows || col >= Cols) {
            throw std::invalid_argument("wrong size");
        }
        return data.Get(row)->Get(col);
    }

    Matrix<T, Rows, Cols> *operator+(const Matrix<T, Rows, Cols> &other) const {
        return this->Sum(other);
    }

    Matrix<T, Rows, Cols> *operator*(const T &scalar) const {
        return this->ScalarMultiplication(scalar);
    }
};

#endif // RECTANGULARMATRIX_H
