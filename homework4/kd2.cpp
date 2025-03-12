#include<iostream>
using namespace std;

class C{
    int x;
    public:
    C(int i){x=i;}
    C(const C & op)
    {
        x = op.x;
    }
    const C operator+(const C & op) const
    {
        C tmp(0);
        tmp.x = x+op.x;
        tmp.x *= 2;
        return tmp;
    }
    int get() const
    {
        return 2*x;
    }
};

int main(){
    C c1(7),c2=5,c3(c1+c2);
    cout << c1.get() << c2.get() << c3.get()<< endl;
    return 0;
}