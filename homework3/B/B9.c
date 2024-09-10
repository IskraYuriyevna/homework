# include <stdio.h>

int main(){
    int cnt1=0,cnt2=0,bf=0;char c;

    while((c=getchar())!='\n'){
        if(c=='='){
            cnt1++;
            continue;
        }else{
            bf = 1;
            break;
        }
    }

    while((c=getchar())!='\n'){
        if(c=='='){
            cnt2++;
            continue;
        }else{
            bf = 1;
            break;
        }
    }


    if (bf == 1){
        printf("Incorrect");
    }else if(cnt1>cnt2){
        printf("First");
    }else if(cnt2>cnt1){
        printf("Second");
    }else{
        printf("Equal");
    }

    return 0;
}