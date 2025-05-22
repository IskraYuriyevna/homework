#include <cmath>
#include<iostream>
#include <ostream>
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

        Complex operator+(const Complex& op)const;
        Complex operator+(double i)const;
        friend Complex operator+(double i,const Complex& op);
        
        Complex operator-(const Complex& op)const;
        Complex operator-(double i)const;
        friend Complex operator-(double i,const Complex& op);
        
        Complex operator*(const Complex& op)const;
        Complex operator*(double i)const;
        friend Complex operator*(double i,const Complex &op);
        
        const Complex& operator=(const Complex& op);
        bool operator==(const Complex &op)const;
        friend ostream& operator<<(ostream& os,const Complex& op);

    private:
        double re;
        double im;
};

double pow2(Complex z){
    return z.get_re()*z.get_re() + z.get_im()*z.get_im();
}

Complex Complex::operator+(const Complex& op)const 
{ return Complex(re+op.re,im+op.im); }
Complex Complex::operator+(double i)const 
{ return Complex(re+i,im); }
Complex operator+(double i,const Complex& op)
{ return Complex(i+op.re,op.im); }

Complex Complex::operator-(const Complex& op)const 
{ return Complex(re-op.re,im-op.im); }
Complex Complex::operator-(double i)const
{ return Complex(re-i,im); }
Complex operator-(double i,const Complex& op)
{ return Complex(i-op.re,op.im); }

Complex Complex::operator*(const Complex& op)const
{ return Complex(re*op.re-im*op.im,re*op.im+im*op.re); }
Complex Complex::operator*(double i)const
{ return Complex(re*i,im*i); }
Complex operator*(double i,const Complex& op)
{ return Complex(op.re*i,op.im*i); }

const Complex & Complex::operator=(const Complex& op)
{ 
    re=op.re; im=op.im; 
    return *this; 
}
bool Complex::operator==(const Complex& op)const{
    if(re==op.re && im==op.im){
        return true;
    }else{
        return false;
    }
}

ostream& operator<<(ostream & os,const Complex & op){
    if(op.re==0 && op.im==0){ os << 0; return os; }
    else if(op.re==0 && op.im!=0){
        if(op.im==1){ os << "i"; return os; }
        else if(op.im== -1){ os << "-i"; return os; }
        else{os << op.im << "i"; return os; }
    }
    else if(op.re!=0 && op.im==0){ os << op.re; return os; }
    else if(op.re!=0 && op.im!=0){
        if(op.im==1){ os << op.re << "+" << "i"; return os; }
        else if(op.im==-1){ os << op.re << "-i"; return os; }
        else if(op.im>0&&op.im!=1){os << op.re << "+" << op.im << "i";return os;}
        else if(op.im<0&&op.im!=-1){os << op.re << op.im << "i";return os;}
    }
    return os;
}
