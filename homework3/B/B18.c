
#include <stdio.h>

int count_3(int num){
    int cnt = 0;
    while (num>0){
        if (num%10==3){
            cnt++;
        }
        num = num/10;
    }
    return cnt;
}

int main(){
    int num,i,j,cnt=0;
    scanf("%d",&num);
    for (i=1;i<=num;i++){
        for(j=1;j<=num;j++){
            cnt += count_3(i*j);
        }
    }
    printf("%d",cnt);
    return 0;
}
