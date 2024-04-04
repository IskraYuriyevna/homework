#include <stdio.h>

int num,i=2;

void printPrime(int n){
    num =n;
    if (n<=1) {
        return;
    }else{
        while(1){
            if(num%i == 0){
                num = num / i;
                printf("%d ",i);
            }else{
                break;
            }
        }
        i++;
    }
    
    printPrime(num);
}

int main(){
    int npt;
    scanf("%d",&npt);
    printPrime(npt);

    return 0;
}