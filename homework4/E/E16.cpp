#include<iostream>
#include<string>
using namespace std;

class Person{
    public:
        Person(const char* firstname,const char* lastname,int age);
        void ChangeAge(int new_age){age_ = new_age;}
        virtual void Print() const;
        //虚函数，用于多态输出，析构虚函数用于确保派生类对象销毁时正确调用析构链
        virtual ~Person() {/*cout <<" Destr Person" << endl;*/}
    private://私有字符串，存储姓名
        string firstname_;
        string lastname_;
    protected://protected字段可以由派生类的内部函数访问
        int age_;
};

//实现virtual函数Print
void Person::Print() const{
    cout << "Name: " << firstname_;
    cout << " LName: " << lastname_;
    cout << " Age: " << age_ << endl;
}

//构造函数的实现
Person::Person(const char* firstname,const char* lastname,int age){
    firstname_ = firstname;
    lastname_ = lastname;
    age_ = age;
    //cout << " Constr Person " << endl;
}

//派生类Student
class Student : public Person{
    public:
        Student(const char* firstname,const char* lastname,int age , double grade):Person(firstname,lastname,age),grade_(grade){
            //cout << " Constr Student "<< endl;
        }
        virtual void Print() const;
        bool Bonus() const;
        virtual ~Student(){/*cout << "Destr Student" << endl;*/}
    private:
        double grade_;
};

//Student类专有的函数Bonus
bool Student::Bonus() const{
    if(age_ >= 18 && grade_>= 4.5) return true;
    else return false;
}

//Stundent类的Print方法覆盖
//c++
void Student::Print() const{
    Person::Print();
    cout << "Grade: " << grade_ << endl;
}

//注意：构造函数不能是虚函数，而析构函数应该为虚函数
//虚函数覆盖时签名必须完全匹配，参数类型，数量和顺序必须完全一致
//纯虚函数和抽象类：通过虚函数 = 0语法声明，不可实例化
//如果派生类函数与基类虚函数名称相同而参数不同，会隐藏基类虚函数（而非覆盖）
//C++11之后，需要显示的用override关键字进行显式的覆盖void fn() override {}
