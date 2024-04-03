#include<stdio.h>

int main(){
    int i, k;unsigned int x, n, max = 0;
    scanf("%d %d",&n,&k);
    unsigned int mask = (1 << k) - 1;

    for (i = 0; i < 33 - k; i++)
    {
        x = (n >> i) & mask;
        if (x > max)
            max = x;
    }
    printf("%d",max);
    
    return 0;
}
