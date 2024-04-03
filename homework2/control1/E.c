#include <stdio.h>

int main(){
    int i,j,l;
    scanf("%d",&l);
    for(i=1;i<=l;i++){
        for (j=0;j<i;j++){
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}