#include<iostream>
using namespace std;

struct S{
    double d;
    static int i;
    S(double a=3.5){d=i=a;}
    S(S&& a){d=a.d;}
    static int f(){return n;};
};

//static是后加的
//int S::i;

int main(){
    const S s = S(7.3),t;
    cout << s.f() <<" "<< t.n <<endl;
}


//答案： 3 7 3
//强烈怀疑有印刷错误，n是哪来的