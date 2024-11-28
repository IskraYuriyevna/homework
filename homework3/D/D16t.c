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
volatile sig_atomic_t flag = 0,flag2 = 0;

void SigHandler(int s){
    signal(SIGINT,SigHandler);
    signal(SIGQUIT,SigHandler);//for System V
    switch(s){
        case SIGINT:    
            if(cnti<5){
                cnti++;
                flag = 1;
            }
            else 
            {
                signal(SIGQUIT,SIG_DFL);
                signal(SIGINT,SIG_DFL);
                kill(getpid(),SIGINT);
            }
            break;

        case SIGQUIT:
                cntq++;
                flag2 = 1;
            break;
    }
}

int main()
{
    // установка сигналов    
    signal(SIGQUIT,SigHandler);
    signal(SIGINT,SigHandler);

    pid_t pid = fork();
    if (pid > 0)
    {
        test_signal(pid);
        wait(NULL);
        return 0;
    }
    // код процесса-сына

    while(1){
        if(flag){
            flag=0;
            printf("SIGINT %d SIGQUIT %d\n",cnti,cntq);fflush(stdout);
            cntq=0;
            if(cnti==5){
                signal(SIGINT,SIG_DFL);
                kill(getpid(),SIGINT);
            }
        }
    }

    return 0;
}