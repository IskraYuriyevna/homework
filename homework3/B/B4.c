#include <stdio.h>

int main(){
    int a,b,c,n;float m;
    n = scanf("%d %d %d",&a,&b,&c);
    switch (n){
        case (EOF):
            printf("empty input");
            break;

        case (0):
            printf("3 errors");
            break;

        case (1):
            printf("2 errors");
            break;

        case (2):
            printf("1 error");
            break;

        case (3):
            if (c==0) {
                printf("divided by 0");
            } else {
                m = ((float)a+(float)b)/c;
                printf("%.2f",m);
            }
            break;
    }

    return 0;
}