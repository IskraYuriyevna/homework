#include<iostream>
#include<cstring>
using namespace std;

class mstring{
    private:
        char* string_;
        int length_;
    public:
    mstring(){

    }
    mstring(){

    }
    mstring(const char* str){

    }
    ~mstring(){

    }


    int length();
    bool isempty();
    void add(char c);
    void add(const char* c);
    void insert(char c,int i);
    void insert(const char* c,int i);
    void del(int i);
    void del(int i, int j);
    int search(const char* str);
    void print();

};




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