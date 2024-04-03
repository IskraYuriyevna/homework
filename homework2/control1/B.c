#include <stdio.h>

int main(){
    unsigned int num,cur,max=0,min=9;
    scanf("%u",&num);
    while(num>0){ 
        cur=num%10;
        if(cur>=max){
            max = cur;
        }
        if(cur<=min){
            min = cur;
        }
        num = num/10;
    }
    max = max - min;
    if(min == 9){
        printf("0");
    }else{
        printf("%u",max);
    }

    return 0;
}