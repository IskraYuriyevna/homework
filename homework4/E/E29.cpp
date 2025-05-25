#include<iostream>
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
        void print();
        Set operator*(const Set& op)const;
        Set operator+(const Set& op)const;
        void ins_sort();
}; 

template<class T>
void Set<T>::ins_sort(){
    int n = set.size();
    for(int i = 1;i<n;i++){
        T key = set[i];
        int j  = i - 1;
        while(j>=0 && set[j]>key)
        {
            set[j+1]=set[j];
            j--;
        }
        set[j+1] = key;
    }
}

template<class T>
Set<T>::Set(T* arr,int size){
    for(int i=0;i<size;i++){
        add(arr[i]);
    }
}

template<class T>
void Set<T>::add(const T& i){
    if(!in(i)){
        set.push_back(i);
    }
}

template<class T>
void Set<T>::add(const T* arr,int size){
    for(int i=0;i<size;i++){
        add(arr[i]);
    }
}

template<class T>
void Set<T>::del(const T& i){
    for(int j=0;j<set.size();j++){
        if(set[j]==i){
            set.erase(set.begin()+j);
        }
    }
}

template<class T>
bool Set<T>::in(const T& i)const{
    for(int j=0;j<set.size();j++){
        if(set[j]==i){
            return true;
        }
    }
    return false;
}

template<class T>
void Set<T>::print(){
    ins_sort();
    for(int j=0;j<set.size();j++){
        cout << set[j] << " ";
    }
    cout << endl;
}

template<class T>
Set<T> Set<T>::operator*(const Set& op)const{
    Set res;
    for(int j=0;j<set.size();j++){
        for(int k=0;k<op.set.size();k++){
            if(set[j]==op.set[k]){
                res.add(set[j]);
                break;
            }
        }
    }
    return res;
}

template<class T>
Set<T> Set<T>::operator+(const Set& op)const{
    Set res;
    for(int j=0;j<set.size();j++){
        res.add(set[j]);
    }
    for(int j=0;j<op.set.size();j++){
        res.add(op.set[j]);
    }
    return res;
}
