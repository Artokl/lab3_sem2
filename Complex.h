#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class complex
{
private:
      double Re;
      double Im;
public:
    complex()
    {
        Re = 0;
        Im = 0;
    }
    complex(double Real, double Image)
    {
        Re = Real;
        Im = Image;
    }
    complex(const complex &CopyItem)
    {
        Re = CopyItem.Re;
        Im = CopyItem.Im;
    }
    double GetRe() const
    {
        return Re;
    }
    double GetIm() const
    {
        return Im;
    }
    complex operator+(complex item) const
    {
        double Re = this->Re + item.Re;
        double Im = this->Im + item.Im;
        complex result(Re, Im);
        return result;
    }
    complex operator-(complex item) const
    {
        double Re = this->Re - item.Re;
        double Im = this->Im - item.Im;
        complex result(Re, Im);
        return result;
    }
    complex operator*(complex item) const
    {
        double Re = this->Re;
        double Im = this->Im;
        double ReRes = Re * item.Re - Im * item.Im;
        double ImRes = Re * item.Im + Im * item.Re;
        complex result(ReRes, ImRes);
        return result;
    }
    complex operator/(complex item) const
    {
        double Re = this->Re;
        double Im = this->Im;
        double ReRes = (Re * item.Re + Im * item.Im) / (item.Re * item.Re + item.Im * item.Im);
        double ImRes = (Im * item.Re - Re * item.Im) / (item.Re * item.Re + item.Im * item.Im);
        complex result(ReRes, ImRes);
        return result;
    }
    friend std::istream &operator>>(std::istream &in, complex &item)
    {
        std::cout << "Enter Re part: ";
        in >> item.Re;
        std::cout << "Enter Im part: ";
        in >> item.Im;
        return in;
    }
    friend std::ostream &operator<<(std::ostream &out, const complex &item)
    {
        if (item.Im < 0)
        {
            return out << item.Re << "-i*" << item.Im << " ";
        }
        else
        {
            return out << item.Re << "+i*" << item.Im << " ";
        }
    }
    complex &operator+=(complex item)
    {
        this->Re += item.Re;
        this->Im += item.Im;
        return *this;
    }
    complex &operator-=(complex item)
    {
        double Re = this->Re;
        double Im = this->Im;
        this->Re = Re - item.Re;
        this->Im = Im - item.Im;
        return *this;
    }
    complex &operator*=(complex item)
    {
        double Re = this->Re;
        double Im = this->Im;
        this->Re = Re * item.Re - Im * item.Im;
        this->Im = Re * item.Im + Im * item.Re;
        return *this;
    }
    complex &operator/=(complex item)
    {
        double Re = this->Re;
        double Im = this->Im;
        this->Re = (Re * item.Re + Im * item.Im) / (item.Re * item.Re + item.Im * item.Im);
        this->Im = (Im * item.Re - Re * item.Im) / (item.Re * item.Re + item.Im * item.Im);
        return *this;
    }
    bool operator==(complex item) const
    {
        if (this->Re == item.Re && this->Im == item.Im)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator!=(complex item) const
    {
        if (this->Re != item.Re || this->Im != item.Im)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

#endif //COMPLEX_H
