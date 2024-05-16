#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>

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
    T Get(int index) const
    {
        return this->elements->Get(index);
    }
    int GetLength() const
    {
        return this->elements->GetSize();
    }
    Vector<T> *vectorSum(const Vector<T> &vec2)
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
        Vector<T> VecRes = new Vector(Present, this->GetLength());
        return VecRes;
    }
    Vector<T> *vectorMultiOnScalar(const int scalar)
    {
        T *Present = new T[this->GetLength()];

        for (int i = 0; i < this->GetLength(); i++)
        {
            Present[i] = this->Get(i) * scalar;
        }
        Vector<T> *vecRes = new Vector(Present, this->GetLength());
        return vecRes;
    }
    static int vectorNorm(const Vector<T> &vec)
    {
        int Present = 0;
        for (int i = 0; i < vec.GetLength(); i++)
        {
            Present += vec.Get(i)*vec.Get(i);
        }
        int VecNorm = sqrt(Present);
        return VecNorm;
    }
    Vector<T> *vectorMulti(const Vector<T> &vec2)
    {
        if (this->GetLength() != vec2.GetLength())
        {
            throw std::invalid_argument("different sizes");
        }
        T *Present = new T[this->GetLength()];
        for (int i = 0; i < this->GetLength(); i++)
        {
            Present[i] = this->Get(i) * vec2.Get(i);
        }
        Vector<T> *vecRes = new Vector(Present, this->GetLength());
        return vecRes;
    }
    virtual ~Vector()
    {
        delete elements;
    }
    Vector<T> *operator+(const Vector<T> &vec)
    {
        Vector<T> *vecRes = this->vectorSum(vec);
        return vecRes;
    }
    Vector<T> *operator*(const Vector<T> &vec)
    {
        Vector<T> *vecRes = this->vectorMulti(vec);
        return vecRes;
    }
    Vector<T> *operator*(const T item)
    {
        Vector<T> *vecRes = this->vectorMultiOnScalar(item);
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
template <typename T> void VectorShow(Vector<T> &vec)
{
    for (int i = 0; i < vec.GetLength(); i++)
    {
        std::cout << vec.Get(i) << " ";
    }
    std::cout << std::endl;
}
template <typename T> void VectorShow(Vector<T> *vec)
{
    for (int i = 0; i < vec->GetLength(); i++)
    {
        std::cout << vec->Get(i) << " ";
    }
    std::cout << std::endl;
}

#endif //VECTOR_H
