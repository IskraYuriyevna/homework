#include<iostream>
using namespace std;

class B{
    int n;
    public:
    B(){n=10;}
    B(const B&ob){
        n = ob.n+10;
    }
    ~B(){}
    int get(){
        return n;
    }
};

int main(){
    B b1,b2 = b1,b3(b2);
    cout << b1.get()<< " " << b2.get()<< " "<< b3.get() << endl;
    return 0;
}