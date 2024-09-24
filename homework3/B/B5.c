#include <stdio.h>

int main(){
    int count=0,sum=0,c;
    while(1){
        c=getchar();
        if (((c=='\n')||(c==EOF))&&(count==0)){
            // 如果检测到
            printf("%d",-1);
            //printf("HR1 ");
            break;

        }else if(((c<'0')||(c>'9'))&&(count==0)){
            printf("%d",0);
            //printf("HR2 ");
            break;

        }else if ((c>='0')&&(c<='9')){
            if(c=='5'){
                count++;
                continue;
            }else{
                sum = sum+(c-'0');
                count++;
            }
            //printf("HR3 ");

        }else if (c==' '){
            printf("%d ",sum);
            sum = 0;
            //printf("HR4 ");

        }else if((c=='\n')||(c==EOF)){
            printf("%d ",sum);
            //printf("HR5 ");
            break;

        }else{
            //printf("HR6 ");
            break;
        }

    }


    return 0;
}