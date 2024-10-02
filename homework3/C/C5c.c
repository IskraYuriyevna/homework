#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>

int main(){ 
    char *low = NULL;
    int *cap = NULL;
    int size = 10;
    int count = 0;
    int c;

    
    low = (char*)malloc(size*sizeof(char));
    if(low == NULL){
        printf("Can't allocate memory\n");
        return 0;
    }

    while((c=getchar())!=EOF&&c!='\n'){
        low[count]= c;
        count++;
        //printf("hr0\n");
        if(count == size){
            char *buf = NULL;
            size *= 2;
            buf = (char*)realloc(low,size*sizeof(char));
            //printf("hr1");
            if(buf == NULL){
                size /= 2;
                printf("Can't realloc memory\n");
                break;
            }else{
                //printf("hr2");
                low = buf;
            }
        }
    }
    
    int len = count;
    size = 10;
    count = 0;
    cap = (char*)malloc(size*sizeof(char));
    if(cap == NULL){
        printf("Can't allocate memory\n");
        return 0;
    }

    for (int i = 0; low[i] != '\0'; i++) {
        if (islower(low[i])) {
            continue;
        } else if (isupper(low[i])) {
            cap[count++] = low[i];
        }
    }

    for (int i = 0; i<len; i++) {
        //printf("hr3\n");
        if () {
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

    free(arr);
    free(out);
    arr = NULL;
    out = NULL;
    return 0;
}