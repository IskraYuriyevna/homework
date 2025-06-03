#include<iostream>
#include<cmath>
using namespace std;


class Exception{
    private:
        string comment_;
    public:
        Exception(const char* comment):comment_(comment){}
        Exception(const Exception &other){comment_ = other.comment_;}
        ~Exception(){}
        const string GetComment() const {return comment_;}
};

class Root{
    protected:
        double r1_,r2_;
    public:
        Root();
        ~Root();
        virtual void find_roots()=0;
        virtual void print_roots(); 
};

class Linear:public Root{
    private:
        double a_,b_;
    public:
        Linear(double a,double b):a_(a),b_(b){};
        void find_roots();
        void print_roots(){cout<< r1_ <<endl;}
};

void Linear::find_roots(){
    double root;
    if(a_==0){
        if(b_==0){
            throw Exception("infinite many roots");
        }else{
            throw Exception("no roots");
        }
    }else{
        r1_ = -b_/a_;
    }
}

class Square:public Root{
    private:
        double a_,b_,c_;
    public:
        Square(double a,double b,double c):a_(a),b_(b),c_(c){};
        void find_roots();
        void print_roots(){cout << r1_ << r2_ << endl;}
};

void Square::find_roots(){
    double delta = b_*b_ - 4*a_*c_;
    if(a_==0){
        throw Exception("infinitely many roots");
    }else{
        if(delta< 0){
            throw Exception("no roots");
        }else{
            double tmp1 = (-b_+sqrt(delta))/2*a_;
            double tmp2 = (-b_-sqrt(delta))/2*a_;
            if(tmp1>tmp2){
                r1_ = tmp1;r2_ = tmp2;
            }else{
                r1_ = tmp2;r2_ = tmp2; 
            }
        }
    }
}

int main(){
    try{
       Solution(); 
    }catch(Exception &ex){
        cerr << "Exception:" << ex.GetComment() << endl;
    }catch(...){
        cerr << "Exception: unknown error" << endl;
    }
    return 0;
}

