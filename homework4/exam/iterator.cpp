#include<list>
#include<iostream>
using namespace std;

struct A{
    static int n;
    int t;
    A(int m = 3){t=m;}
    bool operator == (int a)const {return t == a;}
    
};

int A::n = 3;

template<class T> int count(const list<T>& v,int a)
{
    int k = 0;
    typename list<T>::const_iterator p = v.begin();
    while(p != v.end()){
        k+= *p == a;
    }
    return k;
}

int main(){
}