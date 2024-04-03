#include<stdio.h>

int main(){
    unsigned int num,i,cnt=0;
    scanf("%d",&num);
    for(i=0;i<32;i++){
        if (num%2==1){
            cnt+=1;
            num = num>>1;
        }else{
            num = num>>1;
        }
    }
    printf("%d",cnt);
    
    return 0;
}