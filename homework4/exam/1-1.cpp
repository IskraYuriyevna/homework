#include<iostream>
using namespace std;

struct A{
    int n;
    A(int k = 0){n=k;cout<<"1 ";}
    A(const A&){cout<<"2 ";}
    virtual ~A(){cout <<"3 ";}
};

struct B:A{
    B(){cout<<"4 ";}
    B(const B&){cout<<"5 ";}
    ~B(){cout << "6 ";}
};

void func(int x,char* y){cout<<"::func(int,char*)\n";}

void func(const char* a,double b){cout<<"::func(const char*,double)\n";}

namespace N {
    void func(const A &a,int i){cout<<"N::func(A,int)\n";}
}

void func(A& a,B& b){
    try{
        if(typeid(a)==typeid(b)) throw a;
        else throw b;
    }catch(B&){
        cout<<"catch(B&)\n";
    }catch(A&){
        cout<<"catch(A&)\n";
    }
}

int main(){
    A a;B b;
    func(b,b);
    func(1,0);
    using namespace N;
    func(1,2);
}

