#include <stdio.h>

int main(){
    int i,j,k,l,m=0,n;
    if(scanf("%d%d",&i,&j)==2){
        k=i/j;
        l=k+1;
        while(m*k+(j-m)*l != i){m++;}
        for(n=0;n<m;n++){
            printf("%d ",k);
        }
        for(n=m;n<j;n++){
            printf("%d ",l);
        }
    }

    return 0;
}