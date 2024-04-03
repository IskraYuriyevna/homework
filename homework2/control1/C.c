#include <stdio.h>

int main(){
    unsigned int n,s1,s2,s3;
    scanf("%u %d %d %d",&n,&s1,&s2,&s3);
    if (s1>0){
    s1 = 1<<(s1-1);    
    n = n | s1;
    }
    if (s2>0){
    s2 = 1<<(s2-1);    
    n = n | s2;
    }
    if (s3>0){
    s3 = 1<<(s3-1);    
    n = n | s3;
    }
    printf("%u",n);

    return 0;
}