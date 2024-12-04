#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void test_signal(pid_t pid)
{
        usleep(10);
        kill(pid, SIGQUIT);
        usleep(10);
        kill(pid, SIGINT);
        usleep(10);
        kill(pid, SIGQUIT);
        usleep(10);
        kill(pid, SIGQUIT);
        usleep(10);
        kill(pid, SIGINT);
        usleep(10);
        kill(pid, SIGQUIT);
        usleep(10);
        kill(pid, SIGQUIT);
        usleep(10);
        kill(pid, SIGQUIT);
        usleep(10);
        kill(pid, SIGINT);
        usleep(10);
        kill(pid, SIGINT);
        usleep(10);
        kill(pid, SIGQUIT);
        usleep(10);
        kill(pid, SIGINT);
}

volatile int cnti = 0;//count of SIGINT
volatile int cntq = 0;//count of SIGQUIT
volatile sig_atomic_t flag = 0;
int t1;

void IntHandler(int s){
    signal(SIGINT,IntHandler);//for System V
    cnti++;
    flag=1;
    t1=cntq;
    cntq=0;
}

void QuitHandler(int s){
    signal(SIGQUIT,QuitHandler);//for System V                
    cntq++;
}

int main()
{
    // установка сигналов    
    signal(SIGQUIT,QuitHandler);
    signal(SIGINT,IntHandler);

    pid_t pid = fork();
    if (pid > 0)
    {
        test_signal(pid);
        wait(NULL);
        return 0;
    }
    // код процесса-сына

    while(1){
        if(flag==1){
            flag=0;
            printf("SIGINT %d SIGQUIT %d\n",cnti,t1);fflush(stdout);
            if(cnti==5){
                signal(SIGINT,SIG_DFL);
                kill(getpid(),SIGINT);
            }
        }
    }

    return 0;
}