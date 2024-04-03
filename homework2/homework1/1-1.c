#include <stdio.h>

int main(){
    int c,l,p,i,cnt=1;
    scanf("%d",&l);
    for (i=0;i<l;i++){
        scanf("%d",&c);
        if (i==0){
            p = c;
            cnt=1;
        }else{
            if (c>p) {
                p=c;
                cnt=1;
            }else if (c<p){
                continue;
            }else{
                cnt+=1;
            }
        }
    }

    printf("%d",cnt);
    
    return 0;
}