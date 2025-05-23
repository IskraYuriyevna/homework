#include<iostream>
using namespace std;


class Parser
{
    private:
        char c;
        void A();
        void B();
        void S();
    public:
        void gc(){c=cin.get();}
        bool analyze();
};

void Parser::S(){
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

void Parser::A(){
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

void Parser::B(){
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

bool Parser::analyze()
{
    try{
        gc();
        S();
        return true;
    }catch(char c){
        return false;
    }
}

int main(){
    Parser ps;
    if(ps.analyze()){
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}