#include <iostream>
using namespace std;

class Complex{
		private:
						double re,im;
		public:
						Complex(double r = 0.,double i = 0.):re(r),im(i){}
						// <<
						friend ostream & operator << (ostream & os,const Complex & op);
						// =
						const Complex & operator = (const Complex & op);
						//  (a+bi)(c+di) = (ac-bd)+(ad+bc)i
						Complex operator * (const Complex & op) const;
						Complex operator * (double a) const;
						friend Complex operator * (double a,const Complex & op);
						// +
						Complex operator + (const Complex & op) const;
						Complex operator + (double a) const;
						friend Complex operator + (double a,const Complex & op);
						// -  (a+bi)-c = (a-c)+bi
						Complex operator - (const Complex & op) const;
						Complex operator - (double a) const;
						friend Complex operator - (double a,const Complex & op);
						// ==
						bool operator == (const Complex & op) const;
};
ostream & operator << (ostream & os,const Complex & op){
    if(op.re==0 && op.im==0){ os << 0; return os; }
    if(op.re==0 && op.im!=0){
        if(op.im==1){ os << "i"; return os; }
        else if(op.im== -1){ os << "-i"; return os; }
        else{os << op.im << "i"; return os; }
    }
    if(op.re!=0 && op.im==0){ os << op.re; return os; }
    if(op.im>0){ os << op.re << "+" << op.im << "i"; return os; }
    if(op.im<0){ os << op.re << op.im << "i"; return os; }
    return os;
}
const Complex & Complex::operator = (const Complex & op){ re=op.re; im=op.im; return *this; }
Complex Complex::operator * (const Complex & op) const { return Complex(re*op.re-im*op.im,re*op.im+im*op.re); }
Complex Complex::operator * (double a) const { return Complex(re*a,im*a); }
Complex operator * (double a,const Complex & op){ return Complex(op.re*a,op.im*a); }
Complex Complex::operator + (const Complex & op) const { return Complex(re+op.re,im+op.im); }
Complex Complex::operator + (double a) const { return Complex(re+a,im); }
Complex operator + (double a,const Complex & op){ return Complex(a+op.re,op.im); }
Complex Complex::operator - (const Complex & op) const { return Complex(re-op.re,im-op.im); }
Complex Complex::operator - (double a) const { return Complex(re-a,im); }
Complex operator - (double a,const Complex & op){ return Complex(a-op.re,op.im); }
bool Complex::operator == (const Complex & op) const {
    return (re==op.re && im==op.im) ? true : false;
}
/*
int main(){
   Complex c(1,2), g(3,4), v;
   cout << "c = " << c << endl;
   cout << "g = " << g << endl;
   cout << "c-2=" << c+2. << endl;
   cout << "2-c=" << 2.+c << endl;
   cout << "g-c=" << g+c << endl;
//   cout << "v = " << v << endl;
//   v = 4.*c*2.;
//   cout << "v = " << v << endl;
//   g = 3.-g+c-2.*v;
//   cout << "g = " << g << endl;
//   cout << "2.*g*v = " << 2.*g*v << endl;
//   v = g = c;
//   if (c == g)
//        v = 2.*Complex(0,1);
//   else
//        v = 2.;
//   cout << "c = " << c << " g = " << g << "v = " << v << endl;
	 return 0;
}
*/