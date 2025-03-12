#include<iostream>
using namespace std;

class A{
    int a;
    public:
    A(int a){this-> a=a;cout<<2;}
    A(){a=100;cout<<3;}
    ~A(){cout<<4;}
    A(const A &b){a=b.a;cout<<1;}
    A& operator=(const A &b){a=b.a;cout<<5;}
};

void f(){
    A x(1);
    A y;
    A z =A(2);
    A t(3.8);
    A w('5');
    x=w=t;
}

int main()
{
    f();
    return 0;
}