#include <stdio.h>

int main(){
    int a[102]={0},b[102]={0};int i,j=0,k=0,l=0;
    if(scanf("%d%d",&k,&l)==2){

    for (i=0;i<101;i++){
        a[i] = k%10;
        k=k/10;
        if(k<1)break;
    }

    for (i=0;i<101;i++){
        b[i] = l%10;
        l/=10;
        if(l<1)break;
    }

    for (i=0;i<101;i++){
        a[i] = a[i]+b[i];
        if(a[i]>=10){
            a[i] = a[i]-10;
            a[i+1]++;
        }
    }

    for(i=101;i>=0;i--){
        if (j==0){
            if(a[i]!=0){
                printf("%d",a[i]);
                j++;
            }else if(i==0&&j==0){
                printf("%d",a[i]);
            }
        }else{
            printf("%d",a[i]);
        }
        //printf("%d",a[i]);
    }

    return 0;

    }
    else
    {
        return -1;
    }
}