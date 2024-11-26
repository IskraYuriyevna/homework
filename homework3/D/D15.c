#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>


volatile sig_atomic_t flag = 0;
void SigHandler(int s){
    signal(SIGUSR1,SigHandler);
    flag = 1;
}

int main(){
    pid_t pid;
    int cnt = 0;
    int Cnt_Max,fd[2];
    signal(SIGUSR1,SigHandler);
    if (pipe(fd)<0){perror("pipe");return 1;}

    scanf("%d",&Cnt_Max);

    pid = fork();
    if(pid<0){perror("fork");return 1;}
    if(pid>0){//father pid = SON'sPID
        write(fd[1],&cnt,sizeof(int));
        kill(pid,SIGUSR1);

        while(cnt<Cnt_Max){
            if(!flag)
                pause();
            flag = 0;
            read(fd[0],&cnt,sizeof(int));
            printf("father %d\n",cnt++);
            fflush(stdout);
            write(fd[1],&cnt,sizeof(int));
            kill(pid,SIGUSR1);
        }
        close(fd[0]);close(fd[1]);
        wait(NULL);
    }
    else // SON
    {
        pid_t pid_father = getppid();
        while(cnt <Cnt_Max)
        {
            if(!flag){
                pause();
            }
            flag = 0;
            read(fd[0],&cnt,sizeof(int));
            printf("son %d\n",cnt++);fflush(stdout);
            write(fd[1],&cnt, sizeof(int));
            kill(pid_father,SIGUSR1);
        }
        close(fd[0]);close(fd[1]);
    }
    return 0;
}