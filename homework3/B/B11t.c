#include <stdio.h>

int main(){
    long num,cnt=0,sum=0;

    while(scanf("%ld",&num)){
        if (cnt==0){
            sum = num;

        }else if(cnt%2==1){
            sum = sum + num;

        }else if(cnt%2==0){
            sum = sum - num;

        }
        cnt++;
        
        int c = getchar();
        if (c==' '){
            
        }else if ((c=='\n')||(c==EOF)){
            break;
        }else if (c!=' '){
            ungetc(c,stdin);
        }
        
    }

    printf("%ld",sum);

    return 0;
}