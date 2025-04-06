#include<iostream>
using namespace std;

struct Pers
{
    char name[20];
    int num_int;
    double num_double;
};

//普通引用版本的Swap ， 通过引用int&直接修改原始变量
void Swap(int& a , int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

// void Swap(int *a, int *b)
// {
//     int tmp = *a;
//     *a = *b;
//     *b = tmp;
// }

//泛型模板，只要类型支持赋值操作就可以
template <typename T>
void Swap(T& a, T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
    //cout << "Type T" << endl;
};

//特化模板：针对Pers类型的特化模板，仅交换num_int和num_double,忽略name
template<>
void Swap(Pers& a,Pers& b)
{
    int tmpi = a.num_int;
    double tmpd = a.num_double;
    a.num_int = b.num_int;
    a.num_double = b.num_double;
    b.num_int = tmpi;
    b.num_double = tmpd;
}

//泛型模板的print
template<typename T>
void Print(T *arr ,int n)
{
    for(int i = 0;i<n;i++)
        cout << arr[i] << " ";
    cout << endl;
}

//泛型的数组交换函数
template<typename Type>
void Swap(Type* arr1,Type* arr2, int n)
{
    for(int i = 0;i<n;i++){
        Type tmp = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = tmp;
    }
    //cout << "Type* " <<endl;
}

//运行时，编译器会根据函数传入的实参类型来套入模板，或者使用类似于Swap<double>(x,y)的方法显示指定模板参数
//泛型模板template<typename T>仅适用于类型一致或可以兼容的情况，对于更多个类型，需要双类型模板template<typename T>或更多的类型
//或者通过特化的方式编写接受特定参数的情况
