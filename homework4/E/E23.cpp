#include<iostream>
#include<string>
using namespace std;

class Flower{
    private:
        static int wcnt_,pcnt_;
        string colour_;
    public:
        Flower(string colour="",int petal=10);
        ~Flower();
        static void Print_flowers(){cout << "White: " << wcnt_ << " Pink: " << pcnt_ <<endl;};
};
int Flower::wcnt_=0;
int Flower::pcnt_=0;

Flower::Flower(string colour,int petal)
{
    if(colour=="white"){
        colour_ = "white";
        wcnt_++;
    }else if(colour=="pink"){
        colour_ = "pink";
        pcnt_++;
    }else{
        if(wcnt_>pcnt_){
            colour_ = "pink";
            pcnt_++;
        }else if(wcnt_<pcnt_){
            colour_ = "white";
            wcnt_++;
        }else{
            if(petal%2==0){
                colour_ = "pink";
                pcnt_++;
            }else{
                colour_ = "white";
                wcnt_++;
            }
        }
    }
}

Flower::~Flower()
{
    if(colour_=="pink"){
        pcnt_--;
    }else if(colour_=="white"){
        wcnt_--;
    }
}

