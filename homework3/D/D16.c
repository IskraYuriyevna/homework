#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

//I don't know why this works, it seems to work, but it still occasionally fails

volatile int cnti = 0;//count of SIGINT
volatile int cntq = 0;//count of SIGQUIT
volatile sig_atomic_t flag = 0,flag2 = 0;

void IntHandler(int s){
    signal(SIGINT,IntHandler);//for System V

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
        if(flag){
            int t1=cnti;int t2=cntq;
            // Save these two variables to prevent them from being preempted by signals before they are cleared
            // In other words, we use an atomic operation to replace complex operations such as printf,
            // reducing the probability of signal preemption after printing and before clearing, but it still cannot eliminate
            flag=0;cntq=0;
            printf("SIGINT %d SIGQUIT %d\n",t1,t2);fflush(stdout);
            //printf("SIGINT %d SIGQUIT %d\n",cnti,cntq);fflush(stdout);
            //cntq=0;
            if(cnti==5){
                signal(SIGINT,SIG_DFL);
                kill(getpid(),SIGINT);
            }
        }
    }

    return 0;
}