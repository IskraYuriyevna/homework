#include <stdio.h>

int main(){
    char a;int flag=0;
    while((a=getchar())!='.'){
        if ((a>47)&&(a<58)){
            flag+=1;
        }else{
            continue;
        }
    }
    printf("%d",flag);

    return 0;
}