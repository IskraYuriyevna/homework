#include <iostream>
using namespace std;

//重载函数
class printData
{
    public:
        void print(int i){
            cout<< "整数为：" << i << endl;
        }

        void print(double f){
            cout << "浮点数为：" << f << endl;
        }

        void print(char c[]){
            cout << "字符串为：" << c << endl;
        }
};


//重载运算符
class Box
{
    public:

        double getVolume(void)
        {
            return length * breadth * height;
        }
        void setLength(double len)
        {
            length = len;
        }
        void setBreadth(double bre)
        {
            breadth = bre;
        }
        void setHeight(double hei)
        {
            height = hei;
        }
        Box operator+(const Box& b)
        {
            Box box;
            box.length = this->length+b.length;
            box.breadth = this->breadth+b.breadth;
            box.height = this->height+b.height;
            return box;
        }

    private:
        double length,breadth,height;
};


int main(void)
{
    printData pd;

    //
    pd.print(5);
    //
    pd.print(500.253);
    //
    char c[] = "Hello C++";
    pd.print(c);

    return 0;



    //重载运算符
    Box Box1;
    Box Box2;
    Box Box3;
    double volum;

};