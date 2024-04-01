#include<stdio.h>
#include<stdlib.h>

int* maxminswap(int* mec,int n){
    int i,max=0,min=0;
    for (i=0;i<n;i++){
        if(mec[i]>mec[max]){
            max = i;
        }else if(mec[i]<mec[min]){
            min = i;
        }
    }
    i = mec[min];
    mec[min] = mec[max];
    mec[max] = i;
    return mec;
}

int main(){
    int n,i;
    int* a = (int*)malloc(n*sizeof(int));
    if (a == NULL){
        printf("Error:can't allocate memory\n");

        return 1;
    }
    
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf("%d",&a[i]);    
    }
    a = maxminswap(a,n);
    for (i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    free(a);
    
    return 0;
}