#include<iostream>
using namespace std;

template<class T>//模板定义泛型类 
class Vector_2d
{
    public:
        Vector_2d(T x = 0,T y = 0): x_(x),y_(y){}//初始化成员向量
        void print() const;
        T max_norm() const {return abs(x_)>abs(y_)?abs(x_):abs(y_);}
        const Vector_2d<T>& operator = (const Vector_2d<T>& op);
        Vector_2d<T> operator*(T a) const
        {
            return Vector_2d<T>(a*x_ , a*y_);
        }
        template<typename V>
        friend Vector_2d<V> operator+(const Vector_2d<V>& op1,const Vector_2d<V>& op2);
        //模板友元函数
    private:
        T x_,y_;
};

template<typename T>
Vector_2d<T> operator+(const Vector_2d<T>& op1,const Vector_2d<T>& op2)
{
    Vector_2d<T> tmp;
    tmp.x_ = op1.x_ + op2.x_;
    tmp.y_ = op1.y_ + op2.y_;
    return tmp;
}

template<typename T>
const Vector_2d<T>& Vector_2d<T>::operator=(const Vector_2d<T>& op)
//赋值运算符重载
{
    x_ = op.x_;
    y_ = op.y_;
    return *this;
}

template <typename D>
void Vector_2d<D>::print() const
{
    cout << "(" << x_ << "," <<y_ << ")" << endl;
    //另外，即使是const成员函数也可以修改mutable变量，但mutable只能用于类成员
    //注意const函数和返回const变量的函数的区别，一个是不改变*this的变量，一个是返回不可改变的变量
}