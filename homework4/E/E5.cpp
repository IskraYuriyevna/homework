#include <iostream>
using namespace std;

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
            numerator = num;
            denominator = den;
            if (den == 0){
                denominator = 1;
            }
        }
        void print(){
            if (denominator==1){
                cout << numerator;
            }else{
                cout << numerator << '/' << denominator;
            }
        }
    private:
        int numerator;
        unsigned int denominator;
};