#ifndef LiNEARForm_H
#define LiNEARForm_H

#include "ArraySequence.h"

template <typename T>
concept Arithmetic1 = requires(T a, T b) {
    { a + b } -> std::same_as<T>;
    { a * b } -> std::same_as<T>;
    { a - b } -> std::same_as<T>;
    { a / b } -> std::same_as<T>;
    { T() } -> std::same_as<T>;
};

template <Arithmetic1 T>
class LinearForm {
private:
    MutableArraySequence<T> *data;
public:
    LinearForm() {
        this->data = new MutableArraySequence<T>;
    }
    explicit LinearForm(int count) {
        this->data = new MutableArraySequence<T>(count);
    }
    LinearForm(T *items, int count) {
        this->data = new MutableArraySequence<T>(items, count);
    }
    LinearForm(const LinearForm<T> &LinForm) {
        this->data = new MutableArraySequence<T>(LinForm.data->GetLength());
        for (int i = 0; i < LinForm.data->GetLength(); i++)
        {
            this->data->Append(LinForm.data->Get(i));
        }
    }
    ~LinearForm() {
        delete data;
    }

    T Get(int index) const {
        return this->data->Get(index);
    }
    int GetLength() const {
        return this->data->GetLength();
    }

    LinearForm<T> *Sum(const LinearForm<T> &LinForm) {
        if (this->GetLength() != LinForm.GetLength())
        {
            throw std::invalid_argument("different sizes");
        }
        LinearForm<T> *Result = new LinearForm<T>(this->GetLength());
        for (int i = 0; i < this->GetLength(); i++)
        {
            Result->data->Swap(this->Get(i) + LinForm.Get(i), i);
        }
        return Result;
    }
    LinearForm<T> *Dif(const LinearForm<T> &LinForm) {
        if (this->GetLength() != LinForm.GetLength())
        {
            throw std::invalid_argument("different sizes");
        }
        LinearForm<T> *Result = new LinearForm<T>(this->GetLength());
        for (int i = 0; i < this->GetLength(); i++)
        {
            Result->data->Swap(this->Get(i) - LinForm.Get(i), i);
        }
        return Result;
    }
    LinearForm<T> *ScalarMultiplication(const T scalar) {
        LinearForm<T> *Result = new LinearForm<T>(this->GetLength());
        for (int i = 0; i < this->GetLength(); i++) {
            Result->data->Swap(this->Get(i) * scalar,i);
        }
        return Result;
    }
    T Eval(T *items, int length) const {
        if (length != this->GetLength()) {
            throw std::invalid_argument("wrong size");
        }
        T Result{};
        for (int i = 0; i < this->GetLength(); i++) {
            Result += (*this)(i) * items[i];
        }
        return Result;
    }

    LinearForm<T> *operator+(const LinearForm<T> &other) {
        LinearForm <T> *Res = this->Sum(other);
        return Res;
    }
    LinearForm<T> *operator-(const LinearForm<T> &other) {
        LinearForm <T> *Res = this->Dif(other);
        return Res;
    }
    LinearForm<T> *operator*(const T &scalar) {
        LinearForm<T> *Res = this->ScalarMultiplication(scalar);
        return Res;
    }
    T operator()(int index) const {
        return this->data->Get(index);
    }
};



#endif //LiNEARForm_H
