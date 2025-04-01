#include<iostream>
#include<cmath>
using namespace std;

class Vec{
    private:
        double* v;
        int len;

    public:
        Vec(int length,double* vecptr){
            v = new double [len];   
        }
        Vec(int length){

        }
        Vec(const Vec& vec_a){}
        ~Vec(){
            delete[] v;
        }

        Vec& set(double arg,int coord){
            ;
        }
        double get(int coord){
            ;
        }
        double euc_norm() const {
            ;
        }
        double max_norm() const {
            ;
        }
        void print() const {
            ;
        }
};
