#include<iostream>
#include<string>
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
        int errno_;
    public:
        WrongNumber(const char* comment):comment_(comment){}

};

class Player{
    private:
        string team_;
        int number_;
        static int players_[12];
    public:
        Player();
        ~Player();
        void Print();
        void Print_teams();
};


int main()
{
    try {

    }catch () {
        
    }
}
