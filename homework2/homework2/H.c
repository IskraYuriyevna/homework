#include <stdio.h>

int main(){
    char str[2];int i,j=0;
    scanf("%s",str);
    j = str[0]-65;
    i = str[1]-1;
    if ((i+j)%2==0) printf("BLACK");
    else printf("WHITE");
    return 0;
}