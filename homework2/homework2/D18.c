#include<stdio.h>

void moveHanoi(int n, int x, int y){
    if (n == 1){
        printf("%d %d %d\n",1,x,y);
        return;
    }else{
        moveHanoi(n-1,x,6-x-y);
        printf("%d %d %d\n",n,x,y);
        moveHanoi(n-1,6-x-y,y);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    moveHanoi(n,1,3);

    return 0;
}