#ifndef LINEARSHAPE_H
#define LINEARSHAPE_H

#include "ArraySequence.h"
#include "Complex.h"
#include "Abs.h"

template <typename T>
class LinearShape {
private:
    MutableArraySequence<T> *data;
public:
    LinearShape() {
        this->data = new MutableArraySequence<T>;
    }
    explicit LinearShape(int count) {
        this->data = new MutableArraySequence<T>(count);
    }
    LinearShape(T *items, int count) {
        this->data = new MutableArraySequence<T>(items, count);
    }
    LinearShape(const LinearShape<T> &linear_shape) {
        this->data = new MutableArraySequence<T>(linear_shape.data->GetLength());
        for (int i = 0; i < linear_shape.data->GetLength(); i++)
        {
            this->data->Append(linear_shape.data->Get(i));
        }
    }

    T Get(int index) const {
        return this->data->Get(index);
    }
    int GetLength() const {
        return this->data->GetLength();
    }

    LinearShape<T> *linear_shapeSum(const LinearShape<T> &linear_shape) {
        if (this->GetLength() != linear_shape.GetLength())
        {
            throw std::invalid_argument("different sizes");
        }
        LinearShape<T> *Result = new LinearShape<T>(this->GetLength());
        for (int i = 0; i < this->GetLength(); i++)
        {
            Result->data->Swap(this->Get(i) + linear_shape.Get(i), i);
        }
        return Result;
    }
    LinearShape<T> *linear_shapeDif(const LinearShape<T> &linear_shape) {
        if (this->GetLength() != linear_shape.GetLength())
        {
            throw std::invalid_argument("different sizes");
        }
        LinearShape<T> *Result = new LinearShape<T>(this->GetLength());
        for (int i = 0; i < this->GetLength(); i++)
        {
            Result->data->Swap(this->Get(i) - linear_shape.Get(i), i);
        }
        return Result;
    }
    LinearShape<T> *linear_shapeMultiOnScalar(const T scalar) {
        LinearShape<T> *Result = new LinearShape<T>(this->GetLength());
        for (int i = 0; i < this->GetLength(); i++) {
            Result->data->Swap(this->Get(i) * scalar,i);
        }
        return Result;
    }
    int linear_shapeCalculating(int *items, int length) const {
        if (length != this->GetLength()) {
            throw std::invalid_argument("wrong size");
        }
        int Result = 0;
        for (int i = 0; i < this->GetLength(); i++) {
            Result += this->Get(i) * items[i];
        }
        return Result;
    }
    complex linear_shapeCalculating(complex *items, int length) const {
        if (length != this->GetLength()) {
            throw std::invalid_argument("wrong size");
        }
        complex Result (0, 0);
        for (int i = 0; i < this->GetLength(); i++) {
            Result += this->Get(i) * items[i];
        }
        return Result;
    }

    ~LinearShape() {
        delete data;
    }
    LinearShape<T> *operator+(const LinearShape<T> &other) {
        LinearShape <T> *Res = this->linear_shapeSum(other);
        return Res;
    }
    LinearShape<T> *operator-(const LinearShape<T> &other) {
        LinearShape <T> *Res = this->linear_shapeDif(other);
        return Res;
    }
    LinearShape<T> *operator*(const T &scalar) {
        LinearShape<T> *Res = this->linear_shapeMultiOnScalar(scalar);
        return Res;
    }
    LinearShape operator=(LinearShape<T> &linear_shapeSum){
        LinearShape<T> Result = new LinearShape<T>(linear_shapeSum);
        return Result;
    }
};

void LinearShapeShow(const LinearShape<int> &linear_shape) {
    std::cout << "L(";
    for (int i = 0; i < linear_shape.GetLength()-1; i++) {
        std::cout << "x" << i+1 << ",";
    }
    std::cout << "x" << linear_shape.GetLength() << ") =";
    if (linear_shape.Get(0) > 0 || linear_shape.Get(0) < 0) {
        std::cout << " " << linear_shape.Get(0) << "x1";
    }
    for (int i = 1; i < linear_shape.GetLength()-1; i++) {
        if (linear_shape.Get(i) > 0) std::cout << " + " << linear_shape.Get(i) << "x" << i+1;
        if (linear_shape.Get(i) < 0) std::cout << " - " << Abs(linear_shape.Get(i)) << "x" << i+1;
    }
    if (linear_shape.Get(linear_shape.GetLength()-1) > 0) {
        std::cout << " + " << linear_shape.Get(linear_shape.GetLength()-1)
        << "x" << linear_shape.GetLength() << std::endl;
    }
    else if (linear_shape.Get(linear_shape.GetLength()-1) < 0) {
        std::cout << " - " << Abs(linear_shape.Get(linear_shape.GetLength()-1))
        << "x" << linear_shape.GetLength() << std::endl;
    }
}
void LinearShapeShow(const LinearShape<int> *linear_shape) {
    std::cout << "L(";
    for (int i = 0; i < linear_shape->GetLength()-1; i++) {
        std::cout << "x" << i+1 << ",";
    }
    std::cout << "x" << linear_shape->GetLength() << ") = ";
    if (linear_shape->Get(0) > 0 || linear_shape->Get(0) < 0) {
        std::cout << linear_shape->Get(0) << "x1";
    }
    for (int i = 1; i < linear_shape->GetLength()-1; i++) {
        if (linear_shape->Get(i) > 0) std::cout << " + " << linear_shape->Get(i) << "x" << i+1;
        if (linear_shape->Get(i) < 0) std::cout << " - " << Abs(linear_shape->Get(i)) << "x" << i+1;
    }
    if (linear_shape->Get(linear_shape->GetLength()-1) > 0) {
        std::cout << " + " << linear_shape->Get(linear_shape->GetLength()-1)
        << "x" << linear_shape->GetLength() << std::endl;
    }
    else if (linear_shape->Get(linear_shape->GetLength()-1) < 0) {
        std::cout << " - " << Abs(linear_shape->Get(linear_shape->GetLength()-1))
        << "x" << linear_shape->GetLength() << std::endl;
    }
}


#endif //LINEARSHAPE_H
