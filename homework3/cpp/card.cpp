#include<iostream>
#include<cstring>
using namespace std;

class card{
    char * c;
    int i;
public:
    card():c(nullptr),i(0){}

    card(const char *st,int n) {        
        i = n;
        //delete[] c;
        if(st){
            c = new char[strlen(st)+1];
            strcpy(c,st);
        } else {
            c = nullptr;
        }
        
        // c = new char[strlen(st)+1];
        // strcpy(c,st);
        // cout<< st << " " << endl;
        }
    ~card(){delete[] c;}

    // void f(const char *st,int n){
    //     i = n;
    //     delete[] c;
    //     c = new char[strlen(st)+1];
    //     strcpy(c,st);
    //     cout<< st << " " << endl;
    // }
    
    // void p(){
    //     if(c != nullptr){
    //         cout << c << " " << i << endl;
    //     }else{
    //         cout << " " << endl;
    //     }
    // }

    

};

card::card(*const char * a,int b){
    
}



int main(){
    const card k3("啥玩意啊？",7);
    k3.p();
    //card k1("Hello",3),k2,k3("world",5);
    //k1.f("Hello",3);
    //k1.p();
    //k2.p();
    //k3.p();
    return 0;
}