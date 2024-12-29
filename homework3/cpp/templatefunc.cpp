#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <stdexcept>

using namespace std;

//这里是一个泛型函数，返回两个数中的最大值
template <typename T>
inline T const& Max(T const& a,T const& b)
{
    return a < b ? b:a;
}
//其中 T 是数据类型的占位符名称

//这是一个泛型类Stack,并且实现泛型方法对元素进行入栈和出栈的操作
template <class T> class Stack {
    private:
        vector<T> elems;  

    public:
        void push(T const&);//入栈的函数
        void pop();//出栈的函数
        T top() const;//返回栈顶元素的函数
        bool empty() const{
            return elems.empty();
        }
};

template <class T> void Stack<T>::push(T const& elem){
    //追加传入元素的副本
    elems.push_back(elem);
}

template <class T> void Stack<T>::pop(){
    if (elems.empty()) {
        throw out_of_range("Stack<>::top(): empty stack!");
    }
    //返回并删除最后一个元素的副本
    return elems.pop_back();
}

template <class T> T Stack<T>::top() const{
    if (elems.empty()) {
        throw out_of_range("Stack<>::top(): empty stack!");
    }
    //返回最后一个元素的副本
    return elems.back();
}


//下面是main函数
int main(){
    //下面是对泛型函数的演示
    //对两个整数的比较
    int i =30;
    int j =20;
    cout << "Max(i,j): " << Max(i,j) << endl;

    //对两个浮点数的比较
    double f1 = 13.5;
    double f2 = 20.7;
    cout << "Max(f1,f2): " << Max(f1,f2) << endl;

    //对两个字符串的比较
    string s1 = "Hello";
    string s2 = "World";
    cout << "Max(s1,s2): " << Max(s1,s2) << endl;

    //下面是对泛型类的演示
    try{
        Stack<int> intStack; // int类型的栈
        Stack<string> stringStack; //string类型的栈

        //操作int类型的栈
        intStack.push(7);
        cout << intStack.top() << endl;
        //操作string类型的栈
        stringStack.push("hello");
        cout << stringStack.top() << std::endl;
        stringStack.pop();
        stringStack.pop();

    }
    catch (exception const& ex) {
        cerr << "Exception: " << ex.what() << endl;
        return -1;
    }

}