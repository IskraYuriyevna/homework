#include <stdio.h>

int main(){
    long long flow,sum=0;
    while(scanf("%lld ",&flow) != EOF){
        sum = sum+flow;
    }
    printf("%lld",sum);

    return 0;
}