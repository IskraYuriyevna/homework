#include <iostream>
using namespace std;

class Shape{
    protected:
        int width,height;
    public:
        Shape(int a=0,int b = 0)//构造函数
        {
            width = a;
            height = b;
        }
        virtual int area()//虚函数，之后在多态里面会重新定义
        {
            cout << "Parent class area :"<< endl;
            return 0;
        }
};

class Rectangle : public Shape{
    public:
    Rectangle(int a=0,int b=0):Shape(a,b){}
    int area(){
        cout << "Rectangle class area :" << endl;
        return (width*height);
    }
};

class Triangle : public Shape{
    public:
    Triangle(int a=0,int b=0):Shape(a,b){}
    int area(){
        cout << "Triangle class area :" << endl;
        return (width*height/2);
    }
};

int main(){
    Shape *shape;
    Rectangle rec(10,7);
    Triangle tri(10,5);

    shape = &rec;//存储矩形的地址
    shape -> area();//计算矩形的面积
    shape = &tri;//存储三角形的地址
    shape -> area();//计算三角形的面积

    return 0;
}