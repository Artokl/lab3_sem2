#ifndef COMPLEX_H
#define COMPLEX_H

#include <complex>
#include <iostream>

class complex {
private:
    double Re;
    double Im;
public:
    complex()
    {
        Re = 0;
        Im = 0;
    }
    complex(const double& Real, const double& Image)
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
    double abs() const
    {
        return sqrt(Re * Re + Im * Im);
    }
    complex operator+(const complex& item) const
    {
        return {this->Re + item.Re, this->Im + item.Im};
    }
    complex operator-(const complex& item) const
    {
        return {this->Re - item.Re, this->Im - item.Im};
    }
    complex operator*(const complex& item) const
    {
        return {this->Re * item.Re - this->Im * item.Im,
            this->Re * item.Im + this->Im * item.Re};
    }
    complex operator/(const complex& item) const
    {
        return {(this->Re * item.Re + this->Im * item.Im) / (item.Re * item.Re + item.Im * item.Im),
            (this->Im * item.Re - this->Re * item.Im) / (item.Re * item.Re + item.Im * item.Im)};
    }
    friend std::istream &operator>>(std::istream &in, complex &item)
    {
        std::cout << "Enter Re part:\n";
        in >> item.Re;
        std::cout << "Enter Im part:\n";
        in >> item.Im;
        return in;
    }
    friend std::ostream &operator<<(std::ostream &out, const complex &item)
    {
        if (item.Im < 0)
        {
            return out << item.Re << "-i*" << item.Im*-1;
        }
        else
        {
            return out << item.Re << "+i*" << item.Im;
        }
    }
    complex &operator+=(const complex& item)
    {
        this->Re += item.Re;
        this->Im += item.Im;
        return *this;
    }
    complex &operator-=(const complex& item)
    {
        this->Re -= item.Re;
        this->Im -= item.Im;
        return *this;
    }
    complex &operator*=(const complex& item)
    {
        this->Re = this->Re * item.Re - this->Im * item.Im;
        this->Im = this->Re * item.Im + this->Im * item.Re;
        return *this;
    }
    complex &operator/=(const complex& item)
    {
        this->Re = (this->Re * item.Re + this->Im * item.Im) / (item.Re * item.Re + item.Im * item.Im);
        this->Im = (this->Im * item.Re - this->Re * item.Im) / (item.Re * item.Re + item.Im * item.Im);
        return *this;
    }
    bool operator==(const complex& item) const
    {
        if (this->Re == item.Re && this->Im == item.Im) return true;
        else return false;
    }
    bool operator!=(const complex& item) const
    {
        if (this->Re != item.Re || this->Im != item.Im) return true;
        else return false;
    }
};

#endif //COMPLEX_H
