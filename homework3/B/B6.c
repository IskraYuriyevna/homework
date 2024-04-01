#include <stdio.h>

int main(){
    float m,n,o,p;int i,j;
    scanf("%f %f",&m,&n);

    for(j=n-1;j>=0;j--){
        for (i=0;i<m;i++){
            o=i/(m-1);
            p=j/(n-1);
            printf("(%-4.3f, ",o);
            printf("%-4.3f) ",p);
        }
        printf("\n");
    }

    return 0;
}