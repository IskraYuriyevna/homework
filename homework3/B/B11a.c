#include<stdio.h>

int main(){
    short i,j,k,flag;short a[16],b[16];
    
    scanf("%hu",&i);
    if (i>=0){
        for (j=0;j<16;j++){
            k=(i%2);
            i=(i/2);
            a[j] = k;
        }
        for (j=15;j>=0;j--){
            printf("%hu",a[j]);
        }
    }else{
        //printf("hr2\n");
        for (j=0;j<16;j++){
            i = -i;
            k=(i%2);
            i=(i/2);
            a[j] = k;
        }            
        if(a[0]==0){
            b[0]=0;flag=1;
            }else{
            b[0]=1;
        }
        for (j=1;j<16;j++){
            if (flag==1){
                if(a[j]==0){b[j]=0;}
                else{b[j]=1;flag=0;}
            }else{
                if(a[j]==0){b[j]=1;}
                else{b[j]=0;}
            }
        }
        for (j=15;j>=0;j--){
            printf("%hu",b[j]);
        }
    }
    return 0;
}