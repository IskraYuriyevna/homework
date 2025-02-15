#include<iostream>
#include<cstring>
using namespace std;

char* left(char* str,int N){
    if(strlen(str)>N){return 0;};
    ;
}

int left(unsigned long num,int N){
    
    ;
}

int main(){
    string type;char str2[101],ch;int num,N;
    cin >> type;cin.get(ch);

    if(type=="string"){
        cin.getline(str2,100);
        cin >> N;
        cout << left() << endl;
    }else if(type=="number"){
        cin >> num;
        cin >> N;
        cout << left(num,N) << endl;
    }
    return 0;
}