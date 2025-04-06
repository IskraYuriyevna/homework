#include<iostream>
#include<cstring>
using namespace std;

class mstring{
    private:
        char* string_;
        int length_;
    public:
    mstring(){

    }
    mstring(){

    }
    mstring(const char* str){

    }
    ~mstring(){

    }


    int length();
    bool isempty();
    void add(char c);
    void add(const char* c);
    void insert(char c,int i);
    void insert(const char* c,int i);
    void del(int i);
    void del(int i, int j);
    int search(const char* str);
    void print();

};

int main(){


} 