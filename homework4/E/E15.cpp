
#include<iostream>
#include<cstring>
#include<string>
using namespace std;

class IncorrectArgs{
    protected:
        string comment_;int arg1_,arg2_;
    public:
        IncorrectArgs(const string& func,int arg1,int arg2=0):comment_(func),arg1_(arg1),arg2_(arg2){}
        IncorrectArgs(const IncorrectArgs& other):comment_(other.comment_),arg1_(other.arg1_),arg2_(other.arg2_){}
        ~IncorrectArgs(){}
        string GetComment(){return comment_;}
        int GetArg1(){return arg1_;}
        int GetArg2(){return arg2_;}
};

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
        if(i<0||i>length_) throw(IncorrectArgs("insert",i));

        char* tmp = new char[length_+1]; 
        strncpy(tmp,string_,i);
        tmp[i] = c;
        strcpy(tmp+i+1, string_+i);
        delete [] string_;
        string_ = tmp;
        length_++;
}

void mstring::insert(const char* c,int i){
        if(c==nullptr|| i<0 || i>length_) throw(IncorrectArgs("insert",i));

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
        if(i<0 || i>= length_) throw(IncorrectArgs("del",i));

        char* tmp = new char[length_];
        strncpy(tmp,string_,i);
        strcpy(tmp+i,string_+i+1);
        delete[] string_;
        string_ = tmp;
        length_ --;
}

void mstring::del(int i,int j){
        if(i<0 || j>= length_ || i>j) throw(IncorrectArgs("del",i,j));

        char* tmp = new char[length_-(j-i+1)+1];
        strncpy(tmp,string_,i);
        strcpy(tmp+i,string_+j+1);
        delete[] string_;
        string_ = tmp;
        length_ -= j-i+1;
}

int mstring::search(const char* str){
        if(str==nullptr){return -1;}
        const char* res = strstr(string_,str);
        if(res == nullptr){return -1;}
        return res - string_;
}

void mstring::print(){
	cout << string_ <<endl;
}

// void error()
// {
//         mstring s ("hello world");
//         mstring s1 = s;
//         mstring s2;
//         if (!s1.isempty())
//         {
//            s1.insert(' ', 5);
//            s1.insert('m',6);
//            s1.insert('y',7);
//            s.insert(" my",5);
//            s.print();
//            s1.print();
//         }
//         s.del(9);
//         s1.del(-5,7);
//         s.print();
//         s1.print();
// }

// void error()
// {
//         mstring s ("hello world");
//         mstring s1 = s;
//         mstring s2;
//         if (!s1.isempty())
//         {
//            s1.insert(' ', 5);
//            s1.insert('m',6);
//            s1.insert('y',7);
//            s.insert(" my",5);
//            s.print();
//            s1.print();
//         }
//         s.del(-1);
//         //cout << s << s1 << s2 << endl;

// }

int main()
{
    try{
        error();
    }
    catch(IncorrectArgs& ex){
        if(ex.GetArg2()){
            cerr << "Exception: problem in " << ex.GetComment() << " incorrect parameter:" << ex.GetArg1() << " " << ex.GetArg2() << endl;  
            return 2;
        }else{
            cerr << "Exception: problem in " << ex.GetComment() << " incorrect parameter:" << ex.GetArg1() << endl; 
            return 1;
        }
    }
    catch(...){
        cerr << "Exception: unknown error" << endl;
        return -1;
    }

    return 0;
}