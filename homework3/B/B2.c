#include <stdio.h>

int main() {
    long fn0=0,fn1=1,fn2=0,sum=0;int n=0;
    scanf("%d",&n);
    sum = fn0 + fn1;
    for (int i=0;i<=n-3;i++){
        fn2 = fn0 + fn1;
        fn0 = fn1;
        fn1 = fn2;
        sum = sum + fn2;
    }
    printf("%ld",sum);

    return 0;
}