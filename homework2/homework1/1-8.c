#include <stdio.h>

int main(){
    int i,n,in,num=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&in);
        num = num ^ in;
    }
    printf("%d",num);
    return 0;
}