#include <stdio.h>

int main(){

    int flag = 0,m,ipt,n,sum;

    while (m = scanf("%d ",&ipt)){
        if (m == EOF){
            break;
        }else if (m == 0){
            flag = -2;
            break;
        }else if (m == 1){
            if (ipt<0){
                if (flag==0){
                    flag = -1;
                    break;
                }else{
                    break;
                }
            }else if(ipt>=0){
                sum = 0;
                while(ipt>0){
                    n = ipt%10;
                    ipt=ipt/10;
                    if (n==5){continue;}
                    else{sum = sum + n;}
                }
                printf("%d ",sum);
            }
        }
        flag++;
    }

    if (flag == 0){
        printf("-1");
    }else if (flag == -1){
        printf("0");
    }

    return 0;
}