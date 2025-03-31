#include <iostream>
#include <cmath>

using namespace std;
class Vec {
	private:
					double *v;
					int len;
	public:
                    //只能显示调用,不能隐式转换
                    explicit Vec(int l,double *v_ptr =nullptr);
                    //Vec a = 5; error add explicit
                    //Vec a(5); ok
					Vec(const Vec & ob);
					~Vec();
					void set(double arg,int coord);
					double get(int coord) const;
					double euc_norm() const;
					double max_norm() const;
					void print() const;
};
Vec::Vec(int l,double *v_ptr){
	v = new double[l];
	for(int i = 0;i<l;i++) v[i] = (v_ptr!=nullptr ? v_ptr[i] : 0.0);
	len = l;
}
Vec::Vec(const Vec & ob){
	v = new double[ob.len];
	for(int i=0;i<ob.len;i++) v[i] = (ob.v!=nullptr ? ob.v[i] : 0.0);
	len = ob.len;
}
Vec::~Vec(){
	if(v!=nullptr){ delete [] v; v = nullptr;}
}
void Vec::set(double arg,int coord){
	if(coord>=0 && coord <len) v[coord] = arg;
}
double Vec::get(int coord) const{
	if(coord>=0 && coord<len) return v[coord]; return 0.0;
}
double Vec::euc_norm() const{
	double sum = 0.0;
	for(int i=0;i<len;i++) sum+=(v[i]*v[i]); return sqrt(sum);
}
double Vec::max_norm() const{
	double max = fabs(v[0]);
	for(int i=1;i<len;i++) if(max<fabs(v[i])) max=fabs(v[i]); return max;
}
void Vec::print() const{
		cout << "(";
		for(int i = 0;i<len;i++){ if(i) cout << ","; cout << v[i]; }
		cout << ")" << endl;
}
/*
int main(){
    double y1[3] = {1,2,3};
    double y2[5] = {2,1,0,5,7};
    Vec x(3, y1), y(5, y2), z(4);
    Vec u = x;

    y.print();
    x.print();
    z.print();
    u.print();

    x.set(23, 2);  u.set(34, 1);  z.set(-3, 3);
    cout << "x[2] = " << x.get(2) << endl;
    cout << "u[1] = " << u.get(1) << endl;
    cout << "euc_norma y: " << y.euc_norm() << endl;
    cout << "max_norma z: " << z.max_norm() << endl;
    return 0;
}
*/

