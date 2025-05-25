#include<iostream>
#include <ostream>
#include<exception>
using namespace std;

class NegCoord: public exception{
    private:
        int num_;
    public:
        NegCoord(int number):num_(number){}
        NegCoord(const NegCoord& other):num_(other.num_){}
        int GetNum(){return num_;}
};

class OneCoord: public exception{
    public:
        OneCoord(){};
        //OneCoord(OneCoord& other){};
};

class Vector_2d{
public:
    Vector_2d(double x=0,double y=0)
    {
        x_ = x;y_ = y;
    }
    friend Vector_2d operator*(double a,const Vector_2d& op);
    friend ostream& operator<<(ostream& os, const Vector_2d& op);
    friend istream& operator>>(istream& is, Vector_2d& op);
private:
    int x_,y_;
};

istream& operator>>(istream& is,Vector_2d& op)
{
    char c;
    is >> op.x_; 
    if(op.x_<0){throw NegCoord(op.x_);}

    is.get(c);
    if((c == '\n')||(c == EOF)){throw OneCoord();}
    else{is >> op.y_;}
    if(op.y_<0){throw NegCoord(op.y_);}

    return is;
}

ostream& operator<<(ostream& os,const Vector_2d& op)
{
    os << "(" << op.x_ << "," << op.y_ << ")";
    return os;
}

int main(){
    try{
        Vector_2d v;
        cin >> v;
        cout << v << endl;
    }catch(OneCoord& ex){
        cerr << "Exception: one coordinate" << endl;
    }catch(NegCoord& ex){
        cerr << "Exception: negative coordinate:" << ex.GetNum() << endl;
    }catch(...){
        cerr << "Exception: unknown error" << endl;
    }
    return 0;
}