#include <stdio.h>

int main(){
    int ch;long long sum=0;
    while((ch = getchar())!=EOF){
        if ((ch>='0')&&(ch<='9')){
            ch = ch-'0';
        }else if(((ch>='a')&&(ch<='f'))||((ch>='A')&&(ch<='F'))){
            switch(ch){
                case('a'):ch = 10;break;
                case('b'):ch = 11;break;
                case('c'):ch = 12;break;
                case('d'):ch = 13;break;
                case('e'):ch = 14;break;
                case('f'):ch = 15;break;
                case('A'):ch = 10;break;
                case('B'):ch = 11;break;
                case('C'):ch = 12;break;
                case('D'):ch = 13;break;
                case('E'):ch = 14;break;
                case('F'):ch = 15;break;
            }
        }else{
            continue;
        }
        sum = sum+ch;
        //printf("sum = %lld\n",sum);
    }
    printf("%lld\n",sum);

    return 0;
}