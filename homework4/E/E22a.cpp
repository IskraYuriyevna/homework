#include <iostream>
#include <string>
using namespace std;

class Exception{
private:
    string comment_;
public:
    Exception(const char * comment): comment_(comment){}
    Exception(const Exception & other): comment_(other.comment_){}
    ~Exception(){}
    const string GetComment() const { return comment_; }
};

class Vector_2d_Exception : public Exception{
private:
    int errNum_;
public:
    Vector_2d_Exception(const char * comment , int errNum): Exception(comment), errNum_(errNum){}
    Vector_2d_Exception(const Vector_2d_Exception  & other): Exception(other), errNum_(other.errNum_){}
    int GetErrNum() const { return errNum_; }
};

class Vector_2d{
private:
    int x_,y_;
public:
    Vector_2d():x_(0),y_(0){}
    Vector_2d(int x,int y):x_(x),y_(y){}
    friend istream & operator >> (istream & is,Vector_2d & op);
    friend ostream & operator << (ostream & os,const Vector_2d & op);
};
istream & operator >> (istream & is,Vector_2d & op){
    is >> op.x_;
    if(op.x_<0) throw Vector_2d_Exception("Exception: negative coordinate:", op.x_);
    char c;
    is.get(c);
    if(c=='\n'||c==EOF) throw Exception("Exception: one coordinate");
    else is >> op.y_;
    if(op.y_<0) throw Vector_2d_Exception("Exception: negative coordinate:", op.y_);
    return is;
}
ostream & operator << (ostream & os,const Vector_2d & op){
    os << "(" << op.x_ << "," << op.y_ << ")";
    return os;
}
int main(){
    try{
        Vector_2d v;
        cin >> v;
        cout << v << endl;
    }catch (Vector_2d_Exception & ex){
        cerr << ex.GetComment() << ex.GetErrNum() << endl;
    }catch (Exception & ex){
        cerr << ex.GetComment() << endl;
    }
}