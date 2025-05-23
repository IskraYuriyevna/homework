#include<iostream>
#include<cstring>
using namespace std;

class mstring{
private:
        char* string_;
        int length_;
public:   
           
	mstring(){
		string_ = new char[1];
		string_[0]='\0';
		length_ = 0;
        }
        mstring(const char* str){
		string_ = new char[strlen(str)+1];
		strcpy(string_,str);
		length_ = strlen(str);
        }
        mstring(const mstring& ob){
		string_ = new char[strlen(ob.string_)+1];
		strcpy(string_,ob.string_);
		length_ = ob.length_;
        }

        ~mstring(){
                delete[] string_;
        }

        int length(){return length_;};
        bool isempty(){if (length_){return false;}else{return true;}};
        void add(char c);
        void add(const char* c);
        void insert(char c,int i);
        void insert(const char* c,int i);
        void del(int i);
        void del(int i, int j);
        int search(const char* str);
        void print();
};

void mstring::add(char c){
        
}

void mstring::add(const char*c){

}

void mstring::insert(char c,int i){

}

void mstring::insert(const char* c,int i){

}

void mstring::del(int i){

}

void mstring::del(int i,int j){

}

int search(const char* str){
        return 0;
}

void mstring::print(){
	
}
