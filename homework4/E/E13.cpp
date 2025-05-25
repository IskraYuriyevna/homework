#include<iostream>
#include<cmath>
#include<string>
using namespace std;

class Exception{
    private:
        string comment_;
    public:
        Exception(const char* comment=""):comment_(comment){};
        ~Exception(){}
        string GetComment()const{return comment_;}
};

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
    if(length<=0) throw Exception("length error");
    v = new double[length];   
    for(int i=0;i<length;i++){v[i] = vecptr[i];}
    len = length;
}
Vec::Vec(int length){
    if(length<=0) throw Exception("length error");
    v = new double[length];
    for(int i=0;i<length;i++){v[i] = 0.0;}
    len = length;
}
Vec::Vec(const Vec& vec_a){
    if(vec_a.len<=0) throw Exception("length error");
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
    if (coord<0|| coord >= len)throw Exception("coordinate error in set()");
    v[coord] = arg;
}

double Vec::get(int coord) const {
    if (coord<0|| coord >= len)throw Exception("coordinate error in get()");
    return v[coord];
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

// void error()
// {
//     double y1[3] = {1,2,3};
//     double y2[5] = {2,1,0,5,7};
//     Vec x(1, y1), y(5, y2), z(4);
//     Vec u = x;
//     cout<< y.get(4)<<endl;
//     //x.set(5.4,1);
//     x.print();
//     z.print();
//     u.print();
// }

int main()
{
    try
    {
        error();
    }
    catch(Exception& ex)
    {
        cerr << "Exception: " << ex.GetComment() << endl;
    }
    catch(...)
    {
        cerr << "Exception: unknown error" << endl;
    }
    return 0;
}  