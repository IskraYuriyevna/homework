#include <iostream>
using namespace std;

int gcd(int m,int n){
    while(n!=0){
        int temp = m%n;
        m = n;
        n = temp;
    }
    return m;
}

class Quotient{
    public:
        Quotient(int num){
            numerator = num;
            denominator = 1;
        }
        Quotient(){
            numerator = 0;
            denominator = 1;
        }
        Quotient(int num,int den){
            if (den == 0){
                den = 1;
            }
            if (den < 0) {
                num = -num;
                den = -den;
            }
            int qgcd=gcd(abs(num),den);
            if(qgcd!=1){
                num = num/qgcd;
                den = den/qgcd;
            }            
            numerator = num;
            denominator = den;
        }

        void print(){
            if (denominator==1){
                cout << numerator << endl;;
            }else{
                cout << numerator << '/' << denominator << endl;
            }
        }
    private:
        int numerator;
        unsigned int denominator;
};

