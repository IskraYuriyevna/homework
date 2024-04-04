#include <stdio.h>
int cnt=0;

unsigned count1(unsigned n){
    if (n==0) {
        return 0;
    }else{
        cnt +=(n & 1);
        count1(n>>1);
        return cnt;
    }
     
}

int main(){
    int num;
    scanf("%d",&num);
    count1(num);
    printf("%d",cnt);

    return 0;
}