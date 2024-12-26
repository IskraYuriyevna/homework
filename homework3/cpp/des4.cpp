#include<iostream>
using namespace std;

class A{
    public:
    A(int x=0){cout<<1;}
    A(A&){cout<<2;}
    A(const A&){cout<<3;}
    ~A(){cout<<4;}
};

int main(){
    const A b;
    A c=b;
    cout<<5;
    return 0;
}

//结果为13544
//也就是说，
//1.首先使用构造函数创建了A
//2.然后进行了深拷贝，调用了拷贝的函数
//3.运行main
//4.析构两个A对象