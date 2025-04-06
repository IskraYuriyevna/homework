#include <atomic>
#include<iostream>
using namespace std;

class A{
    public:
        A(int x=0){y=x;count++;}
        static void print_st() {cout << "count = " << count << endl;
            //cout<<y;
        }
        void print() const{
            cout << "y = " << y << " const = " << count <<endl;
        }
        ~A() {count--;}
    private:
        int y;
        static int count;
};

int A::count = 0;

int main(){
    A::print_st();
    A a(5);
    a.print_st();
    A b;
    b.print_st();
    {
        A c;
        A::print_st();
    }
    return 0;
}