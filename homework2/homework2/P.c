#include <stdio.h>

int main(){
    int ca[26]={0},odr[26]={0},o=0,i,j;char c;
    
    while((c = getchar())!='.'){
        o++;
        ca[c-'a']++;
        odr[c-'a'] = o;
        
    }
    for(i=1;i<=o;i++){

        for(j=0;j<26;j++){
            if(odr[j]==i){
                printf("%c%d",j+'a',ca[j]);
            }
        }
    }

    return 0;
}