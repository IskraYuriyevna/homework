#include<iostream>
#include<cmath>
using namespace std;

class BaseEllipse{
    public:
        BaseEllipse(double x , double y): x_(x),y_(y) {}
        void Move(double sh_x,double sh_y){x_ += sh_x;y_ += sh_y;
        }
        virtual void Print() const {cout << "(" << x_ << "," << y_ << ")";}
        virtual double Area() const = 0;//virtual function need to clear
    private:
        double x_,y_;
};

class Circle : public BaseEllipse
{
    public:
        Circle(double x,double y,double r) : BaseEllipse(x,y),r_(r){}
        virtual void Print() const;
        virtual double Area() const {return M_PI*r_*r_;}
    private:
        double r_;
};

void Circle::Print() const{
    BaseEllipse::Print();
    cout << " r = " << r_ << endl; 
}

class Ellipse : public BaseEllipse{
    public:
        Ellipse(double x, double y,double a,double b,double angle): BaseEllipse(x,y) , a_(a),b_(b),angle_(angle){}
        virtual void Print() const;
        virtual double Area() const {return M_PI*a_*b_;}
    private:
        double a_,b_,angle_;
};

void Ellipse::Print() const
{
    BaseEllipse::Print();
    cout << " a = " << a_ << " b = " << b_ << " angle = " << angle_ << endl;
}
