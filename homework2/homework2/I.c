#include<stdio.h>

int main(){
    int n=0;
    scanf("%d",&n);
    if (((n==1)||(n==2))||(n==1000)) {printf("1");}
    else if((n/1000)%2==0) {
        if(n%3==0) {printf("2");}
        else {printf("1");}
        }
        else {
        if(n%3==0) {printf("1");}
        else {printf("2");}
        }
}