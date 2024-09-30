#include<stdio.h>
#include<math.h>

void rwxnum(short num,char* arr){
    unsigned short mask = 1;
    for (int i=8;i>=0;i--){
        if (num&mask){;}
        else{arr[i]='-';}
        mask<<=1;
    }
}

int main(){
    short n,i;
    char rwx[10]="rwxrwxrwx";
    scanf("%ho",&n);
    rwxnum(n,rwx);
    for (i=0;i<=8;i++){
        printf("%c",rwx[i]);
    }
    

    return 0;
}