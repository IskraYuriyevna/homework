#include<iostream>

using namespace std;

void print(double x)
{
    cout << "type: double " << "value: " << x << endl;
}

void print(int a)
{
    cout << "type: int " << "value: " << a << endl;
}

void print(int b,long c)
{
    cout << "type: int long " << "value: " << b << " " << c << endl;
}

void print(char *str)
{
    cout << "type: c-string " << "value: " << str << endl;
}

void print(const char *str)
{
    cout << "type: const string " << "value: " << str << endl;
}

// int main(){
//     char str[50] = "hello";
//     print(3);
//     print(3.14);
//     print(4,3);
//     print(str);
//     print("hello");
//     return 0;
// }
