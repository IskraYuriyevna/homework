#include<stdio.h>

int main(){
    char str[1001]={0},out[1001]={0},ctrl[128]={0};
    int i= 0,j=0;

    scanf("%1000[^\n]",str);

    for(i=0;str[i];i++){
        if((str[i]==' ')||(ctrl[(unsigned int)str[i]]!=0)){
            continue;
        }else{
            ctrl[(unsigned int)str[i]] = 1;
            out[j]=str[i];
            j++;
        }
    }
    out[j] = 0;

    printf("%s",out);
    return 0;
}