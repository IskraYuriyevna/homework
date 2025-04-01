#include <cmath>
#include<iostream>
using namespace std;

class Complex
{
    public:
        Complex(double arg_re=0,double arg_im=0){
            //cout << "create 2" << endl;
            re = arg_re;
            im = arg_im;
        }
        Complex(const Complex & ob){ 
            //拷贝构造函数，接受一个const引用参数，避免修改原对象，深拷贝成员变量re和im
            //cout <<"copy" << endl;
            re = ob.re;
            im = ob.im;
        }
        /*
        Complex(double arg_re){

            re = arg_re;
            im = 0.;
        }
        Complex()
        {
            re = 0.;
            im = 0.;
        }
        */
        void print() const
        //加入const保证不修改对象的状态
        {
            cout << re << "+" << im << "i" << endl;
        }
        double modulo() const
        {
            return sqrt(re*re+im*im);
        }
        double argument() const{
            return atan2(im,re);
        }
        double get_re() const {return re;}
        double get_im() const {return im;}
        ~Complex(){
            //cout << "delete" << endl;
        }
    private:
        double re;
        double im;
};

double pow2(Complex * z){
    //指针版本的pow2,通过->访问成员函数，需要确保指针非空
    return z->get_re()* z->get_re() + z->get_im() * z->get_im();
}

double pow2(const Complex & z){
    //引用版本的pow2函数，接受const类型的应用输入，避免拷贝并保证安全性（引用不能为空），const确保不修改对象
    return z.get_re()*z.get_re() + z.get_im()*z.get_im();
}
/*
指针Type* ptr;可以为空;而引用Type& ref = obj;必须初始化
指针可以重新绑定（ptr = &new_obj）;引用不能重新绑定，始终指向初始化对象
指针存储地址的值，并且本身也是一个占用相应空间大小的变量;引用是不占用额外存储空间的原对象别名
指针需要显式解引用*ptr；引用直接相当于原对象
指针可以进行算术运算；引用不支持计算
c++编译器要求引用必须初始化，如果强制将引用绑定到空指针将引起未定义的行为
*/

/*
double pow4(Complex z){
    return z.get_re()*z.get_re()+z.get_im()*z.get_im();
}
*/