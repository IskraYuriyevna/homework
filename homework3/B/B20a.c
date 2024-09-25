#include<stdio.h>

int Strlen(const char *str)
{
    int i;
    for(i=0;str[i];i++){}

    return i;
}

int my_strcmp(const char *str1,const char *str2){
    for (i=0;str1[i];i++){
        if(str1[i]>str2[i]){
            return 1;
        }else if(str[i]<str2[i]){
            return -1;
        }else{continue;}
    }
    for ()
    
    return cmp;
}

int main(){
    char str1[101];
    char str2[101];
    int cmpr;

    scanf("%100[^\n]\n%100[^\n]",str1,str2);
    cmpr = my_strcmp(str1,str2);
    if(cmpr>0){
        printf("First");
    }else if(cmpr<0){
        printf("Second");
    }else{
        printf("Equal");
    }
    
    return 0;
}