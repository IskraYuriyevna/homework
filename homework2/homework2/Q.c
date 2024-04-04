#include <stdio.h>

int main(){
    int sum=0,cnt=0, c=1;
    while(c){
        scanf("%d",&c);
        cnt++;
        sum = sum+c;
    }
    //printf("cnt=%d ,",cnt);
    //printf("sum=%d",sum);
    sum = ((cnt)*(cnt+1)/2)-sum;
    printf("%d",sum);
    return 0;
}