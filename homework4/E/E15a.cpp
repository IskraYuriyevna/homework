#include <iostream>
#include <cstring>
using namespace std;

class mStringException {
private:
    char *method;
    int param1;
    int param2;
    int errType;

public:
    mStringException(const char *m, int p, int type);
    mStringException(const char *m, int p1, int p2, int type);
    ~mStringException(){
        delete[] method;
    }
    const char * getMethod() const{ return method; }
    int getParam1() const{ return param1; }
    int getParam2() const{ return param2; }
    int getErrType() const{ return errType; }
};
mStringException::mStringException(const char *m, int p, int type) {
    if(m== nullptr){
        method== nullptr;
    }else {
        method = new char[strlen(m) + 1];
        strcpy(method, m);
        param1 = p;
        param2 = 0;
        errType = type;
    }
}
mStringException::mStringException(const char *m, int p1, int p2, int type) {
    if(m== nullptr){
        method== nullptr;
    }else {
        method = new char[strlen(m) + 1];
        strcpy(method, m);
        param1 = p1;
        param2 = p2;
        errType = type;
    }
}

class mstring{
private:
    char *str;
public:
    mstring(const char * s = nullptr);
    mstring(const mstring & ob);
    ~mstring();
    int length() const{ return str==nullptr ? 0 : strlen(str); }
    bool isempty() const;
    void add(char c);
    void add(const char *s);
    void insert(char c,int N);
    void insert(const char *s,int N);
    void del(int N);
    void del(int N,int Y);
    int search(const char * s) const;
    void print() const{ if(str!=nullptr) cout << str << endl; }
};
mstring::mstring(const char * s){
    if(s==nullptr) str=nullptr;
    else{
        str = new char[strlen(s)+1];
        strcpy(str,s);
    }
}
mstring::mstring(const mstring & ob){
    if(ob.str==nullptr) str=nullptr;
    else{
        str = new char[strlen(ob.str)+1];
        strcpy(str,ob.str);
    }
}
mstring::~mstring(){
    if(str!=nullptr){
        delete [] str;
        str=nullptr;
    }
}
bool mstring::isempty() const{
    if(str==nullptr) return true;
    if(strlen(str)) return false;
    else return true;
}
void mstring::add(char c){
    if(str==nullptr){
        str=new char[2];
        str[0]=c;str[1]='\0';
    }else{
        char * temp = new char[strlen(str)+2];
        strcpy(temp,str);
        temp[strlen(str)]=c;
        temp[strlen(temp)]='\0';
        delete [] str;
        str = temp;
    }
}
void mstring::add(const char *s){
    if(s==nullptr) return;
    if(str==nullptr){
        str = new char[strlen(s)+1];
        strcpy(str,s);
    }else{
        char * temp = new char[strlen(s)+strlen(str)+1];
        strcpy(temp,str);
        strcat(temp,s);
        temp[strlen(temp)]='\0';
        delete [] str;
        str = temp;
    }
}
void mstring::insert(char c,int N){
    if(N<0) throw mStringException("insert", N, 1);;
    if(str==nullptr && N!=0) throw mStringException("insert", N, 1);;
    if(str!=nullptr && strlen(str)<N) throw mStringException("insert", N, 1);;
    if(str==nullptr && N==0){add(c); return;}
    if(strlen(str)==N){add(c); return;}
    if(str!=nullptr && N==0){
        char * temp = new char[strlen(str)+2];
        temp[0] = c;
        for(int i =1;i<strlen(str)+1;i++) temp[i] = str[i-1];
        temp[strlen(temp)]='\0';
        delete [] str;
        str = temp;
        return;
    }
    char * temp = new char[strlen(str)+2];
    for(int i = 0;i<N;i++) temp[i] = str[i];
    temp[N] = c;
    for(int i = N+1;i<strlen(str)+1;i++) temp[i]=str[i-1];
    temp[strlen(temp)]='\0';
    delete [] str;
    str = temp;
}
void mstring::insert(const char *s,int N){
    if(N<0) throw mStringException("insert", N, 1);;
    if(str==nullptr && N!=0) throw mStringException("insert", N, 1);
    if(str!=nullptr && strlen(str)<N) throw mStringException("insert", N, 1);;
    if(str==nullptr && N==0){add(s); return;}
    if(strlen(str)==N){add(s); return;}
    if(str!=nullptr && N==0){
        char * temp = new char[strlen(str)+strlen(s)+1];
        strcpy(temp,s);
        strcat(temp,str);
        temp[strlen(temp)]='\0';
        delete [] str;
        str = temp;
        return;
    }
    char * temp = new char[strlen(str)+strlen(s)+1];
    for(int i = 0;i<N;i++) temp[i] = str[i];
    for(int i = N;i<strlen(s)+N;i++) temp[i] = s[i-N];
    for(int i = strlen(s)+N;i<strlen(str)+strlen(s);i++) temp[i]=str[i-strlen(s)];
    temp[strlen(temp)]='\0';
    delete [] str;
    str = temp;
}
void mstring::del(int N){
    if(str==nullptr || N>=strlen(str) || N<0) throw mStringException("del", N, 1);;
    if(strlen(str)==N){
        char * temp = new char[strlen(str)-1+1];
        for(int i = 0;i<strlen(str)-1;i++) temp[i] = str[i];
        temp[strlen(temp)]='\0';
        delete [] str;
        str = temp;
        return;
    }
    if(N==0){
        char * temp = new char[strlen(str)-1+1];
        for(int i = 1;i<strlen(str);i++) temp[i-1] = str[i];
        temp[strlen(temp)]='\0';
        delete [] str;
        str = temp;
        return;
    }
    char * temp = new char[strlen(str)-1+1];
    for(int i = 0;i<N;i++) temp[i] = str[i];
    for(int i = N;i<strlen(str)-1;i++) temp[i] = str[i+1];
    temp[strlen(temp)]='\0';
    delete [] str;
    str = temp;
}
void mstring::del(int N,int Y){
    if(str==nullptr || N>=strlen(str) || Y>=strlen(str) || N<0 || Y<0) throw mStringException("del", N, Y, 2);;
    if(N>Y) throw mStringException("del", N, Y, 2);;
    if(N==Y){ del(N); return;}
    if(N==0 && Y==strlen(str)){
        delete [] str;
        str = nullptr;
        return;
    }
    char * temp = new char[strlen(str)-(Y-N+1)+1];
    for(int i = 0;i<N;i++) temp[i] = str[i];
    for(int i = N;i<strlen(str)-(Y-N+1);i++) temp[i] = str[i+(Y-N+1)];
    temp[strlen(temp)]='\0';
    delete [] str;
    str = temp;
}
int mstring::search(const char * s) const{
    if(str == nullptr || s == nullptr) return -1;
    char * search = strstr(str,s);
    if(search==nullptr) return -1;
    int index = 0;
    const char * temp = str;
    while(temp!=search){index++;temp++;}
    return index;
}

//void error()
//{
//    mstring s ("hello world");
//    mstring s1 = s;
//    mstring s2;
//    if (!s1.isempty())
//    {
//        s1.insert(' ', 5);
//        s1.insert('m',6);
//        s1.insert('y',7);
//        s.insert(" my",5);
//        s.print();
//        s1.print();
//    }
//    s.del(-1);
//    //cout << s << s1 << s2 << endl;
//
//}
//void error() {
//    mstring s("hello world");
//    mstring s1 = s;
//    mstring s2;
//    if (!s1.isempty()) {
//        s1.insert(' ', 5);
//        s1.insert('m', 6);
//        s1.insert('y', 7);
//        s.insert(" my", 5);
//        s.print();
//        s1.print();
//    }
//    s.del(11);
//    s.del(5, 11);
//    s.print();
//    s1.print();
//}

int main() {
    try {
        error();
    } catch (mStringException &ex) {
        if (ex.getErrType() == 1) {
            cerr << "Exception: problem in " << ex.getMethod() << " incorrect parameter:" << ex.getParam1() << endl;
        } else if (ex.getErrType() == 2) {
            cerr << "Exception: problem in " << ex.getMethod() << " incorrect parameter:" << ex.getParam1() << " " << ex.getParam2() << endl;
        }
    } catch (...) {
        cerr << "Exception: unknown error" << endl;
    }
    return 0;
}