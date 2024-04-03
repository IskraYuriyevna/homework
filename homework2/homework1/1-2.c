#include <stdio.h>

int main(){
    int num;char c;
    scanf("%d ",&num);
    while((c = getchar()) != '.'){
        num = num%26;

        if (c<91 && c>64){
            if(c+num>90){
                c = c+num-26;
            }else {
                c = c+num;
            }
        }
        else if(c<123 && c>96){
            if(c+num>122){
                c = c+num-26;
            }else{
                c = c+num;
            }
        }   
        printf("%c",c);
    }
    printf(".");
    
    return 0;
}