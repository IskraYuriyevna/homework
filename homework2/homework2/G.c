#include <stdio.h>

int main() {
    long i,j,k,l,m,n=0;
    scanf("%ld %ld",&m,&n);
    if (m>=0) {
        k = m/n;
        l = m%n;
        for(i=1;i<n;i++){printf("%ld ",k);}
        j = k+l;
        printf("%ld",j);
        }
    else {
        k = m/(n-1);
        l = m%(n-1);
        for(i=1;i<n;i++){printf("%ld ",k);}
        j = k-l;
        printf("%ld",j);
    }
} 