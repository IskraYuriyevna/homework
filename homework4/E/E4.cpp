#include<iostream>
#include<cmath>
using namespace std;

class Vector_3d{
    public:
    Vector_3d(double arg_x,double arg_y, double arg_z){
        x = arg_x;
        y = arg_y;
        z = arg_z;
    }
    Vector_3d(double arg_x){
        x = arg_x;
        y = 0;
        z = 0;
    }
    Vector_3d(){
        x = 0;
        y = 0;
        z = 0;
    }

    void print() const{
        cout << '(' << x << ',' << y << ',' << z << ')' << endl;
    }
    void set(double arg_x,double arg_y, double arg_z){
        x = arg_x;
        y = arg_y;
        z = arg_z;
    }  

    double get_x() const{
        return x;
    }

    double get_y() const{
        return y;
    }

    double get_z() const{
        return z;
    }    
    double euc_norm() const{
        double eucn;
        eucn = sqrt(x*x+y*y+z*z);
        return eucn;
    }

    double max_norm() const{
        double maxn;
        maxn = max(max(abs(x),abs(y)),abs(z));
        return maxn;
    }
    
    private:
        double x;
        double y;
        double z;
};

// int main()
// {
//      Vector_3d v(1.5, 2.4, 3.);
//      Vector_3d w, u = 2.;
//      v.print();
//      w.print();
//      u.print();
//      cout << "norma euc v = " << v.euc_norm() << endl;
//      w.set(1,2,3);
//      cout << "norma max w = " << w.max_norm() << endl;
//      cout << " u_x = " << u.get_x() << endl;
//      cout << " w_y = " << w.get_y() << endl;
//      cout << " v_z = " << v.get_z() << endl;
//      return 0;
// }

