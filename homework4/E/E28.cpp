#include<iostream>
#include<cmath>
#include <ostream>
using namespace std;

class Exception{
    private:
        string comment_;int errno1_,errno2_;
    public:
        Exception(const char* comment=""):comment_(comment){};
        Exception(const char* comment,int err1):comment_(comment),errno1_(err1){};
        Exception(const char* comment,int err1,int err2):comment_(comment),errno1_(err1),errno2_(err2){};
        ~Exception(){}
        string GetComment()const{return comment_;}
        const int& GetErrno1()const{ return errno1_;}
        const int& GetErrno2()const{return errno2_;}
};

template <class T>
class Vec{
    private:
        T* v;
        int len;

    public:
        Vec(int length,T *vecptr); 
        Vec(int length);
        Vec(const Vec & ob);
        ~Vec();
        void set(T arg,int coord);
        T get(int coord) const;
        T euc_norm() const;
        T max_norm() const;
        void print() const;

        Vec<T> operator+(const Vec<T>& op)const;
        Vec<T> operator-(const Vec<T>& op)const;
        Vec<T> operator*(T a)const;
        T operator^(const Vec<T>& op)const;
        template <typename U>
        friend Vec<U> operator*(U a,const Vec<U>& op);
        const Vec<T>& operator=(const Vec<T>& op);
        Vec<T>& operator+=(const Vec<T>& op);
        bool operator==(const Vec<T> &op)const;
        T & operator[](int index); 
        template <typename U>
        friend ostream& operator<<(ostream& os , const Vec<U>& op);
};

template <class T>
Vec<T> Vec<T>::operator+(const Vec<T>& op)const{
    if(len != op.len){throw Exception("addition of vectors of different lengths: ",len, op.len);}
    Vec tmp(len);
    for(int i=0;i<len;i++){
        tmp.v[i] = v[i]+op.v[i];
    }
    return tmp;
}

template <class T>
Vec<T> Vec<T>::operator-(const Vec<T>& op)const{
    if(len != op.len){throw Exception("subtraction of vectors of different lengths: ",len, op.len);}
    Vec tmp(len);
    for(int i=0;i<len;i++){
        tmp.v[i] = v[i]-op.v[i];
    }
    return tmp;
}

template <class T>
Vec<T> Vec<T>::operator*(T a)const{
    Vec tmp(len);
    for(int i=0;i<len;i++){
        tmp.v[i] = v[i]*a;
    }
    return tmp;
}

template <typename U>
Vec<U> operator*(U a,const Vec<U>& op){
    Vec<U> tmp(op.len);
    for(int i=0;i<op.len;i++){
        tmp.v[i] = op.v[i]*a;
    }
    return tmp;
}

template <class T>
T Vec<T>::operator^(const Vec<T>& op)const{
    if(len != op.len){throw Exception("multiplication of vectors of different lengths: ",len, op.len);}
    T produce = 0;
    for(int i=0;i<len;i++){
        produce += v[i]*op.v[i];
    }
    return produce;
}

template <class T>
const Vec<T>& Vec<T>::operator=(const Vec<T>& op){
    if(this==&op) return *this;
    delete[] v;
    len = op.len;
    v = new T[len];
    for(int i=0;i<len;i++){
        v[i]=op.v[i];
    }
    return *this;
}

template <class T>
Vec<T>& Vec<T>::operator+=(const Vec<T>& op){
    if(len != op.len){throw Exception("addition of vectors of different lengths: ",len, op.len);}
    for(int i=0;i<len;i++){
        v[i] = v[i]+op.v[i];
    }
    return *this;
}

template <class T>
bool Vec<T>::operator==(const Vec<T> &op)const{
    if(len!=op.len){
        return false;
    }else{
        for(int i=0;i<len;i++){
            if(v[i]!=op.v[i]){return false;}
        }
    }
    return true;
}

template <class T>
T & Vec<T>::operator[](int index){
    if(index < 0 || index >= len){throw Exception("incorrect indexing: ", index);}
    return v[index];
}

template <typename U>
ostream& operator<<(ostream& os , const Vec<U>& op){
    os << "(";
    for(int i=0;i<op.len;i++){
        if(i){os<< ",";}
        os << op.v[i];
    }
    os << ")";
    return os;
}

template <class T>
Vec<T>::Vec(int length,T* vecptr){
    if(length<=0) throw Exception("length error");
    v = new T[length];   
    for(int i=0;i<length;i++){v[i] = vecptr[i];}
    len = length;
}

template <class T>
Vec<T>::Vec(int length){
    if(length<=0) throw Exception("length error");
    v = new T[length];
    for(int i=0;i<length;i++){v[i] = 0.0;}
    len = length;
}

template <class T>
Vec<T>::Vec(const Vec<T>& vec_a){
    if(vec_a.len<=0) throw Exception("length error");
    v = new T[vec_a.len];
    for(int i=0;i<vec_a.len;i++){v[i] = vec_a.v[i];}
    len = vec_a.len;
}

template <class T>
Vec<T>::~Vec(){
    if(v!=nullptr){
        delete[] v; 
        v = nullptr;
    }
}

template <class T>
void Vec<T>::set(T arg,int coord){
    if (coord<0|| coord >= len)throw Exception("coordinate error in set()");
    v[coord] = arg;
}

template <class T>
T Vec<T>::get(int coord) const {
    if (coord<0|| coord >= len)throw Exception("coordinate error in get()");
    return v[coord];
}

template <class T>
T Vec<T>::euc_norm() const {
    T sum = 0.0;
    for (int i = 0; i < len; i++) {
        sum += (v[i] * v[i]);
    }
    return sqrt(sum);
}

template <class T>
T Vec<T>::max_norm() const {
    T max = fabs(v[0]);
    for(int i =1;i<len;i++){
        if(max<fabs(v[i])){
            max = fabs(v[i]);
        }
    }
    return max;
}

template <class T>
void Vec<T>::print() const {
    cout << "(";
    for (int i=0;i<len;i++){
        if(i){cout << ",";}
        cout << v[i]; 
    }
    cout << ")"<<endl;
}

// void Vector()
// {
//         int w1[3] = {1,2,3};
//         int w2[3] = {2,3,1};

//         Vec <int> v1(3, w1), v2(3, w2), v3(3);
//         cout << "v1 = " << v1 << endl;
//         cout << "v2 = " << v2 << endl;
//         v3 = 2*v1 + v2*3;
//         cout << "v3 = " << v3 << endl;
//         int pr = v1^v2;
//         cout << "v1^v2 = " << pr << endl;
//         v1[1] = 7;
//         cout << "v[1] = " << v1[1] << endl;

// }


// void Vector()
// {
//       double wd[3] = {1.5,2.3,-1.7};
//       double wd2[4] = {1.1,2.3,4.5,6.7};
//       Vec<double>  vd1(3, wd), vd2(4, wd2);
//       cout << "vd1 = " << vd1 << endl;
//       cout << "vd2 = " << vd2 << endl;
//       double m = vd1  vd2;
//       cout << m << endl;
//       cout << "vd1 = " << vd1 << endl;
//       cout << "vd2 = " << vd2 << endl;
//       double prd = vd1^vd2;
//       cout << "vd1^vd2 = " << prd << endl;
//       vd2 = vd1 = vd1;
//       cout << "vd2 = " << vd2 << endl;
// }


int main()
{
    try
    {
        Vector();
    }catch(const Exception& ex){
        string type = ex.GetComment();
        if((type == "addition of vectors of different lengths: ")||(type == "subtraction of vectors of different lengths: ")||(type=="multiplication of vectors of different lengths: ")){
            cerr << "Exception: " << type << ex.GetErrno1() << " " << ex.GetErrno2() << endl;
        }else if(type == "incorrect indexing: "){
            cerr << "Exception: " << type << ex.GetErrno1() << endl;
        }else if((type == "coordinate error in set()")||(type =="coordinate error in get()")||(type=="length error")){
            cerr << "Exception: " << type << endl;
        }
    }catch(...) { 
        cerr << "Exception: unknown error" << endl;
    }
    return 0;
} 

