#include<iostream>
#include<cmath>
#include <ostream>
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

        Vec operator+(const Vec& op)const;
        Vec operator-(const Vec& op)const;
        Vec operator*(double a)const;
        friend Vec operator*(double a,const Vec& op);
        const Vec& operator=(const Vec& op);
        bool operator==(const Vec &op)const;
        double & operator[](int index); 
        friend ostream& operator<<(ostream& os , const Vec& op);
};

Vec Vec::operator+(const Vec& op)const{
    Vec tmp(len);
    for(int i=0;i<len;i++){
        tmp.v[i] = v[i]+op.v[i];
    }
    return tmp;
}

Vec Vec::operator-(const Vec& op)const{
    Vec tmp(len);
    for(int i=0;i<len;i++){
        tmp.v[i] = v[i]-op.v[i];
    }
    return tmp;
}

Vec Vec::operator*(double a)const{
    Vec tmp(len);
    for(int i=0;i<len;i++){
        tmp.v[i] = v[i]*a;
    }
    return tmp;
}

Vec operator*(double a,const Vec& op){
    Vec tmp(op.len);
    for(int i=0;i<op.len;i++){
        tmp.v[i] = op.v[i]*a;
    }
    return tmp;
}

const Vec& Vec::operator=(const Vec& op){
    if(this==&op) return *this;
    delete[] v;
    len = op.len;
    v = new double[len];
    for(int i=0;i<len;i++){
        v[i]=op.v[i];
    }
    return *this;
}

bool Vec::operator==(const Vec &op)const{
    if(len!=op.len){
        return false;
    }else{
        for(int i=0;i<len;i++){
            if(v[i]!=op.v[i]){return false;}
        }
    }
    return true;
}

double & Vec::operator[](int index){
    return v[index];
}

ostream& operator<<(ostream& os , const Vec& op){
    os << "(";
    for(int i=0;i<op.len;i++){
        if(i){os<< ",";}
        os << op.v[i];
    }
    os << ")";
    return os;
}


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

int main()
{
        double y1[4] = {1,2,3,4};
        double y2[4] = {-2,1,3,-3};

        Vec u(4, y1), v(4, y2);
        Vec w(4);

        cout << "u = " << u << endl;
        cout << "v = " << v << endl;
        w = u = u;
        cout << "w = u = " << w << endl;
        w = 4.*u + v*3;
        cout << "w = 4.*u + v*3 = " << w << endl;
        w[2] = 3;
        w[0] = -1;
        cout << "w = " << w << endl;

        return 0;
}
