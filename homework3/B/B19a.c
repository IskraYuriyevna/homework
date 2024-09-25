#include<stdio.h>

void Strcpy(char *dest,const char *src){
    int i;
    for(i=0;src[i];i++)
        dest[i] = src[i];
    dest[i]=0;
}

int main(){
    char str1[101];
    char str2[101];

    scanf("%100[^\n]",str1);
    Strcpy(str2,str1);
    printf("%s\n",str2);

    return 0;
}