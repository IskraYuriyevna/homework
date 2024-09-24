#include<stdio.h>
int main(){
    int sum=0,n=0,num;
    while(1){
        scanf("%d",&num);
        if (num%1000==0){break;}
        sum = 0;
        while (num>=1){
            n=num%10;
            if (n!=5){sum = sum + n;}
            num=num/10;
        }
        printf("%d ",sum);
    } 
    
    return 0;
}