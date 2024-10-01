#include<stdio.h>
#include<stdlib.h>

int main(){
    int *arr;
    int num=8,i=0,j;

    arr = (int*)malloc(num*sizeof(int));//开数组，先开一个int

    if (arr == NULL)
    {
        printf("Error:can't allocate memory\n");
        return 1;
    }

    while(scanf("%d",arr+i) == 1)
    {
        i++;
        if (i == num)
        {
            int *buf;
            num *= 2;
            buf = (int*)realloc(arr,num*sizeof(int));//开新的内存
            if (buf == NULL)
            {
                printf("Error:Can't allocate memory\n");
                return 1;
            }
            else
                arr = buf;
        }
    }
    for(j = i-1;j >=0;j--)
        printf("%d ",arr[j]);
    printf("\n");
    free(arr);
    return 0;
}