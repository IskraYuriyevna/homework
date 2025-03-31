#include<iostream>
using namespace std;

template<typename T , typename D>
class Vector_2d
{
    public:
        Vector_2d(T x = 0,D y = 0) : x_(x),y_(y) {}
        void print() const;
        T get_x() const {return x_;}
        D get_y() const {return y_;}
        const Vector_2d<T, D>& operator=(const Vector_2d<T,D>& op);
        template<typename U ,typename V>
        friend Vector_2d<U,V> operator+(const Vector_2d<U,V>& op1,const Vector_2d<U,V>& op2);
    private:
        T x_;
        D y_;
};

template<typename U ,typename V>
Vector_2d<U,V> operator+(const Vector_2d<U,V>& op1,const Vector_2d<U, V>& op2)
{
    Vector_2d<U,V> tmp;
    tmp.x_ = op1.x_ + op2.x_;
    tmp.y_ = op1.y_ + op2.y_;
    return tmp;
}

template <typename N,typename M>
const Vector_2d<N, M>& Vector_2d<N,M>::operator=(const Vector_2d<N,M>& op)
{
    x_ = op.x_;
    y_ = op.y_;
    return *this;
}

template <typename T,typename D>
void Vector_2d<T, D>::print() const
{
    cout << "(" << x_ << "," << y_ << ")" << endl;
}

