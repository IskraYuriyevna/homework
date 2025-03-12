#include <cmath>
#include<iostream>
using namespace std;

class Complex
{
    public:
        Complex(double arg_re,double arg_im){
            cout << "Create complex number" << endl;
            re = arg_re;
            im = arg_im;
        }
        
        //如果加入关键字 explicit 会制止隐式类型转换
        //explicit 
        Complex(double arg_re){
            cout << "Create complex from double" << endl;
            re = arg_re;
            im = 0.;
        }
        Complex()
        {
            cout << "Create zero complex " << endl;
            re = 0.;
            im = 0.;
        }
        Complex(const Complex& other){
            cout << "Create copy " << endl;
            re = other.re;
            im = other.im;
        }
        void print()
        {
            cout << re << "+" << im << "i" << endl;
        }
        double modulo()
        {
            return sqrt(re*re+im*im);
        }
        double argument(){
            return atan2(im,re);
        }
        double get_re(){return re;}
        double get_im(){return im;}
        ~Complex(){ cout << "delete complex" << endl;};

    private:
        double re;
        double im;
};

double pow2(Complex* z){
    return z->get_re()*z->get_re() + z -> get_im() * z -> get_im();
}

double pow2(Complex& z){
    return z.get_re()*z.get_re() + z.get_im()*z.get_im();
}

double pow2(Complex z){
    return z.get_re()*z.get_re() + z.get_im()*z.get_im();
}

int main(){
    Complex z(3,5);//???
    Complex z1(6);
    Complex z2;
    z.print();
    z1.print();
    z2.print();
    cout << "|Z| = " << z.modulo() << endl;
    cout << "pow2(z) " << pow2(z) << endl;
    cout << "pow2(8) " << pow2(8.) << endl;//编译器会自动调用一个参数的建构函数，产生一个值为8.的Complex类
    return 0;
}