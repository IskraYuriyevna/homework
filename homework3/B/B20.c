#include <stdio.h>

void string_copy(char *dest,const char *src){
    int i = 0; 
    for(i=0;src[i];i++){
        dest[i] = src[i];
    }
    dest[i] = 0;
}

void string_copy2(char *dest,const char *src){
    for(;*src;dest++,src++){
        *dest = *src;
    }
    *dest = 0;
}

int main(){
    char str1[101];
    char str2[101];
    scanf("%100[^\n]",str1);
    string_copy(str2,str1);
    printf("%s\n",str2);
    return 0;
}