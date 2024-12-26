# include <iostream>
using namespace std;

class Line
{
    public:
    void setLength(double len);
    double getLength(void);
    Line(double len); //构造函数的声明
    ~Line(); //析构函数的声明
    
    private:
    double length;
};

//使用初始化列表来初始化字段
Line::Line(double len):length(len)
{
    cout << "Object is being created" << endl;
}

Line::~Line(void)
{
    cout << "Object is being deleted" << endl;
}

