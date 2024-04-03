#include <stdio.h>

int main(){
    unsigned int a,b,c,d;
    scanf("%u %u",&a,&b);
    c = a>>b;
    d = (a-(c<<b))<<(32-b);
    c = c+d;
    printf("%u",c);

    return 0;
}