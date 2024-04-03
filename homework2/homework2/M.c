#include<stdio.h>

int main() {
    int n;unsigned long long count=1;
    scanf("%d",&n);
    if(n < 2){count = 1;}
    else if(n == 2){count = 2;}
    else {
        for(int i=n-2;i<=n;i++){
            count *=i;
        }
    }
    printf("%llu",count);
    return 0;
}
