#include<stdio.h>
#include<stdlib.h>

int belto(int i,int* a,int n){
    int j,b = 0;
    for(j=0;j<n;j++){
        if(a[j]==i){b=1;break;}
    }
    return b;
}

int main(){
    int n,i,max,min;
    int* a = (int*)malloc(n*sizeof(int));
    if (a == NULL){
        printf("Error:can't allocate memory\n");

        return 1;
    }
    
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    max = a[0];min = a[0];
    for(i=0;i<n;i++){
        if (a[i]>max){
            max = a[i];
        }else if(a[i]<min){
            min = a[i];
        }
    }
    for(i=min;i<max;i++){
        if (belto(i,a,n) == 0){
            printf("%d",i);
        }
    }

    free(a);
    return 0;
}