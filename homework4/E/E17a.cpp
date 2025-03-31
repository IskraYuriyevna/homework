
#include <iostream>
#include <cstring>
using namespace std;
class event{
private:
    char * info_;
    int y_,m_,d_;
    char * strdup(const char * info) const;
public:
    explicit event(const char * info,int y,int m,int d):info_(strdup(info)),y_(y),m_(m),d_(d){}
    event(const event & other): info_(strdup(other.info_)),y_(other.y_),m_(other.m_),d_(other.d_){}
    virtual ~event(){delete [] info_;}
    virtual void print_res() const { cout << info_ << " " << y_ << " " << m_ << " " << d_; };
    void change_date(int new_year,int new_month,int new_day);
    virtual void change_grade(bool grade){}
    virtual void change_grade(int grade)=0;//чистая виртуальная функция
};
char * event::strdup(const char * info) const{
    char * res = new char[strlen(info)+1];
    strcpy(res,info);
    return res;
}
void event::change_date(int new_year, int new_month, int new_day){
    y_=new_year; m_=new_month; d_=new_day;
}
class test : public event{
private:
    bool grade_;
public:
    explicit test(const char * info,int y,int m,int d,bool grade): event(info,y,m,d),grade_(grade){}
    explicit test(const char * info,int y,int m,int d,int grade): event(info,y,m,d),grade_(grade >= 3){}
    test(const test & other): event(other),grade_(other.grade_){}
    void print_res() const;
    void change_grade(int grade){ grade_ = grade >= 3; }
    void change_grade(bool grade){ grade_ = grade; }
};
void test::print_res() const {
    event::print_res();
    if (grade_) cout << " true" << endl;
    else cout << " false" << endl;
}
class exam : public event{
private:
    int grade_;
public:
    explicit exam(const char * info,int y,int m,int d,int grade): event(info,y,m,d),grade_(grade){}
    exam(const exam & other): event(other),grade_(other.grade_){}
    void print_res() const;
    void change_grade(int grade){ grade_ = grade; }
};
void exam::print_res() const{
    event::print_res();
    cout << " Grade " << grade_ << endl;
}