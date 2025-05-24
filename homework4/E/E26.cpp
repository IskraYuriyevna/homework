#include<iostream>
#include<cstring>
using namespace std;

template<typename T>
T maxn(T* arr,int len)
{
    T max=arr[0];
    for(int i=1;i<len;i++){
        if(arr[i]>max){max=arr[i];}
    }
    return max;
};

template <>
const char* maxn(const char** arr,int len)
{
    const char* max = arr[0];
    for(int i=1;i<len;i++){
        if(strlen(arr[i])>strlen(max)){max = arr[i];}
    }
    return max;
}
