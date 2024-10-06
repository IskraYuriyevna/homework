#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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
    char *arr = NULL;
    int *out = NULL;
    int size = 10;
    int count = 0;
    int c;

    
    arr = (char*)malloc(size*sizeof(char));
    if(arr == NULL){
        printf("Can't allocate memory\n");
        return 0;
    }

    while((c=getchar())!=EOF&&c!='\n'){
        arr[count]= c;
        count++;
        //printf("hr0\n");
        if(count == size){
            char *buf = NULL;
            size *= 2;
            buf = (char*)realloc(arr,size*sizeof(char));
            //printf("hr1\n");
            if(buf == NULL){
                size /= 2;
                printf("Can't realloc memory\n");
                break;
            }else{
                //printf("hr2\n");
                arr = buf;
            }
        }
    }
    
    int len = count;
    size = 10;
    count = 0;
    out = (int*)malloc(size*sizeof(int));
    if(out == NULL){
        printf("Can't allocate memory\n");
        return 0;
    }

    for (int i = 0; i<len; i++) {
        //printf("hr3\n");
        if (isdigit(arr[i])) {
            int num = 0;
            while (isdigit(arr[i])) {
                //printf("hr4\n");
                num = num * 10 + (arr[i] - '0');
                i++;
                if (count == size) {
                    int *buf2 = NULL;
                    size *= 2;
                    buf2 = (int*)realloc(out, size * sizeof(int));
                    //printf("hr5\n");
                    if(buf2 == NULL){
                        size /= 2;
                        printf("Can't realloc memory\n");
                        break;
                    }else{
                        out = buf2;
                    }
                }
            }
            out[count] = num;
            count++;
            //printf("hr6\n");
            i--;
        }
    }

    sort(out, count);

    for(int i=0;i<count;i++){
        //printf("hr7\n");
        printf("%d ", out[i]);
    }
    printf("\n");

    free(arr);
    free(out);
    arr = NULL;
    out = NULL;
    return 0;
}