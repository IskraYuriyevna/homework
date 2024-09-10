#include <stdio.h>

int main(){
    int num=0,count = 0,s,sum,n;char c;
    
    while(1){
        c = getchar();
        if (c==EOF){
            break;
        }else if (c-'0'){
            
        }else if (){

        }

        if(num>=0){
            sum = 0;
            while(num>0){
                n = num%10;
                num=num/10;
                if (n==5){continue;}
                else{sum = sum + n;}
            }
            printf("%d ",sum);
        }else{
            if (count==0){
                count=-1;
                break;
            } else {
                break;
            }
            break;
        }
        count++;
    }

    if (count==-1){
        printf("%d",0);
    }else if((count==0)&&(c)){
        printf("%d",0);
    }else if(c==EOF){
        printf("%d",-1);
    }

    return 0;
}