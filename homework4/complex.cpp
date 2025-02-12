#include <cmath>
#include<iostream>
using namespace std;

class Complex
{
    public:
        Complex(double arg_re,double arg_im){
            re = arg_re;
            im = arg_im;
        }
        Complex(double arg_re){
            re = arg_re;
            im = 0.;
        }
        Complex()
        {
            re = 0.;
            im = 0.;
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

    private:
        double re;
        double im;
};

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