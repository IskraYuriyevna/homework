#include<iostream>
#include <ostream>//输出流库
//iostream的基类是istream和ostream
//ostream的基类是ios
using namespace std;

class Vector_2d{
public:
    Vector_2d(double x=0,double y=0.)//构造函数
    {
        x_ = x;y_ = y;
    }
    void print(const char* str) const;//打印函数

    //运算符重载声明
    //运算符重载的定义为 ReturnType operator@(const T1& a, const T2& b);
    //其中@是运算符，成员函数的第一个参数默认为this,非成员函数的第一个参数需要显式声明
    Vector_2d operator+(const Vector_2d& op) const;//加法
    Vector_2d operator-(const Vector_2d& op) const;//减法
    //{return Vector_2d(x_ - op.x_,y_ - op.y_);}
    const Vector_2d& operator=(const Vector_2d& op);//赋值
    const Vector_2d& operator+=(const Vector_2d& op);//加赋值
    Vector_2d operator*(double a)const;//点乘/标量乘
    double& operator[](int index);//下标操作符
    const Vector_2d& operator++();//++u前置自增
    Vector_2d operator++(int);//u++后置自增

    //友元函数的声明，友元函数可以允许非成员函数访问私有成员
    //输入输出流的重载，需要以友元函数的形式进行，因为流对象需要为左操作数，而成员函数的重载要求第一个函数必须是类对象，不符合习惯
    //由于成员函数默认包含this作为左操作数，所以对称操作必须以友元函数声明
    friend Vector_2d operator*(double a,const Vector_2d& op);//友元的标量乘
    friend ostream& operator<<(ostream& os, const Vector_2d& op);//输出流重载
    friend istream& operator>>(istream& is, Vector_2d& op);//输入流重载

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
