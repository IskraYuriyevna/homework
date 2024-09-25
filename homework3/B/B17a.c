#include <stdio.h>
int Str_length(char * str){
    return 0;
}

int main(){
    char str[100];
    scanf("%99[^\n]",str);//Error
    //gets(str); 
    //fgets(str,SIZE,stdin);
    printf("%d\n",Str_length(str));
}