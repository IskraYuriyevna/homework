#include <cmath>
#include<iostream>
using namespace std;

class Complex
{
    public:
        Complex(double arg_re=0,double arg_im=0){
            //cout << "create 2" << endl;
            re = arg_re;
            im = arg_im;
        }
        Complex(const Complex & ob){
            //cout <<"copy" << endl;
            re = ob.re;
            im = ob.im;
        }
        /*
        Complex(double arg_re){

            re = arg_re;
            im = 0.;
        }
        Complex()
        {
            re = 0.;
            im = 0.;
        }
        */
        void print() const
        {
            cout << re << "+" << im << "i" << endl;
        }
        double modulo() const
        {
            return sqrt(re*re+im*im);
        }
        double argument() const{
            return atan2(im,re);
        }
        double get_re() const {return re;}
        double get_im() const {return im;}
        ~Complex(){
            //cout << "delete" << endl;
        }
    private:
        double re;
        double im;
};

double pow2(Complex * z){
    return z->get_re()* z->get_re() + z->get_im() * z->get_im();
}

double pow2(const Complex & z){
    return z.get_re()*z.get_re() + z.get_im()*z.get_im();
}

/*
double pow4(Complex z){
    return z.get_re()*z.get_re()+z.get_im()*z.get_im();
}
*/