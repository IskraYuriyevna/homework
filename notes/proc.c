#include<stdio.h>
#include<unistd.h>

int main(){
    if(fork()==0){
        printf("I'm son,my PID = %d,my father's PID = %d\n",getpid(),getppid());
    }else{
        pid_t pid = getpid();
        printf("Hello world I'm %d\n",pid);
    }
    return 0;
}