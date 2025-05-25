#include<iostream>
#include<cmath>
using namespace std;

class Vec{
    private:
        double* v;
        int len;

    public:
        Vec(int length,double *vecptr);
        Vec(int length);
        Vec(const Vec & ob);
        ~Vec();
        void set(double arg,int coord);
        double get(int coord) const;
        double euc_norm() const;
        double max_norm() const;
        void print() const;

        

};

Vec::Vec(int length,double* vecptr){
    v = new double[length];   
    for(int i=0;i<length;i++){v[i] = vecptr[i];}
    len = length;
}
Vec::Vec(int length){
    v = new double[length];
    for(int i=0;i<length;i++){v[i] = 0.0;}
    len = length;
}
Vec::Vec(const Vec& vec_a){
    v = new double[vec_a.len];
    for(int i=0;i<vec_a.len;i++){v[i] = vec_a.v[i];}
    len = vec_a.len;
}
Vec::~Vec(){
    if(v!=nullptr){
        delete[] v; 
        v = nullptr;
    }
}

void Vec::set(double arg,int coord){
    if(coord>=0&&coord<len){
        v[coord] = arg;
    }
}
double Vec::get(int coord) const {
    if(coord>=0&&coord<len){
        return v[coord];
    }else{
        return 0;
    }
}
double Vec::euc_norm() const {
    double sum = 0.0;
    for (int i = 0; i < len; i++) {
        sum += (v[i] * v[i]);
    }
    return sqrt(sum);
}
double Vec::max_norm() const {
    double max = fabs(v[0]);
    for(int i =1;i<len;i++){
        if(max<fabs(v[i])){
            max = fabs(v[i]);
        }
    }
    return max;
}
void Vec::print() const {
    cout << "(";
    for (int i=0;i<len;i++){
        if(i){cout << ",";}
        cout << v[i]; 
    }
    cout << ")"<<endl;
}
