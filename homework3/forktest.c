#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    pid_t pid0,pid1;

    pid0=fork();
    if(pid0<0){return 1;}
    if(pid0==0){
        printf("son1");
    }else{
        pid1 = fork();
        if(pid1<0){return 1;}
        if(pid1==0){
            printf("son2");
        }else{
            printf("father");
            wait(NULL);wait(NULL);
        }
        
    }
    wait(NULL);wait(NULL);
    return 0;
}