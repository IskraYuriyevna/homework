#include<stdio.h>
#include<stdlib.h>

int zeroonten(int num){
    int m=0;
    if((num/10)%10==0){m=1;}

    return m;
}

int main(){
    int i,n;
    if(scanf("%d",&n) != 1){
        return 1;
    }
    int* a = (int*)malloc(n*sizeof(int));

    if (a == NULL){
        printf("Error:can't allocate memory\n");
        return 1;
    }
    
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        if(zeroonten(a[i])==1){
            printf("%d ",a[i]);
        }
    }
    
    free(a);
    return 0;
}