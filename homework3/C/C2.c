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

    int *b = (int*)malloc(n*sizeof(int));
    int cnt = 0;
    if(b == NULL){
        printf("Error:can't allocate memort\n");
        return 1;
    }

    for(i=0;i<n;i++){
        if(zeroonten(a[i])==1){
            b[cnt]=a[i];
            cnt++;
        }
    }

    for(i=0;i<cnt;i++){
        printf("%d ",b[i]);
    }
    
    free(a);
    return 0;
}