#include<iostream>
#include<cmath>
using namespace std;

class Base{
    private:
        double x_,y_,z_; // center
    public:
        Base(double x,double y,double z):x_(x),y_(y),z_(z){}
        Base(const Base& src):x_(src.x_),y_(src.y_),z_(src.z_){}
        ~Base(){}
        void move(double x,double y,double z){x_=x;y_=y;z_=z;}
        virtual void print()const{ cout<< "(" << x_ << "," << y_ << "," << z_ << ")";}
        virtual double volume()const=0;
        virtual double area()const=0;
};


class cube : public Base{
    private:
        double l_; //side length
    public:
        cube(double x,double y,double z,double l):Base(x,y,z),l_(l){}
        cube(const cube& src):Base(src),l_(src.l_){}
        ~cube(){}
        void print() const{
            Base::print();
            cout << " l=" << l_ << endl;
        };
        double volume() const{return l_*l_*l_;}
        double area()const{return l_*l_*6;}
};

class ball : public Base{
    private:
        double r_; // radius
    public:
        ball(double x,double y,double z,double r):Base(x,y,z),r_(r){}
        ball(const ball& src):Base(src),r_(src.r_){}
        ~ball(){}
        void print() const{
            Base::print();
            cout << " r=" << r_ << endl;
        };
        double volume() const{return 4*M_PI*r_*r_*r_/3;}
        double area()const{return 4*M_PI*r_*r_;}
};

class cylinder : public Base{
    private:
        double r_,h_; // radius and height
    public:
        cylinder(double x,double y,double z,double r,double h):Base(x,y,z),r_(r),h_(h){}
        cylinder(const cylinder& src):Base(src),r_(src.r_),h_(src.h_){}
        ~cylinder(){}
        void print() const{
            Base::print();
            cout << " r=" << r_ << " h=" << h_ <<endl;
        };
        double volume() const{return M_PI*r_*r_*h_;}
        double area()const{return M_PI*r_*r_*2 + 2*M_PI*r_*h_;}
};

