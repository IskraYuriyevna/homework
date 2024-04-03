#include <stdio.h>

int main(){
    int a1,a2,n;long an;
    scanf("%d %d %d",&a1,&a2,&n);
    an = a2+(a2-a1)*(n-2);

    printf("%ld",an);

    return 0;
}