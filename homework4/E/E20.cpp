#include<iostream>
using namespace std;

class Figure{
    protected:
        int x1_,y1_,x2_,y2_;
    public:
    Figure(int x1,int y1,int x2,int y2):x1_(x1),y1_(y1),x2_(x2),y2_(y2){}
    virtual ~Figure(){}
    virtual bool move () const = 0;
    bool bound()const;
};

bool Figure::bound()const{
    if(x2_>8 || y2_>8 || x2_<=0 || y2_<=0){
        return false;
    }else if(x1_==x2_ && y1_==y2_) {
        return false;
    }else{
        return true;
    }
}


class K : public Figure{ //King
    public:
    K(int x1,int y1,int x2,int y2):Figure(x1,y1,x2,y2){}
    bool move() const;
};

bool K::move() const {
    if(!bound()){return false;}
    if(abs(x1_-x2_)==1 && y1_==y2_) 
    {
        return true;
    }else if(abs(y1_-y2_)==1 && x1_==x2_) {
        return true;
    }else if(abs(x1_-x2_)==1 && abs(y1_-y2_)==1) {
        return true;
    }else{
        return false;
    }
}


class Q : public Figure{ //Queen
    public:
    Q(int x1,int y1,int x2,int y2):Figure(x1,y1,x2,y2){}
    bool move() const;
};

bool Q::move() const {
    if(!bound()){return false;}
    if(abs(x1_-x2_)>=1 && (y1_==y2_)) 
    {
        return true;
    }else if(abs(y1_-y2_)>=1 && (x1_==x2_)) {
        return true;
    }else if(abs(x1_-x2_) == abs(y1_-y2_)) {
        return true;
    }else{
        return false;
    }
}


class N : public Figure{ //Knight
    public:
    N(int x1,int y1,int x2,int y2):Figure(x1,y1,x2,y2){}
    bool move() const;
};

bool N::move() const {
    if(!bound()){return false;}
    if(abs(y1_-y2_)==2 && (x1_==x2_)==1) {
        return true;
    }else if(abs(x1_-x2_)==2 && abs(y1_-y2_)==1) {
        return true;
    }else{
        return false;
    }
}


class B : public Figure{ //Bishop
    public:
    B(int x1,int y1,int x2,int y2):Figure(x1,y1,x2,y2){}
    bool move() const;
};

bool B::move() const {
    if(!bound()){return false;}
    if(abs(x1_-x2_) == abs(y1_-y2_)) {
        return true;
    }else{
        return false;
    }
}


class R : public Figure{ //Rook
    public:
    R(int x1,int y1,int x2,int y2):Figure(x1,y1,x2,y2){}
    bool move() const;
};

bool R::move() const {
    if(!bound()){return false;}
    if(abs(y1_-y2_)>=1 && x1_==x2_) {
        return true;
    }else if(abs(x1_-x2_)>=1 && y1_==y2_) {
        return true;
    }else{
        return false;
    }
}


class Parser{
    private:
        char fig_;
        int x1,y1,x2,y2;
    public:
        Parser(const char * str):fig_(str[0]),x1(str[2]-'a'+1),y1(str[3]-'0'),x2(str[5]-'a'+1),y2(str[6]-'0'){}
        char getFig() const {return fig_;}
        int getX1() const {return x1;}
        int getY1() const {return y1;}
        int getX2() const {return x2;}
        int getY2() const {return y2;}
};


class ChessChecker{
    private:
        Figure* figures;
        char * str;
    public:
        ChessChecker(){
            Parser p(gs());
            
            switch (p.getFig()) {
                case ('K'):
                    figures = new K(p.getX1(),p.getY1(),p.getX2(),p.getY2());
                    break;
                case ('Q'):
                    figures = new Q(p.getX1(),p.getY1(),p.getX2(),p.getY2());
                    break;
                case ('N'):
                    figures = new N(p.getX1(),p.getY1(),p.getX2(),p.getY2());
                    break;
                case ('B'):
                    figures = new B(p.getX1(),p.getY1(),p.getX2(),p.getY2());
                    break;
                case ('R'):
                    figures = new R(p.getX1(),p.getY1(),p.getX2(),p.getY2());
                    break;
                default:
                    break;
            }  
        };
        ~ChessChecker(){delete [] str;delete figures;}
        char* gs(){
            str = new char[8];cin.getline(str,8);return str;
        };
        bool check() const{if(figures->move()){return true;}else{return false;}}
};

int main(){
    ChessChecker checker;
    if(checker.check()){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}
