#include<stdio.h>
#include<ctype.h>

int main(){
    int a, sum=0;

    while ((a=getchar())!='\n'){
        if (isdigit(a)){
            sum = sum+a-'0';
        }
    }
    printf("%d",sum);
    
    return 0;
}