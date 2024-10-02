#include<stdio.h>
#include<stdlib.h>
void sort(int arr[], int len){
        int i,j,key;
        for (i=1;i<len;i++){
                key = arr[i];
                j=i-1;
                while((j>=0) && (arr[j]>key)) {
                        arr[j+1] = arr[j];
                        j--;
                }
                arr[j+1] = key;
        }
}

int main(){
    int *arr = NULL;
    int *out = NULL;
    int size = 10;
    int count = 0;
    int number = 0;

    arr = (int*)malloc(size*sizeof(int));
    out = (int*)malloc(size*sizeof(int));
    if(arr == NULL){
        printf("Can't allocate memory\n");
        return 0;
    }

    while(scanf("%d",arr+count)==1){
        count++;
        if(count == size){
            int *buf = NULL;
            int *buf2 = NULL;
            size *= 2;
            buf = (int*)realloc(arr,size*sizeof(int));
            buf2 = (int*)realloc(arr,size*sizeof(int));
            if(buf == NULL){
                size /= 2;
                printf("Can't realloc memory\n");
                break;
            }else{
                arr = buf;
                out = buf2;
            }
        }
    }

    for(int i = 0;i<count;i++){
        if((arr[i]>='0')&(arr[i]<='9')){
            out[number] = arr[i];
            number++;
        }
    }
    sort(out,number);
    for(int i=0;i<number;i++){
        printf("%d ",out[i]);
    }
    printf("\n");

    free(arr);
    free(out);
    arr = NULL;
    out = NULL;
    return 0;
}