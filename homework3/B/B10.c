#include<stdio.h>
#include<stdlib.h>

int main(){
    long i=0,sum,an;
    while((an=getchar())!='\n'){
        if (an!=' '){
            if (i==0){sum=an-'0';i++;}
            else if(((i%2)==0)){sum=sum-(an-'0');i++;}
            else if(((i%2)==1)){sum=sum+(an-'0');i++;}
        }
    }
    printf("%d",sum);

    return 0;
}
