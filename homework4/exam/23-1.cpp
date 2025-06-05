#include<iostream>
using namespace std;

struct B{
    //用户自定义的转换，使B被当作int使用时会返回3
    //相当于一个没有返回类型，隐式返回int的函数
    operator int(){return 3;}
};

void g(B& b ,double d){cout<<"g(B&,double)\n";}
void g(char c,const char* b){cout<<"g(char,const char*)\n";}
void g(char c,int d){cout<< "g(char,int)\n";}

int main(){
    B b;
    g(1.5,0);
    g(b,2);
    g(2,b);
}