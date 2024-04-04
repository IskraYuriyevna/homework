#include <stdio.h>

int main(){
    unsigned int n,k,i,cnt0,bi,cur,cnt=0;

    scanf("%u %u",&n,&k);
    for(i=1;i<=n;i++){
        bi = i;
        cnt0 = 0;
        while(bi!=0){
            cur = bi%2;
            if(cur==0){
                cnt0++;
                bi >>= 1;
            }else{
                bi >>= 1;
            }
        }
        if (cnt0==k){
            cnt += 1;
        }else{
            continue;
        }
    }
    printf("%u",cnt);

    return 0;
}