#include<iostream>
using namespace std;

int main(){
    int var_a = 32;
    int var_b = 64;
    const int* ptr = &var_a;
    var_a++;
    //*ptr = 3;
    ptr = &var_b;

    int* const cptr = &var_a;
    *cptr = 8;
    //cptr = &var_b;

    const double pi = 3.1415926;
    //double* ptr_pi = &pi;
    const double* ptr_pi = &pi;

    int i = 9;
    int& ref_i = i;
    const int& ref = 1;
    i++;
    ref_i--;
    //ref++;

    const int j = 12;
    //int& ref_j = j;
    const int& ref_const = j;
    
    return 0;
}