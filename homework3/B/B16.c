#include<stdio.h>

int Strlen(const char *str)
{
    int i;
    for(i=0;str[i];i++){}

    return i;
}

int main(){
    char str[101];
    int len;
    scanf("%100[^\n]s",str);
    len = Strlen(str);
    printf("%d",len);
    return 0;
}