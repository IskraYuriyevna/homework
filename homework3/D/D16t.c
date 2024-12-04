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

char* itoa(int num,char* buf){
    char* str=buf;

    if(num == 0){
        *str++ = '0';
        *str = '\0';
        return buf;
    }else{
        while(num > 0){
            *str++ = (num%10)+'0';
            num/=10;
        }
        *str = '\0';
    }

    char* l = buf;
    char* r = str-1;
    while(l<r){
        char temp = *l;
        *l++ = *r;
        *r-- = temp;
    }

    return buf;
}

void IntHandler(int s){
    signal(SIGINT,IntHandler);//for System V

    if(cnti<5){
        cnti++;
        flag = 1;
        //printf("SIGINT %d SIGQUIT %d\n",cnti,cntq);
        write(stdout,"SIGINT ",sizeof("SIGINT "));
        write(stdout,,sizeof());
        write(stdout,"SIGQUIT ",sizeof("SIGQUIT "));
        write(stdout,,sizeof());fflush(stdout);
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
            flag=0; 
            //printf("SIGINT %d SIGQUIT %d\n",cnti,cntq);fflush(stdout);
            //cntq=0;
        }
    }

    return 0;
}