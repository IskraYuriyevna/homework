#include <stdio.h>
int main(){
    unsigned long v;int a[5]={0},i,flag=0;
    scanf("%lu",&v);

    for(i=0;i<4;i++){
        a[i]=v%3;
        v=v/3;
    }

    for(i=0;i<4;i++){
        if (a[i]==2){
            a[i]=-1;
            a[i+1]+=1;
        }else if(a[i]==3){
            a[i]=0;
            a[i+1]+=1;
        }else{continue;}
    }

    if((v==0)&&(a[4]==0)){
        for(i=0;i<4;i++){
            if(a[i]!=0){
                flag++;
            }else{
                continue;
            }
        }
    }else if(v>40){
        flag=-1;
    }

    printf("%d",flag);
    
    
    return 0;
}