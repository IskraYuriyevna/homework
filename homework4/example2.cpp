#include<iostream>

int a = 5;

namespace CL {
    int a = 8;
    int b = 10;
    void func() { std::cout << "CL function" << std::endl; }
}

int main(){
    int a = 9;
    std::cout << "local a = " << a << std::endl;
    std::cout << "global a = " << ::a << std::endl;
    std::cout << "CL a = " << CL::a << std::endl;
    CL::func();
    using CL::b;
    std::cout << "b = " << b <<std::endl;
    return 0;
}

