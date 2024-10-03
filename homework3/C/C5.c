#include <stdio.h>
#include <stdlib.h>

//  void convert_string(char str[],int len) {
//     for (int i = 0; i < len; i++) {
//         if (str[i] >= 'a' && str[i] <= 'z') {
//             continue;
//         } else if (str[i] >= 'A' && str[i] <= 'Z') {
//             char temp = str[i];
//             for (int j = i; j <len; j++) {
//                 if (str[j] >= 'a' && str[j] <= 'z'){
//                     str[i] = str[j];
//                     str[j] = temp;
//                     break;
//                 }
//             }
//         }
//     }
// }


char *strcat(char *dest, const char *src) {
    char *ptr = dest; 

    while (*ptr != '\0') {
        ptr++;
    }

    while (*src != '\0') {
        *ptr = *src;
        ptr++;
        src++;
    }
    *ptr = '\0';

    return dest;
}

void convert_string(char str[],int len) {
    char low[len],upr[len];
    int leb_l=0,leb_u=0;
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            low[leb_l]=str[i];
            leb_l++;
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            upr[leb_u]=str[i];
            leb_u++;
        }
    }
    low[leb_l] = '\0';
    upr[leb_u] = '\0';
    strcat(low,upr);
    for (int i=0;i<len;i++){
        str[i] = low[i];
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