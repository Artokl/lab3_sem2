#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>

#include "Abs.h"
#include "DynamicArray.h"

template <typename T> class Vector
{
  private:
    DynamicArray<T> *elements;
  public:
    Vector()
    {
        this->elements = new DynamicArray<T>();
    }
    Vector(T *items, int count)
    {
        this->elements = new DynamicArray<T>(items, count);
    }
    Vector(const Vector<T> &vec)
    {
        this->elements = new DynamicArray<T>(vec.GetLength());
        for (int i = 0; i < vec.GetLength(); i++)
        {
            this->elements->Set(vec.Get(i), i);
        }
    }
    ~Vector()
    {
        delete elements;
    }

    T Get(int index) const
    {
        return this->elements->Get(index);
    }
    int GetLength() const
    {
        return this->elements->GetSize();
    }

    Vector<T> Sum(const Vector<T> &vec2)
    {
        if (this->GetLength() != vec2.GetLength())
        {
            throw std::invalid_argument("different sizes");
        }
        T *Present = new T[this->GetLength()];
        for (int i = 0; i < this->GetLength(); i++)
        {
            Present[i] = this->Get(i) + vec2.Get(i);
        }
        Vector<T> VecRes = Vector(Present, this->GetLength());
        return VecRes;
    }
    Vector<T> ScalarMultiplication(T scalar)
    {
        T *Present = new T[this->GetLength()];

        for (int i = 0; i < this->GetLength(); i++)
        {
            Present[i] = this->Get(i) * scalar;
        }
        Vector<T> vecRes = Vector(Present, this->GetLength());
        return vecRes;
    }
    double GetNorm()
    {
        double Present = 0;
        for (int i = 0; i < this->GetLength(); i++)
        {
            double Now = Abs(this->Get(i));
            Present += Now * Now;
        }
        double VecNorm = sqrt(Present);
        return VecNorm;
    }
    Vector<T> Multiplication(const Vector<T> &vec2) {
        if (this->GetLength() != vec2.GetLength())
        {
            throw std::invalid_argument("different sizes");
        }
        T *Present = new T[this->GetLength()];
        for (int i = 0; i < this->GetLength(); i++)
        {
            Present[i] = this->Get(i) * vec2.Get(i);
        }
        Vector<T> vecRes = Vector(Present, this->GetLength());
        return vecRes;
    }

    Vector<T> operator+(const Vector<T> &vec)
    {
        Vector<T> vecRes = this->Sum(vec);
        return vecRes;
    }
    Vector<T> operator*(const Vector<T> &vec)
    {
        Vector<T> vecRes = this->Multiplication(vec);
        return vecRes;
    }
    Vector<T> operator*(const T item)
    {
        Vector<T> vecRes = this->ScalarMultiplication(item);
        return vecRes;
    }
    T operator[](int index)
    {
        return this->Get(index);
    }
    Vector operator=(Vector<T>& vec)
    {
        Vector<T> newVec = new Vector<T>(vec);
        return newVec;
    }
};


#endif //VECTOR_H
