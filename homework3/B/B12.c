#include<stdio.h>

void rwxnum(short num,char* arr){
    unsigned short mask = 1<<8*(sizeof(short))-1;
    for (int i=0;i<=16;i++){
        if (num&mask){;}
        else{arr[i]='-';}
        mask>>=1;
    }
}

int main(){
    short n,i;
    char rwx[16]="rwxrwxrwxrwxrwxr";
    scanf("%ho",&n);
    rwxnum(n,rwx);
    for (i=0;i<=15;i++){
        printf("%c",rwx[i]);
    }
    

    return 0;
}