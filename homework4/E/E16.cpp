#include<iostream>
#include<string>
using namespace std;

class Person{
    public:
        Person(const char* firstname,const char* lastname,int age);
        void ChangeAge(int new_age){age_ = new_age;}
        virtual void Print() const;
        virtual ~Person() {/*cout <<" Destr Person" << endl;*/}
    private:
        string firstname_;
        string lastname_;
    protected:
        int age_;
};

void Person::Print() const{
    cout << "Name: " << firstname_;
    cout << " LName: " << lastname_;
    cout << " Age: " << age_ << endl;
}

Person::Person(const char* firstname,const char* lastname,int age){
    firstname_ = firstname;
    lastname_ = lastname;
    age_ = age;
    //cout << " Constr Person " << endl;
}

class Student : public Person{
    public:
        Student(const char* firstname,const char* lastname,int age , double grade):Person(firstname,lastname,age),grade_(grade){
            //cout << " Constr Student "<< endl;
        }
        virtual void Print() const;
        bool Bonus() const;
        virtual ~Student(){/*cout << "Destr Student" << endl;*/}
    private:
        double grade_;
};

bool Student::Bonus() const{
    if(age_ >= 18 && grade_>= 4.5) return true;
    else return false;
}

void Student::Print() const{
    Person::Print();
    cout << "Grade: " << grade_ << endl;
}

