#include <stdio.h>

int main(){
    int a,b,c;
    scanf("%d %d",&a,&b);
    c = a>>b;
    a = a-(c<<b);

    printf("%d",a);

    return 0;
}