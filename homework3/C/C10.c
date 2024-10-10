#include <stdio.h>
#include <string.h>

int is_palindrom(char *Str){
    int len = strlen(Str),flag= 1;
    for(int i=0;i<=(len/2);i++){
        if(Str[i]==Str[len-1-i]){
            continue;
        }else{
            flag = 0;
            break;
        }
    }
    return flag;
}

int main(int argc,char**argv){
    if (argc < 2){
        return -1;
    }
    
    if (is_palindrom(argv[1])){
        printf("YES");
    }else{
        printf("NO");
    }
    

    return 0;
}