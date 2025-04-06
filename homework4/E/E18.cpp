#include<iostream>
#include<cmath>
using namespace std;

class BaseEllipse{
    public:
        BaseEllipse(double x , double y): x_(x),y_(y) {}
        //函数之后是初始化列表，直接将参数变量赋值给成员变量，这样不必在构造函数体内赋值
        //另外无默认构造函数的类类型成员必须初始化
        //类成员变量按照声明顺序而非初始化列表中的顺序初始化
        void Move(double sh_x,double sh_y){x_ += sh_x;y_ += sh_y;
        }
        virtual void Print() const {cout << "(" << x_ << "," << y_ << ")";}
        virtual double Area() const = 0;//virtual function need to clear
        //纯虚函数，必须在派生类中实现，而含有纯虚函数的基类无法实例化（称为抽象类）
    private:
        double x_,y_;
};

class Circle : public BaseEllipse
{
    public:
        Circle(double x,double y,double r) : BaseEllipse(x,y),r_(r){}
        //初始化基类和半径
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

//注意，初始化只能进行一次，否则会编译错误
//派生类的构造函数中，基类构造函数必须显式或者隐式地被调用
//若不显式调用，会调用基类的默认（无参）构造函数，若基类没有这样的构造函数将会报错。
//由于引用在声明时必须初始化且无法重新绑定，而构造函数体中对引用的赋值是赋值操作，而这种操作是不允许的。
