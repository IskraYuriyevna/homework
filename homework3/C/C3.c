#include <stdio.h>
#include <stdlib.h>

int main(){
    int *arr = NULL;
    int size = 10;
    int count = 0;

    arr = (int*)malloc(size*sizeof(int));
    if(arr == NULL){
        printf("Can't allocate memory\n");
        return 0;
    }

    while(scanf("%d",arr+count)==1){
        count++;
        if(count == size){
            int *buf = NULL;
            size *= 2;
            //printf("%d\n",size*sizeof(int));
            buf = (int*)realloc(arr,size*sizeof(int));
            if(buf == NULL){
                size /= 2;
                printf("Can't realloc memory\n");
                break;
            }else{
                arr = buf;
            }
        }
    }

    for(int i = count-1;i>=0;i--){
        printf("%d ",arr[i]);
    }
    printf("\n");

    free(arr);
    arr = NULL;
    return 0;
}