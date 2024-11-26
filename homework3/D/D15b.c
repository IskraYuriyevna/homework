#include<stdio.h>
#include<unistd.h>
#include<signal.h>

volatile int count = 0;
volatile sig_atomic_t flag = 0;
void SigHandler(int s){
    signal(SIGINT,SigHandler);//for System V
    if(count<5){
        count++;
        flag = 1;
    }
    else 
    {
        signal(SIGINT,SIG_DFL);
        kill(getpid(),SIGINT);
    }
}


int main(){
    signal(SIGINT,SigHandler);
    while(1){
        if(flag){
            flag = 0;
            printf("I've received SIGINT %d times\n",count);
        }
        printf("Hello world\n");
        sleep(1);
    }
    return 0;
}