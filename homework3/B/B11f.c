#include<stdio.h>

void print_bin(short num){
    unsigned short mask = 1 << sizeof(short)*8-1;
    for ( ;mask; mask>>=1){
        if (mask&num)
            printf("1");
        else
            printf("0");
    }
}


int main(){
    short n;
    scanf("%hd",&n);
    print_bin(n);

    return 0;
}