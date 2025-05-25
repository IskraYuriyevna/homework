#include<iostream>
#include<string>
#include <vector>
using namespace std;

class Exception{
    private:
        string comment_;
    public:
        Exception(const char * comment): comment_(comment){}
        Exception(const Exception & other): comment_(other.comment_){}
        ~Exception(){}
        const string GetComment() const { return comment_; }
    };

class WrongNumber : public Exception{
    private:
        string team_;
        int errno_;
    public:
        WrongNumber(const char* comment,string team,int no=0):Exception(comment),team_(team),errno_(no){}
        WrongNumber(const WrongNumber& other):Exception(other),team_(other.team_),errno_(other.errno_){};
        string GetTeam(){return team_;}
        int GetErrno(){return errno_;}
};

class WrongName: public Exception{
    private:
        string team_;
    public:
        WrongName(const char* comment,string team):Exception(comment),team_(team){}
        WrongName(const WrongName& other):Exception(other),team_(other.team_){};
        string GetTeam(){return team_;}
};

class Player{
    private:
        string team_;
        int number_;
        static vector<string> team;
    public:
        Player();
        ~Player();
        string team_;
        void Print();
        void Print_teams();
};




int main()
{
    try {

    }catch () {
        
    }
}
