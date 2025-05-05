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
        gc();
        S();
        cout << 'b';
    }
    else if(c == '1')
    {
        cout << 'a';
        gc();
        A();
    }
    else throw c;
}

void A(){
    if(c=='1')
    {
        gc();
        A();
        cout << 'a';
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