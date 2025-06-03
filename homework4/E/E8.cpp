#include<iostream>
#include<cstring>
using namespace std;

class mstring{
private:
        char* string_;
        int length_;
public:   
           
	mstring();

        mstring(const char* str);
        
        mstring(const mstring& ob);

        ~mstring(){delete[] string_;}

        int length()const{return length_;};
        bool isempty()const{if (length_){return false;}else{return true;}};
        void add(char c);
        void add(const char* c);
        void insert(char c,int i);
        void insert(const char* c,int i);
        void del(int i);
        void del(int i, int j);
        int search(const char* str)const;
        void print()const;
};

mstring::mstring(){
   string_ = new char[1];
        string_[0]='\0';
        length_ = 0;
}

mstring::mstring(const char* str){
        string_ = new char[strlen(str)+1];
        strcpy(string_,str);
        length_ = strlen(str);
}

mstring::mstring(const mstring& ob){
        string_ = new char[strlen(ob.string_)+1];
        strcpy(string_,ob.string_);
        length_ = ob.length_;
}

void mstring::add(char c){
        char* tmp = new char[length_+2];
        strcpy(tmp,string_);
        tmp[length_]=c;
        tmp[length_+1]='\0';
        delete[] string_;
        string_ = tmp;
        length_++;
}

void mstring::add(const char* c){
        if(c != nullptr){
                int nlen = strlen(c);
                char* tmp = new char[length_+nlen+1];
                strcpy(tmp,string_);
                strcat(tmp,c);
                delete[] string_;
                string_ = tmp;
                length_ += nlen;
        }
}

void mstring::insert(char c,int i){
        if(i<0||i>length_) return;

        char* tmp = new char[length_+1]; 
        strncpy(tmp,string_,i);
        tmp[i] = c;
        strcpy(tmp+i+1, string_+i);
        delete [] string_;
        string_ = tmp;
        length_++;
}

void mstring::insert(const char* c,int i){
        if(c==nullptr|| i<0 || i>length_) return;

        int nlen = strlen(c);
        char* tmp = new char[length_+nlen+1];
        strncpy(tmp,string_,i);
        strcpy(tmp+i,c);
        strcpy(tmp+i+nlen,string_+i);
        delete[] string_;
        string_ = tmp;
        length_ += nlen;
}

void mstring::del(int i){
        if(i<0 || i>= length_) return;

        char* tmp = new char[length_];
        strncpy(tmp,string_,i);
        strcpy(tmp+i,string_+i+1);
        delete[] string_;
        string_ = tmp;
        length_ --;
}

void mstring::del(int i,int j){
        if(i<0 || j>= length_ || i>j) return;

        char* tmp = new char[length_-(j-i+1)];
        strncpy(tmp,string_,i);
        strcpy(tmp+i,string_+j+1);
        delete[] string_;
        string_ = tmp;
        length_ -= j-i+1;
}

int mstring::search(const char* str)const{
        if(str==nullptr){return -1;}
        const char* res = strstr(string_,str);
        if(res == nullptr){return -1;}
        return res - string_;
}

void mstring::print()const{
	cout << string_ <<endl;
}

