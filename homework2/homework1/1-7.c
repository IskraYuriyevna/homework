#include <stdio.h>

int main(){
    unsigned int i,mask = 4278190080;
    scanf("%u",&i);
    i = i ^ mask;
    printf("%u",i);
    
    return 0;
}