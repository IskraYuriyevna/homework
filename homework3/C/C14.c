#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv){
    int num,flag=0;
    long long x;
    int* arr = NULL;

    if(argc < 3){
        printf("0 0");
        return 1;
    }
    if(sscanf(argv[1],"%lld",&x)!=1){
        printf("0 0");
        return 1;
    }
    if(sscanf(argv[2],"%d",&num)!=1){
        printf("0 0");
        return 1;
    }
    if(num < 2){
        printf("0 0");
        return 1;
    }

    arr = (int*)malloc(num*sizeof(int));
    if(arr == NULL){
        printf("0 0");
        return 1;
    }

    for(int i=0;i<num;i++){
        if(scanf("%d",arr+i)!=1){
            printf("0 0");
            free(arr);
            return 1;
        }
    }

    for(int i = 0;i<(num-1);i++){
        if((long long)*(arr+i)+(long long)*(arr+i+1)==x){
            printf("%d %d ",arr[i],arr[i+1]);
            flag++;
            break;
        }else{
            continue;
        }
    }
    if(flag==0){
        printf("0 0");
    }

    free(arr);
    arr = NULL;
    return 0;
}