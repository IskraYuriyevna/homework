#include <stdio.h>

int main(){
    char ca[26]={0};char c;
    while((c = getchar())!='.'){
        ca[c-97]++;
    }
    for(int i=0;i<26;i++){
        if(ca[i]==0){
            continue;
        }else{
            printf("%c%d",i+97,ca[i]);
        }
    }

    return 0;
}