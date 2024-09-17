#include<stdio.h>
void print_bit(short sh)
{
    unsigned short mask= 1<<15;
    for(; mask !=0;mask = mask>>1)
    {
        if((mask & sh) > 0) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
}
int main(){
    short sh;
    if(scanf("%hd",&sh) == 1){
        print_bit(sh);
    }
    return 0;
}