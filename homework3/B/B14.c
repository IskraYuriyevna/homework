#include <stdio.h>

int main(){
    int yy,mm,dd,data;unsigned short mask = 1<<15;
    scanf("%d %d %d",&yy,&mm,&dd);
    data = dd+(mm<<5)+(yy<<9);
    for (int i=0;i<=15;i++){
        if(data&mask){
            printf("1");
        }else{
            printf("0");
        }
        mask>>=1;
    }

    printf("\n%d",data);
}