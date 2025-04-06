//ball x y z r
//cube x y z l
//cylinder x y z r h
#include <iostream>
#include <cmath>
using namespace std;
class Base{
private:
    double x_,y_,z_;
public:
    Base(double x,double y,double z):x_(x),y_(y),z_(z){}
    Base(const Base & other):x_(other.x_),y_(other.y_),z_(other.z_){}
    virtual ~Base(){}
    void move(double x,double y,double z);
    virtual void print() const { cout << "(" << x_ << "," << y_ << "," << z_ << ")"; }
    virtual double volume() const = 0;
    virtual double area() const = 0;
};
void Base::move(double x,double y,double z) {x_=x;y_=y;z_=z;}
class ball : public Base{
private:
    double r_;
public:
    ball(double x,double y,double z,double r): Base(x,y,z),r_(r){}
    ball(const ball & other): Base(other),r_(other.r_){}
    void print() const;
    double volume() const { return M_PI*r_*r_*r_*4/3; };
    double area() const { return 4*M_PI*r_*r_; }
};
void ball::print() const {
    Base::print();
    cout << " r=" << r_ << endl;
}
class cube : public Base{
private:
    double l_;
public:
    cube(double x,double y,double z,double l): Base(x,y,z),l_(l){}
    cube(const cube & other): Base(other),l_(other.l_){}
    void print() const;
    double volume() const { return l_*l_*l_; };
    double area() const { return 6*l_*l_; }
};
void cube::print() const {
    Base::print();
    cout << " l=" << l_ << endl;
}
class cylinder : public  Base{
private:
    double r_,h_;
public:
    cylinder(double x,double y,double z,double r,double h): Base(x,y,z),r_(r),h_(h){}
    cylinder(const cylinder & other): Base(other),r_(other.r_),h_(other.h_){}
    void print() const;
    double volume() const { return M_PI*r_*r_*h_; };
    double area() const { return 2*M_PI*r_*h_+2*M_PI*r_*r_; }
};
void cylinder::print() const {
    Base::print();
    cout << " r=" << r_ << " h=" << h_ << endl;
}
