#include <stdio.h>

int main()
{
    int a, b, n;
    
    scanf("%d %d %d", &a, &b, &n);
    // if(n <= 0 || b <= a)
    // {
    //     return 1;
    // }

    for(int i=(a-1);i<b;i++){
        if (i==(a-1)){
            for(int j=(a-1);j<b;j++){
                if(j==(a-1)){
                    printf("%*s",n,"");
                }else{
                    printf(" %*d",n,j);
                }
            }
            printf("\n");
        }else{
            for(int j=(a-1);j<b;j++){
                if(j==(a-1)){
                    printf("%*d",n,i);
                }else{
                    printf(" %*lld",n,(long long)i*j);
                }
            }
            printf("\n");
        }
    }

    return 0;
}