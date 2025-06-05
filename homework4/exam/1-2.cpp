#include<iostream>
using namespace std;

struct A{
    virtual void g1(){cout<<"A:g1\n";}
    void g2(){g1();cout<<"A:g2\n";}
    virtual void g3() = 0;
};

void f(A& a){
    a.g1();
}

class B : public A{
    void g1(){cout<<"B:g1\n";}
    virtual void g2(){g1();cout<<"B:g2\n";}
    void g3(){cout<<"B:g3()\n";}
};

int main(){
    B b; A *pa = &b;
    pa ->g2();
    f(b);
}

