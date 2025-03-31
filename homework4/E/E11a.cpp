#include <iostream>
#include <cmath>

using namespace std;
class Vec {
	private:
					double *v;
					int len;
	public:
					Vec(int l,const double *v_ptr =nullptr);
					Vec(const Vec & ob);
					~Vec();
					void set(double arg,int coord);
					double get(int coord) const;
					double euc_norm() const;
					double max_norm() const;
					void print() const;
					// +
					Vec operator + (const Vec & op) const;
					// -
					Vec operator - (const Vec & op) const;
					// *
					Vec operator * (double a) const;
					friend Vec operator * (double a,const Vec & op);
					// =
					const Vec & operator = (const Vec & op);
					// ==
					bool operator == (const Vec & op) const;
					// []
					double & operator [] (int index);
					// <<
					friend ostream & operator << (ostream & os,const Vec & op);
};
bool Vec::operator == (const Vec & op) const{
	if(len!=op.len) return false;
	for(int i = 0;i<len;i++){
		if(v[i]!=op.v[i]) return false;
	}
	return true;
}
double & Vec::operator [] (int index){
		return v[index];
}
Vec Vec::operator + (const Vec & op) const{
		Vec tmp(len);		
		for(int i = 0;i<len;i++) tmp.v[i] = v[i]+op.v[i];
		return tmp;
}
Vec Vec::operator - (const Vec & op) const{
		Vec tmp(len);
    for(int i = 0;i<len;i++) tmp.v[i] = v[i]-op.v[i];
    return tmp;
}
Vec Vec::operator * (double a) const{
		Vec tmp(len);
    for(int i = 0;i<len;i++) tmp.v[i] = v[i]*a;
    return tmp;
}
Vec operator * (double a,const Vec & op){
		Vec tmp(op.len);
    for(int i = 0;i<op.len;i++) tmp.v[i] = a*op.v[i];
    return tmp;
}
const Vec & Vec::operator = (const Vec & op){
	if(this==&op) return *this;
	delete [] v;
	len = op.len;
	v = new double[len];
	for(int i = 0;i<len;i++) v[i]=op.v[i];
	return *this;
}
ostream & operator << (ostream & os,const Vec & op){
    os << "(";
    for(int i = 0;i<op.len;i++){ if(i) os << ","; os << op.v[i]; }
    os << ")";
		return os;
}
Vec::Vec(int l,const double *v_ptr){
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
int main(void){
				double y1[4] = {1.0,2.0,3.0,4.0};
        double y2[4] = {-2.0,1.0,3.0,-3.0};
        double y3[3] = {1.0,1.0,1.0};
	
        Vec u(4, y1), v(4, y2);
        Vec w(4);
				Vec z(3,y3);
				
        cout << "u = " << u << endl;
        cout << "v = " << v << endl;
        w = u = u;
        cout << "w = u = " << w << endl;
				w = z;
				cout << "w = z = " << w << endl;
				w = 4.*u + v*3;
        cout << "w = 4.*u + v*3 = " << w << endl;
        w[2] = 3;
        w[0] = -1;
        cout << "w = " << w << endl;
				return 0;
}
*/