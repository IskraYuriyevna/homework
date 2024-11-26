#include<stdio.h>
#include<signal.h>
#include<unistd.h>

//void (*signal(int sig,void (*handler)(int))(int))
int count = 0;
void SigHandler(int s)
{
    if(count < 5){printf("I've received SIGINT %d times\n",++count);}
    else{
        signal(SIGINT,SIG_DFL);
        kill(getpid(),SIGINT);
    }
}

int main(){
    signal(SIGINT,SigHandler);//ignore
    while(1){
        printf("Hello world!\n");
        sleep(1);
    }
    return 0;
}