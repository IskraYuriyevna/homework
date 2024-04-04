#include <stdio.h>

int main(){
    int ipt[101]={0},a[101]={0},b[101]={0};int i,j=0,k=0;char c;
    
    while((c=getchar())!='\n'){
        ipt[j] = c-'0';
        j++;
    }
    j-=1;
    while(j>=0){
        a[k] = ipt[j];
        j--;
        k++;
    }
    j=0;k=0;
    while((c=getchar())!='\n'){
        ipt[j] = c-'0';
        j++;
    }
    j-=1;
    while(j>=0){
        b[k] = ipt[j];
        j--;
        k++;
    }
    
    //for (i=0;i<101;i++){
        //a[i] = a[i]+b[i];
        //if(a[i]>=10){
        //    a[i] = a[i]-10;
        //    a[i+1]++;
        //}
        //printf("%d",a[i]);
    //}
    //printf("\n");
    for (i=0;i<101;i++){
        a[i] = a[i]+b[i];
        if(a[i]>=10){
            a[i] = a[i]-10;
            a[i+1]++;
        }
        //printf("%d",b[i]);
    }
    j=0;
    for(i=100;i>=0;i--){
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