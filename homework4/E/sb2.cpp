#include<iostream>
using namespace std;

struct Pers{
    char name[20];
    int num_int;
    double num_double;
};

void Swap(int a , int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void Swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

template <typename T>
void Swap(T& a, T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
    cout << "Type T << endl";
};

template<>
void Swap(Pers& a,Pers& b)
{
    int tmp1 = a.num_int;
    double tmpd = a.num_double;
    a.num_int = b.num_int;
    a.num_double = b.num_double;
    b.num_int = tmp1;
    b.num_double = tmpd;
}

template<typename T>
void Print(T *arr ,int n)

void Swap(Pers& a,Pers b){
    int tmpi = a.num_int;
    double tmpd = a.num_double;
    a.num_int = b.num_int;
    a.num_double = b.num_double;
    b.num_int;

}

template<typename T>
void Print(T *arr,int n){
    for(int i = 0;i<n;i++)
        cout << arr[i] << " ";
    cout << endl;
}

template<typename Type>
void Swap(Type* arr1,Type* arr2, int n)
{
    for(int i = 0;i<n;i++){
        Type tmp = arr1[i];
        arr1[i] = 
        arr2[i] = 
    }
    cout << "Type" ;
}


int main(){
    int i = 45 , j = 98;
    cout << "i = " << i << " j = " << j << endl;
    //Swap(i,j);
    Swap<int>(i,j);
    cout << "i = " << i << " j = " << j << endl;
    double x = 3.14,y = 2.7;
    cout << "x = " << x << " y = " << y << endl;
    Swap(x,y);
    cout << " x = " << x << " y = " << y << endl;
    double *arr1,*arr2;
    arr1 = new double[5];
    arr2 = new double[5];

    for(int i = 0;i<5;i++){
        arr1[i] = i+i;
        arr2[i] = 10-i;
    }
    Print(arr1, 5);
    Swap(arr1,arr2);
    Print(arr1,5);Print(arr2,5);
    int arr[];
    int arr[];

    Pers p1 = {"A",23,3.14};
    Pers p2 = {"B",56,2.7};

    cout<<p1.name<< " "<<p1.num_int << " "<<p1.num_double <<endl;
    cout<<p1.name<< " "<<p1.num_int << " "<<p1.num_double <<endl;
    Swap(p1,p2);
    cout<<p1.name<< " "<<p1.num_int << " "<<p1.num_double <<endl;
    cout<<p2.name<< " "<<p2.num_int << " "<<p2.num_double <<endl;

    return 0;
}