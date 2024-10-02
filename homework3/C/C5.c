#include <stdio.h>
#include <stdlib.h>
#include <String.h>

void convert_string(char str[],int len) {;

    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            continue;
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            char temp = str[i];
            for (int j = i; j <len; j++) {
                if (str[j] >= 'a' && str[j] <= 'z'){
                    str[i] = str[j];
                    str[j] = temp;
                    break;
                }
            }
        }
    }
}

int main(){
    char *arr = NULL;
    int size = 10;
    int count = 0;

    arr = (char*)malloc(size*sizeof(char));
    if(arr == NULL){
        printf("Can't allocate memory\n");
        return 0;
    }

    int c;
    while ((c = getchar()) != EOF && c != '\n') {
        arr[count] = c;
        count++;
        if(count == size){
            char *buf = NULL;
            size *= 2;
            buf = (char*)realloc(arr,size*sizeof(char));
            if(buf == NULL){
                size /= 2;
                printf("Can't realloc memory\n");
                break;
            }else{
                arr = buf;
            }
        }
    }

    convert_string(arr,count);
    
    for(int i=0;i<count;i++){
        printf("%c",arr[i]);
    }
    printf("\n");

    free(arr);
    arr = NULL;
    return 0;
}