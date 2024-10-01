#include <stdio.h>
#include <stdlib.h>

int main(){
    int *arr = NULL;
    int N;

    if(scanf("%d",&N) != 1){
        return 1;
    }

    arr = (int*)malloc(N*sizeof(int));
    if(arr == NULL){
        printf("Can't allocate memory\n");
        return 1;
    }
    for(int i=0;i<N;i++){
        if(scanf("%d",arr+i)!=1){
            return 1;
        }
    }

    int imax = 0,imin = 0;
    for(int i = 1;i<N;i++){
        if(arr[i]>arr[imax]){
            imax = i;
        }
        if(arr[i]<arr[imin]){
            imin = i;
        }
    }
    int tmp = arr[imax];
    arr[imax] = arr[imin];
    arr[imin] = tmp;

    for(int i=0;i<N;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    free(arr);
    arr = NULL;
    return 0;
}