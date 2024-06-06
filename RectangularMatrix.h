#ifndef RECTANGULARMATRIX_H
#define RECTANGULARMATRIX_H

#include <concepts>
#include "Abs.h"
#include "ArraySequence.h"

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

template <Arithmetic T>
class Matrix: public IMatrix<T> {
private:
    MutableArraySequence<MutableArraySequence<T> *> data;
    size_t Rows;
    size_t Cols;
public:
    Matrix(size_t rows, size_t cols) : IMatrix<T>(rows, cols), Rows(rows), Cols(cols) {
        initialize(rows, cols);
    }

    explicit Matrix(const T* array, size_t rows, size_t cols) : IMatrix<T>(array, rows, cols), Rows(rows), Cols(cols) {
        initialize(array, rows, cols);
    }

    Matrix(const Matrix<T>& matrix) : IMatrix<T>(matrix), Rows(matrix.Rows), Cols(matrix.Cols) {
        initialize(matrix);
    }

    ~Matrix() override {
        for (int i = 0; i < Rows; i++) {
            delete data.Get(i);
        }
        Rows = 0;
        Cols = 0;
    }

    void initialize(size_t rows, size_t cols) {
        if (rows == 0 || cols == 0) {
            throw std::invalid_argument("invalid size");
        }
        for (size_t i = 0; i < rows; ++i) {
            MutableArraySequence<T> *row = new MutableArraySequence<T>(cols);
            data.Append(row);
        }
    }

    void initialize(const T* array, size_t rows, size_t cols) {
        if (rows == 0 || cols == 0) {
            throw std::invalid_argument("invalid size");
        }
        for (size_t i = 0; i < rows; ++i) {
            MutableArraySequence<T> *row = new MutableArraySequence<T>;
            for (size_t j = 0; j < cols; ++j) {
                row->Append(array[i * cols + j]);
            }
            data.Append(row);
        }
    }

    void initialize(const Matrix<T>& matrix) {
        for (size_t i = 0; i < matrix.Rows; ++i) {
            MutableArraySequence<T> *row = new MutableArraySequence<T>;
            for (size_t j = 0; j < matrix.Cols; ++j) {
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
    size_t getRows() const {
        return Rows;
    }

    size_t getCols() const {
        return Cols;
    }

    Matrix <T> *Sum(const Matrix<T> &matrix) {
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
    Matrix <T> *ScalarMultiplication(const T &scalar) {
        Matrix<T> *result = new Matrix<T>(Rows, Cols);
        for (int i = 0; i < Rows; ++i) {
            for (int j = 0; j < Cols; ++j) {
                result->data.Get(i)->Swap((*this)(i, j) * scalar, j);
            }
        }
        return result;
    }
    double GetNorm() const {
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
        Matrix <T> *Res = this->Sum(other);
        return Res;
    }
    Matrix<T> *operator*(const T &scalar) {
        Matrix<T> *Res = this->ScalarMultiplication(scalar);
        return Res;
    }
};



#endif //RECTANGULARMATRIX_H

/*#ifndef RECTANGULARMATRIX_H
#define RECTANGULARMATRIX_H

#include <concepts>
#include <utility> 
#include "Abs.h"
#include "ArraySequence.h"

template <typename T>
concept Arithmetic = requires(T a, T b) {
    { a + b } -> std::same_as<T>;
    { a * b } -> std::same_as<T>;
    { a - b } -> std::same_as<T>;
    { a / b } -> std::same_as<T>;
};

template <typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;

    constexpr Pair() : first(), second() {}

    constexpr Pair(const T1& a, const T2& b) : first(a), second(b) {}

    constexpr Pair(const Pair& other) : first(other.first), second(other.second) {}

    constexpr Pair(Pair&& other) noexcept : first(std::move(other.first)), second(std::move(other.second)) {}

    T1 GetFirst() const {
        return first;
    }
    T2 GetSecond() {
        return second;
    }

    Pair& operator=(const Pair& other) {
        if (this != &other) {
            first = other.first;
            second = other.second;
        }
        return *this;
    }

    Pair& operator=(Pair&& other) noexcept {
        if (this != &other) {
            first = std::move(other.first);
            second = std::move(other.second);
        }
        return *this;
    }

    constexpr bool operator==(const Pair& other) const {
        return first == other.first && second == other.second;
    }

    constexpr bool operator!=(const Pair& other) const {
        return !(*this == other);
    }
};

template <Arithmetic T, Pair <const size_t &, const size_t &> size>
class Matrix {
private:
    MutableArraySequence<MutableArraySequence<T> *> data;
    static const size_t Rows = size.GetFirst();
    static const size_t Cols = size.second;
public:
    Matrix() {
        if (Rows == 0 || Cols == 0) {
            throw std::invalid_argument("invalid size");
        }
        for (int i = 0; i < Rows; ++i) {
            MutableArraySequence<T> *row = new MutableArraySequence<T>(Cols);
            data.Append(row);
        }
    }
    explicit Matrix(const T *array) {
        if (Rows == 0 || Cols == 0) {
            throw std::invalid_argument("invalid size");
        }
        for ( int i = 0; i < Rows; ++i) {
            MutableArraySequence<T> *row = new MutableArraySequence<T>;
            for ( int j = 0; j < Cols; ++j) {
                row->Append(array[i * Cols + j]);
            }
            data.Append(row);
        }
    }
    Matrix(const Matrix<T, size> &matrix) {
        if (matrix.getRows() != Rows || matrix.getCols() != Cols) {
            throw std::invalid_argument("invalid size");
        }
        for ( int i = 0; i < Rows; ++i) {
            MutableArraySequence<T> *row = new MutableArraySequence<T>;
            for ( int j = 0; j < Cols; ++j) {
                row->Append(matrix(i, j));
            }
            data.Append(row);
        }
    }
    ~Matrix() {
        for ( int i = 0; i < Rows; i++) {
            delete data.Get(i);
        }
    }

    T Get(size_t row, size_t col) const {
        if (row >= Rows || col >= Cols) {
            throw std::invalid_argument("wrong size");
        }
        return data.Get(row)->Get(col);
    }

    static  int getRows() {
        return Rows;
    }

    static  int getCols() {
        return Cols;
    }

    Matrix <T, size> *Sum(const Matrix<T, size> &matrix) const {
        Matrix<T, size> *result = new Matrix<T, size>();
        for ( int i = 0; i < Rows; ++i) {
            for ( int j = 0; j < Cols; ++j) {
                result->data.Get(i)->Swap((*this)(i, j) + matrix(i, j), j);
            }
        }
        return result;
    }
    Matrix <T, size> *ScalarMultiplication(const T &scalar) const {
        Matrix<T, size> *result = new Matrix<T, size>();
        for ( int i = 0; i < Rows; ++i) {
            for ( int j = 0; j < Cols; ++j) {
                result->data.Get(i)->Swap((*this)(i, j) * scalar, j);
            }
        }
        return result;
    }
    double GetNorm() const {
        double sum = 0;
        for ( int i = 0; i < Rows; ++i) {
            for ( int j = 0; j < Cols; ++j) {
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
        for ( int j = 0; j < Cols; ++j) {
            T temp = (*this)(row1, j);
            this->data.Get(row1)->Swap((*this)(row2, j), j);
            this->data.Get(row2)->Swap(temp, j);
        }
    }
    void multiplyRow(size_t row, const T& scalar) {
        if (row >= Rows) {
            throw std::invalid_argument("wrong size");
        }
        for ( int j = 0; j < Cols; ++j) {
            this->data.Get(row)->Swap((*this)(row, j) * scalar, j);
        }
    }
    void addRows(size_t row1, size_t row2, const T& scalar) {
        if (row1 >= Rows || row2 >= Rows) {
            throw std::invalid_argument("wrong size");
        }
        for ( int j = 0; j < Cols; ++j) {
            this->data.Get(row1)->Swap((*this)(row1, j) + (*this)(row2, j) * scalar, j);
        }
    }
    void swapCols(size_t col1, size_t col2) {
        if (col1 >= Cols || col2 >= Cols) {
            throw std::invalid_argument("wrong size");
        }
        for ( int i = 0; i < Rows; ++i) {
            T temp = (*this)(i, col1);
            this->data.Get(i)->Swap((*this)(i, col2), col1);
            this->data.Get(i)->Swap(temp, col2);
        }
    }
    void multiplyCol(size_t col, const T& scalar) {
        if (col >= Cols) {
            throw std::invalid_argument("wrong size");
        }
        for ( int i = 0; i < Rows; ++i) {
            this->data.Get(i)->Swap((*this)(i, col) * scalar, col);
        }
    }
    void addCols(size_t col1, size_t col2, const T& scalar) {
        if (col1 >= Cols || col2 >= Cols) {
            throw std::invalid_argument("wrong size");
        }
        for ( int i = 0; i < Rows; ++i) {
            this->data.Get(i)->Swap((*this)(i, col1) + (*this)(i, col2) * scalar, col1);
        }
    }

    T operator()(size_t row, size_t col) const {
        if (row >= Rows || col >= Cols) {
            throw std::invalid_argument("wrong size");
        }
        return data.Get(row)->Get(col);
    }
    Matrix<T, size> *operator+(const Matrix<T, size> &other) const {
        return this->Sum(other);
    }
    Matrix<T, size> *operator*(const T &scalar) const {
        return this->ScalarMultiplication(scalar);
    }
};

#endif //RECTANGULARMATRIX_H*/
