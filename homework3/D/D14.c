#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
volatile int flag=0;

void do_work(const char* str,int *cnt,int pid,int *fd){
    if (!flag) pause();
    flag = 0;
    read (fd[0],cnt,sizeof(int));
    printf("%s %d\n",str,*cnt);
    fflush(stdout);
    (*cnt)++;
    write(fd[1],cnt,sizeof(int));
    kill(pid,SIGUSR1);
}

void Sig_handler(int s){
    signal(SIGUSR1,Sig_handler);
    flag=1;
}

int main(){
    pid_t pid;
    int fd[2];
    int cnt=0,Cnt_Max;

    pipe(fd);

    signal(SIGUSR1,Sig_handler);

    scanf("%d",&Cnt_Max);

    pid=fork();
    if(pid<0){perror("fork");return 1;}
    if(pid>0){
        write(fd[1],&cnt,sizeof(int));
        kill(pid,SIGUSR1);
        while(cnt<Cnt_Max){
            do_work("father",&cnt,pid,fd);
        }
        close(fd[0]);
        close(fd[1]);
        wait(NULL);
    }
    else{
        pid_t pid_f=getppid();
        while (cnt<Cnt_Max){
            do_work("son",&cnt,pid_f,fd);
        }
        close(fd[0]);
        close(fd[1]);
    }

    return 0;
}