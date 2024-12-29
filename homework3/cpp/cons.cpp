#include<iostream>
using namespace std;

class A{
    private:
    int x;
    public:
    A():x(10){cout<<"A1";}//默认的构造函数,如果不输入值时调用，默认给x赋值10
    A(int x){cout<<"A2";}//接受参数的构造函数
    A(A&){cout<<"A3";}//拷贝构造函数
    A(const A&){cout<<"A4";}//常数拷贝构造函数
    ~A(){cout<<"A5";}//解构函数
};

class B{
    private:
        int x;
    public:
        int y;

};

class C{
    private:
        int x,y;
    public:

};

class D{
    private:
        string name;
        int weight;
        B b; C c;
    public:
        D(){};
        ~D(){};
};

int main(){


}