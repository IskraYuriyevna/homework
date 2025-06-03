#include<iostream>

using namespace std;

template<class T>
class Set{
    private:
        T* set_;
        int size_;
        void ins_sort();

    public:
        Set(){set_ = nullptr;size_=0;}
        Set(T* arr,int size);
        Set(const Set& other);
        ~Set(){delete[] set_;};
        void add(const T& i);
        void add(const T* arr,int size);
        void del(const T& i);
        bool in(const T& i)const;
        void print();
        Set operator*(const Set& op)const;
        Set operator+(const Set& op)const;
        Set<T>& operator=(const Set& other);
        
}; 

template<class T>
Set<T>::Set(const Set& other):set_(new T[other.size_]),size_(other.size_){
    for (int i = 0;i<size_;i++) {
        set_[i] = other.set_[i];
    }
}

// template<class T>
// Set<T>::Set(T* arr,int size){
//     set_ = nullptr;
//     for(int i=0;i<size;i++){
//         add[i];
//     }
// }

// template<class T>
// Set<T>::Set(T* arr,int size){
//     set_ = new T[size];
//     for(int i=0;i<size;i++){
//         set_[i] = arr[i];
//     }
//     size_ = size;
// }

template<class T>
Set<T>::Set(T* arr, int size) {
    set_ = new T[size];   
    size_ = 0;

    for (int i=0;i<size;i++) {
        if (!in(arr[i])) {  
            set_[size_] = arr[i];
            size_++;
        }
    }
}

template<class T>
void Set<T>::ins_sort(){
    int n = size_;
    for(int i = 1;i<n;i++){
        T key = set_[i];
        int j  = i - 1;
        while(j>=0 && set_[j]>key)
        {
            set_[j+1]=set_[j];
            j--;
        }
        set_[j+1] = key;
    }
}


template<class T>
void Set<T>::add(const T& i){
    if(!in(i)){
        T* tmp = new T[size_+1];
        for(int j=0;j<size_;j++){
            tmp[j]=set_[j];
        }
        tmp[size_] = i;

        delete[] set_;
        set_ = tmp;
        size_ ++;
    }
}

template<class T>
void Set<T>::add(const T* arr,int size){
    for(int i=0;i<size;i++){
        add(arr[i]);
    }
}


//
template<class T>
void Set<T>::del(const T& i) {
    if(in(i)){
        int pos=-1;
        for (int j = 0; j < size_; ++j) {
            if (set_[j] == i) {
                pos = j;
                break;
            }
        }

        T* tmp = new T[size_ - 1];
        for (int j = 0; j < pos; ++j) {
            tmp[j] = set_[j];
        }
        for (int j = pos; j < size_ - 1; ++j) {
            tmp[j] = set_[j + 1];
        }

        delete[] set_;
        set_ = tmp;
        size_--;
    }
}

template<class T>
bool Set<T>::in(const T& i)const{
    for(int j=0;j<size_;j++){
        if(set_[j]==i){
            return true;
        }
    }
    return false;
}

template<class T>
void Set<T>::print(){
    ins_sort();
    for(int j=0;j<size_;j++){
        cout << set_[j] << " ";
    }
    cout << endl;
}

template<class T>
Set<T> Set<T>::operator*(const Set& op)const{
    Set res;
    for(int j=0;j<size_;j++){
        for(int k=0;k<op.size_;k++){
            if(set_[j]==op.set_[k]){
                res.add(set_[j]);
                break;
            }
        }
    }
    return res;
}

template<class T>
Set<T> Set<T>::operator+(const Set& op)const{
    Set res;
    for(int j=0;j<size_;j++){
        res.add(set_[j]);
    }
    for(int j=0;j<op.size_;j++){
        res.add(op.set_[j]);
    }
    return res;
}

template<class T>
Set<T>& Set<T>::operator=(const Set& other) {
    if (this != &other) {
        delete[] set_;
        size_ = other.size_;
        set_ = new T[size_];
        for (int i = 0; i < size_; ++i) {
            set_[i] = other.set_[i];
        }
    }
    return *this;
}
