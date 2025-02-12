#include<iostream>
using namespace std;
void func(const char *arr){
    cout << arr <<endl;
}

void func(const char *arr,int n){
    for(int i=0;i<n;i++){
       cout << arr <<endl; 
    }
}
void func(double f){
    cout << f*2 << endl;
}

void func(double f,int n){
    cout << f*n <<endl;
}

void func(int* arr,int n){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    cout << sum << endl;
}

void func(double* arr,int n){
    double sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    cout << sum << endl;
}

