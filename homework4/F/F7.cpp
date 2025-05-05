#include <iostream>
using namespace std;

char c;

void gc(){
    c = cin.get();
}

void S();
void A();

void S(){
    if(c == '0')
    {
        cout << 'a';
        gc();
        A();
    }
    else if(c == '1')
    {
        gc();
        A();
        cout << 'b';
    }
    else throw c;
}

void A(){
    if(c == '0')
    {
        cout << 'a';
        gc();
        A();
    }
    else if(c == '1')
    {
        gc();
        A();
        cout << 'b';
    }
    
}

int main()
{
    try{
        gc();
        S();
        if(c=='\n') cout << endl;
        else throw c;
    }
    catch(char c)
    {
        cerr << "Error in: " << c << endl;
    }

    return 0;
}
