#include<iostream>
using namespace std;

class A{
    public:
    A(int x=0){cout<<0;}
    A(A&){cout<<2;}
    A(const A&){cout<<3;}
    ~A(){cout<<4;}
};

int main(){
    A c=2;
    cout<<5;
    return 0;
}

//结果为054