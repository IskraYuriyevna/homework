#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int rpncalc(vector<string>tokens){
    stack<int> stk;
    int a,b;
    for(const string& token:tokens){
        //cout << token << endl;
        if (token=="+"){
            a = stk.top(); stk.pop();
            b = stk.top(); stk.pop();
            stk.push(a+b);
        }else if(token=="-"){
            a = stk.top(); stk.pop();
            b = stk.top(); stk.pop();
            stk.push(b-a);
        }else if(token=="*"){
            a = stk.top(); stk.pop();
            b = stk.top(); stk.pop();
            stk.push(a*b);
        }else if(token=="/"){
            a = stk.top(); stk.pop();
            b = stk.top(); stk.pop();
            stk.push(b/a);
        }else if(token=="@"){
            a = stk.top(); stk.pop();
            stk.push(0-a);
        }else{
            stk.push(stoi(token));
        }
    }

    return stk.top();
}

int main(){
    vector<string> tokens;
    string input;string token;
    getline(cin,input);

    for(char c : input){
        if(c == ' '){
            tokens.push_back(token);
            token.clear();
        }else if(c == '\n'){
            tokens.push_back(token);
        }else{
            token += c;
        }
        //cout << token << endl;
    }

    tokens.push_back(token);

    int result = rpncalc(tokens);
    
    cout << result << endl;

    return 0;
}