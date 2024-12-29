#include<iostream>
using namespace std;

class B{
    public:
    B(){cout<<1;}
    ~B(){cout<<2;}
};

class C{
    public:
    C(){cout<<3;}
    ~C(){cout<<4;}
};

class A{
    B b; C c;
    public:
    A(int x=0){cout<<5;}
    ~A(){cout<<6;}
};

int main(){
    A a;
    cout<<7;
    return 0;
}

//结果为1357642,也就是说：
//1.首先会进入A的代码，然后按顺序创建B和C
//2.然后运行A的构造函数完成创建A
//3.然后运行main的内容
//4.首先销毁A
//5.再按照先创建的后解构的顺序解构C和B