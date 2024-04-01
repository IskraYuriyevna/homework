#include <stdio.h>

int main() {
    long fn1=0,fn2=1,fn3=0,sum=0;int n=0;
    scanf("%d",&n);
    sum = fn1 + fn2;
    for (int i=0;i<=n-3;i++){
        fn3 = fn1 + fn2;
        fn1 = fn2;
        fn2 = fn3;
        sum = sum + fn3;
    }
    printf("%ld",sum);

    return 0;
}