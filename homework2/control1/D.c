#include <stdio.h>

int main(){
    int line[1000],no=0,i,j,cnt=0,max=0;;char c,cur;
    while((c = getchar()) != '.'){
        line[no] = c;
        no+=1;
    }

    for(i=0;i<=no;i++){
        //printf("line=%c ",line[i]);
        for(j=0;j<=i;j++){
            if (line[j]==line[i]){
                cnt+=1;
            }
        }
        if(cnt > max){
            cur = line[i];
            max = cnt;
        }
        cnt = 0;
    }
    printf("%c %d",cur,max);
    return 0;
}