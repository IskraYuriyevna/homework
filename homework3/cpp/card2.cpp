#include <iostream>
#include <cstring>
using namespace std;



class card{
    char *name;int n;
    public:
    //card(const char* a,int bt){}
    ~card(){delete[] name;}
    void p()const{cout << name << " " << n;}

    card(const char *a ,int b){
        name = new char[strlen(a)+1];
        strcpy(name,a);
        n = b;
    }
};

int main(){
    card k2("Kong",10);k2.p();
    const card k3("Boxun",7);k3.p();

    return 0;
}