#include<iostream>
using namespace std;

char c;

void gc()
{
    c = cin.get();
}

void A();
void B();

void S(){
    if(c == 'a')
    {
        //cout << "S -> aAB" << endl;
        gc();
        A();
        B();
    }
    else if(c == 'b')
    {
        //cout << "S -> bB" << endl;
        gc();
        B();
    }
    if (c != '\n')
        throw c;
}

void A(){
    if(c == 'a'){
        //cout << "A -> aA" << endl;
        gc();
        A();
    }
    else if(c == 'b'){
        //cout << "A -> b" << endl;
        gc();
    }
    else throw c;
}

void B(){
    if(c == 'b')
    {
        //cout << "B -> bB" << endl;
        gc();
        B();
    }
    else if(c == '\n')
    {
        ;//cout << "B -> ε" << endl;
    }
    else throw c;
}

int main(){
    try{
        gc();
        S();
        cout << "YES" << endl;
    }
    catch(char c){
        cout << "NO" << endl;
    }
    return 0;
}