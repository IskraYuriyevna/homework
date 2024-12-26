#include<iostream>
using namespace std;
class A{
    public:
    A(){cout<<1;}
    ~A(){cout<<2;}
};

int main(){
    A a;
    cout<<3;
    return 0;
}

//结果为132