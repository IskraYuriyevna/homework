#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

template<class T>
class Set{
    private:
        vector<T> set;
    public:
        Set(){}
        Set(T* arr,int size);
        ~Set(){}
        void add(const T& i);
        void add(const T* arr,int size);
        void del(const T& i);
        bool in(const T& i)const;
        void print()const;
        Set operator*(const Set& op)const;
        Set operator+(const Set& op)const;
}; 

template<class T>
Set<T>::Set(T* arr,int size){
    for(int i=0;i<size;i++){
        add(arr[i]);
    }
}

template<class T>
void Set<T>::add(const T& i){

}

template<class T>
void Set<T>::add(const T* arr,int size){
    for(int i=0;i<size;i++){
        add(arr[i]);
    }
}

template<class T>
void Set<T>::del(const T& i){

}

template<class T>
bool Set<T>::in(const T& i)const{

}

template<class T>
void Set<T>::print()const{
    
}

template<class T>
Set<T> Set<T>::operator*(const Set& op)const{

}

template<class T>
Set<T> Set<T>::operator+(const Set& op)const{

}