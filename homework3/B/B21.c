#include<stdio.h>

int my_strcmp(const char *str1,const char *str2){
    int i = 0;
    for(i=0;str1[i];i++){
        if(str1[i] == str2[i]){
            continue;
        }else{
            break;
        }
    }
    int cmpstr = str1[i] - str2[i];
    return cmpstr;
}

int main(){
    char str1[101];
    char str2[101];
    int cmpstr;

    scanf("%100[^\n]",str1);
    getchar();
    scanf("%100[^\n]",str2);

    cmpstr = my_strcmp(str1,str2);
    if(cmpstr>0){
        printf("First");
    }else if(cmpstr<0){
        printf("Second");
    }else{
        printf("Equal");
    }
    
    return 0;
}