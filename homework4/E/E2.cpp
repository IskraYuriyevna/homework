#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

unsigned long left(unsigned long num, int N) {
    if (N <= 0) {
        return 0; 
    }
    int len = 0;
    //unsigned long result = num;
    len = floor(log10(num)+1);
    if (N >= len) {
        return num;
    }
    for (int i = len - N; i > 0; i--) {
        num /= 10;
    }
    return num;
}

char* left(char* str, int N) {
    static char result[101] = {0};
    int len = strlen(str);
    if (len == 0 || N <= 0) {
        result[0] = '\0';
        return result;
    }
    if (N >= len) {
        return str;
    }
    for(int i = 0;i<N;i++){result[i]=str[i];}
    result[N] = '\0';
    return result;
}

int main(){
    string type;char str[101],ch;unsigned long num;int N;
    cin >> type;cin.get(ch);

    if(type=="string"){
        cin.get(str,100);
        cin >> N;
        //cout << str << endl;
        char* result = left(str,N);
        if(result){
            cout << result << endl;
        }
    }else if(type=="number"){
        cin >> num;
        cin >> N;
        cout << left(num,N) << endl;
    }

    return 0;
}