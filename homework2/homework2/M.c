#include<stdio.h>

int main() {
    int n,count;
    scanf("%d",&n);
    if(n == 1){count = 1;}
    if(n == 2){count = 2;}
    else {count = n * (n - 1) * (n - 2);}
    printf("%d",count);
    return 0;
}