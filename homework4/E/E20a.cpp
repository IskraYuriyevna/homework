#include <iostream>
using namespace std;
class Figure{
protected:
    int x1_,y1_,x2_,y2_;
public:
    Figure(int x1,int y1,int x2,int y2):x1_(x1),y1_(y1),x2_(x2),y2_(y2){}
    virtual ~Figure() {}
    virtual bool move () const = 0;
};
class K: public Figure{//King 国王
public:
    K(int x1,int y1,int x2,int y2): Figure(x1,y1,x2,y2){}
    bool move() const;
};
bool K::move() const {
    if(x2_>8 || y2_>8 || x2_<=0 || y2_<=0) return false;
    if(x1_==x2_ && y1_==y2_) return false;

    if(abs(x1_-x2_)==1 && y1_==y2_) return true;//左右
    if(abs(y1_-y2_)==1 && x1_==x2_) return true;//上下
    if(abs(x1_-x2_)==1 && abs(y1_-y2_)==1) return true;//对角
    return false;
}
class Q: public Figure{//Queen 王后
public:
    Q(int x1,int y1,int x2,int y2): Figure(x1,y1,x2,y2){}
    bool move() const;
};
bool Q::move() const {
   // cout <<"("<<x1_<<","<<y1_<<") "<<"("<<x2_<<","<<y2_<<")" << endl;
    if(x2_>8 || y2_>8 || x2_<=0 || y2_<=0) return false;
    if(x1_==x2_ && y1_==y2_) return false;

    if(abs(x1_-x2_)>=1 && y1_==y2_) return true;//左右
    if(abs(y1_-y2_)>=1 && x1_==x2_) return true;//上下
    if(abs(x1_-x2_) == abs(y1_-y2_)) return true;//对角
    return false;
}
class N: public Figure{//Knight 马
public:
    N(int x1,int y1,int x2,int y2): Figure(x1,y1,x2,y2){}
    bool move() const;
};
bool N::move() const {
    //cout <<"("<<x1_<<","<<y1_<<") "<<"("<<x2_<<","<<y2_<<")" << endl;
    if(x2_>8 || y2_>8 || x2_<=0 || y2_<=0) return false;
    if(x1_==x2_ && y1_==y2_) return false;

    if(abs(x1_-x2_)==2 && abs(y1_-y2_)==1) return true;
    if(abs(y1_-y2_)==2 && abs(x1_-x2_)==1) return true;
    return false;
}
class B: public Figure{//Bishop 象
public:
    B(int x1,int y1,int x2,int y2): Figure(x1,y1,x2,y2){}
    bool move() const;
};
bool B::move() const {
    //cout <<"("<<x1_<<","<<y1_<<") "<<"("<<x2_<<","<<y2_<<")" << endl;
    if(x2_>8 || y2_>8 || x2_<=0 || y2_<=0) return false;
    if(x1_==x2_ && y1_==y2_) return false;

    //if(abs(x1_-x2_)>=1 && y1_==y2_) return true;//左右
    //if(abs(y1_-y2_)>=1 && x1_==x2_) return true;//上下
    if(abs(x1_-x2_) == abs(y1_-y2_)) return true;//对角
    return false;
}
class R: public Figure{//Rook 车
public:
    R(int x1,int y1,int x2,int y2): Figure(x1,y1,x2,y2){}
    bool move() const;
};
bool R::move() const {
    // cout <<"("<<x1_<<","<<y1_<<") "<<"("<<x2_<<","<<y2_<<")" << endl;
    if(x2_>8 || y2_>8 || x2_<=0 || y2_<=0) return false;
    if(x1_==x2_ && y1_==y2_) return false;

    if(abs(x1_-x2_)>=1 && y1_==y2_) return true;//左右
    if(abs(y1_-y2_)>=1 && x1_==x2_) return true;//上下
    //if(abs(x1_-x2_) == abs(y1_-y2_)) return true;//对角
    return false;
}
class Parser{
private:
    char str1;
    int x1,y1,x2,y2;
public:
    Parser(const char * str):str1(str[0]),x1(str[2]-'a'+1),y1(str[3]-'0'),x2(str[5]-'a'+1),y2(str[6]-'0'){}
    char getStr1() const {return str1;}
    int getX1() const {return x1;}
    int getY1() const {return y1;}
    int getX2() const {return x2;}
    int getY2() const {return y2;}
};
class ChessChecker{
private:
    Figure * figures;
    char * str;
    const char * readStr();
public:
    ChessChecker();
    ~ChessChecker(){delete [] str; delete figures;}
    void check() const;
};
const char * ChessChecker::readStr(){
    str = new char[8];
    cin.getline(str,8);
    return  str;
}
ChessChecker::ChessChecker(){
    Parser p(readStr());
    //cout << p.getStr1() << " " << p.getX1() << " " << p.getY1() << " " << p.getX2() << " " << p.getY2() << endl;
    switch (p.getStr1()) {
        case 'K':figures = new K(p.getX1(),p.getY1(),p.getX2(),p.getY2());
            break;
        case 'Q':figures = new Q(p.getX1(),p.getY1(),p.getX2(),p.getY2());
            break;
        case 'N':figures = new N(p.getX1(),p.getY1(),p.getX2(),p.getY2());
            break;
        case 'B':figures = new B(p.getX1(),p.getY1(),p.getX2(),p.getY2());
            break;
        case 'R':figures = new R(p.getX1(),p.getY1(),p.getX2(),p.getY2());
            break;
        default:
            break;
    }
}

void ChessChecker::check() const {
    if(figures->move()) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){
    ChessChecker c;
    c.check();
    return 0;
}

/*
//Examples
//        Input
//Q d6 f4
//        Output
//YES
//        Input
// R g5 f3
//        Output
//NO


//8 -  -  -  -  -  -  -  -
//7 -  -  -  -  -  -  -  -
//6 -  -  -  -  -  -  -  -
//5 -  -  -  -  -  -  -  -
//4 -  -  -  -  -  -  -  -
//3 -  -  -  -  -  -  -  -
//2 -  -  -  *  -  -  -  -
//1 -  *  -  -  -  -  -  -
//  a  b  c  d  e  f  g  h
//  1  2  3  4  5  6  7  8
 */