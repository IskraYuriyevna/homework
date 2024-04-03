#include <stdio.h>

int main(){
    int i,num,fac=1;
    scanf("%d",&num);
    for(i=1;i<=num/2;i++){
        if(num%i==0){
            fac=i;
        }else{
            continue;
        }
    }
    printf("%d",fac);
    return 0;
}