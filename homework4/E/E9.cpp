#include<iostream>
#include <ostream>
using namespace std;

class Vector_2d{
public:
    Vector_2d(double x=0,double y=0.)
    {
        x_ = x;y_ = y;
    }
    void print(const char* str) const;
    Vector_2d operator+(const Vector_2d& op) const;
    Vector_2d operator-(const Vector_2d& op) const;
    //{return Vector_2d(x_ - op.x_,y_ - op.y_);}
    const Vector_2d& operator=(const Vector_2d& op);
    const Vector_2d& operator+=(const Vector_2d& op);
    Vector_2d operator*(double a)const;

    double& operator[](int index);
    const Vector_2d& operator++();//++u
    Vector_2d operator++(int);//u++
    friend Vector_2d operator*(double a,const Vector_2d& op);
    friend ostream& operator<<(ostream& os, const Vector_2d& op);
    friend istream& operator>>(istream& is, Vector_2d& op);
private:
    double x_,y_;
};

Vector_2d Vector_2d::operator++(int) //u++
{
    Vector_2d tmp(x_,y_);
    x_ = x_+1.;
    y_ = y_+1;
    return tmp;
}

const Vector_2d& Vector_2d::operator++() //++u
{
    x_ = x_+1.;
    y_ = y_+1.;
    return *this;
}

istream& operator>>(istream& is,Vector_2d& op)
{
    is >> op.x_ >> op.y_;
    return is;
}

ostream& operator<<(ostream& os,const Vector_2d& op)
{
    os << "(" << op.x_ << "," << op.y_ << ")";
    return os;
}

double& Vector_2d::operator[](int index){
    if(index==0)
        return x_;
    else
        return y_;
}

Vector_2d operator*(double a,const Vector_2d& op)
{
    return Vector_2d(a*op.x_,a*op.y_);
}

Vector_2d Vector_2d::operator*(double a) const
{
    return Vector_2d(a*x_,a*y_);
}

const Vector_2d& Vector_2d::operator+=(const Vector_2d& op)
{
    x_ += op.x_;
    y_ += op.y_;
    return *this;
}

const Vector_2d& Vector_2d::operator=(const Vector_2d& op)
{
    x_ = op.x_;
    y_ = op.y_;
    return *this;
}

Vector_2d Vector_2d::operator+(const Vector_2d& op) const
{
    Vector_2d tmp;
    tmp.x_ = x_ + op.x_;
    tmp.y_ = y_ + op.y_;
    return tmp;
}

Vector_2d Vector_2d::operator-(const Vector_2d& op)const
{
    return Vector_2d(x_-op.x_,y_-op.y_);
}

void Vector_2d::print(const char* str=0) const
{
    if(str)
        cout << str << " = ";
    cout << "(" << x_ << "," << y_ << ")" << endl;
}
