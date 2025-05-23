#include<iostream>
#include<cstring>
using namespace std;

class event{
    private:
        char* event_;
        int y_,m_,d_;
    public:
        explicit event(const char* eve,int y,int m,int d):y_(y),m_(m),d_(d){
            char* event_= new char[strlen(eve)+1];
            strcpy(event_,eve);
        }
        event(const event& src):y_(src.y_),m_(src.m_),d_(src.d_){
            char* event_= new char[strlen(src.event_)+1];
            strcpy(event_,src.event_);
        }
        virtual ~event(){
            delete[] event_;
        }
        virtual void print_res()const{
            cout<< event_ << " " << y_ << " " << m_ << " " << d_; 
        }
        void change_date(int ny,int nm,int nd){y_ = ny;m_ = nm,d_ = nd;};
        virtual void change_grade(bool grade)=0;
        virtual void change_grade(int grade)=0;
        char* getevent()const{return event_;};
};


class test : public event{
    private:
        bool pass_;
    public:
        explicit test(const char* event_,int y,int m,int d,bool grade):event(event_,y,m,d),pass_(grade){}
        test(const test& src):event(src),pass_(src.pass_){
            char* event_= new char[strlen(src.getevent())+1];
            strcpy(event_,src.getevent());
        }
        void print_res()const;
        void change_grade(bool grade){pass_ = grade;};
};

void test::print_res()const{
    event::print_res();
    if(pass_){
        cout << " true" << endl;
    }else{
        cout << " false" << endl;
    }
}


class exam : public event{
    private:
        int grade_;
    public:
        explicit exam(const char *event_,int y,int m ,int d,int grade):event(event_,y,m,d),grade_(grade){}
        exam(const exam& src):event(src),grade_(src.grade_){}
        void print_res() const{
            event::print_res();
            cout << " Grade " << grade_ << endl;
        };
        void change_grade(int grade){grade_ = grade;}
};

