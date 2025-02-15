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
        Quotient(int num,unsigned int den){
            if (den == 0){
                den = 1;
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

int main()
{
       Quotient q1(-5,0), q2(6,12), q3(-7), q4;
       q1.print();
       q2.print();
       q3.print();
       q4.print();
       return 0;
}