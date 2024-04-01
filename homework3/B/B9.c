#include<stdio.h>
#include<ctype.h>

int main(){
    int a,cntl=0,cntu=0;

    while ((a=getchar())!='\n'){
        if(islower(a)){cntl++;}
        else if(isupper(a)){cntu++;}
    }

    printf("%d %d",cntl,cntu);

    return 0;
}