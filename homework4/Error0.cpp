#include <iostream>
using namespace std;

class B{
    public:
    B(int n){
        try{
            cout << 1 << " ";
            if(n == 0) throw "abc";
            if(n>11) throw 11;
        }
        catch (int) {cout<<" ";}
        catch (char *) {cout<<" ";throw;}
        cout << 4 << " "; 
    }
    B(B&){cout<<5<<" ";}
    ~B(){cout<<6<<" ";}
};

int main(){
    try{
        B b(12);
        B c(0);
    }
    catch (...){
        cout << 7 << " ";
        cout << 8;
    }
}