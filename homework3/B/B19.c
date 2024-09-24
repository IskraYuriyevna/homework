#include <stdio.h>


int main(){
    char str[100]={0};int cnt=0;
    fgets(str, sizeof(str), stdin);
    for(int i;i<100;i++){
        if(str[i] == '\0'){
            break;
        }else if(str[i] == '\n'){
            continue;
        }else{
            cnt++;
        }
    }

    printf("%d",cnt);

    return 0;
}