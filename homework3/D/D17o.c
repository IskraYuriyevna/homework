#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

volatile sig_atomic_t flag = 0;

// Trying to change global variables within a process does not work, 
// each process will have its own space and will only change its own variables. 
// Pipes must be used to communicate between processes.

typedef struct {
    // In order to pass these two numbers through a pipe at the same time, a structure is needed
    int Dec;
    int Inc;
}cnt;

void SigHandler(int s){
    signal(SIGUSR1,SigHandler);
    //printf("SigHandler is called\n");
    flag = 1;
}

int main(){
    pid_t pid;
    pid_t pid2;
    cnt Cnt;
    int fd[2];
    // No matter what type of data is transmitted, pipe is of type int
    signal(SIGUSR1,SigHandler);
    
    if(pipe(fd)<0){perror("pipe");return 1;}
    
    scanf("%d %d",&Cnt.Dec,&Cnt.Inc);

    pid = fork();
    if(pid<0){perror("fork");return 2;}    
    pid2 = fork();
    if(pid2<0){perror("fork");return 2;}
    if(pid>0&&pid2>0){
        // run the parent process first, then let son2 complete the first increment
        // Note that you need to read cnt instead of int here, otherwise only the first value of the structure will be read
        write(fd[1],&Cnt,sizeof(cnt));
        kill(pid2,SIGUSR1);// Send signal SIGUSR1 to son2
    }

    if(pid==0){//son1
        pid_t pid_father = getppid();
        while(Cnt.Inc<Cnt.Dec)
        {
            if(!flag){
                pause();
            }
            flag = 0;
            // printf("Son1 working\n");
            read(fd[0],&Cnt,sizeof(cnt));
            if(Cnt.Inc<=Cnt.Dec){
                // Since this process knows the current status of the two values ​​only after obtaining the structure Cnt from the pipeline, 
                // if no judgment is made here, when Inc of other processes is already greater than Dec, 
                // the output here will continue until the next loop judgment.
                // There's probably a cleaner way, but I'm lazy and here's what worked.
                printf("son1 %d %d\n",Cnt.Dec,Cnt.Inc);fflush(stdout);
                Cnt.Dec--;Cnt.Inc++;
            }
            write(fd[1],&Cnt, sizeof(cnt));
            kill(pid_father,SIGUSR1);// Send signal SIGUSR1 to father
        }
        close(fd[0]);close(fd[1]);
    }

    if(pid2==0){//son2
        while(Cnt.Inc<Cnt.Dec)
        {
            if(!flag){
                pause();
            }
            flag = 0;
            // printf("Son2 working\n");
            read(fd[0],&Cnt,sizeof(cnt));
            if(Cnt.Inc<=Cnt.Dec){
                printf("son2 %d %d\n",Cnt.Dec,Cnt.Inc);fflush(stdout);
                Cnt.Dec--;Cnt.Inc++;
            }
            write(fd[1],&Cnt, sizeof(cnt));
            kill(pid,SIGUSR1);// Send signal SIGUSR1 to son1
        }
        close(fd[1]);close(fd[0]);
    }

    //father
    while(Cnt.Inc<Cnt.Dec){
        if(!flag)
            pause();
        flag = 0;
        // printf("Father working\n");
        read(fd[0],&Cnt,sizeof(cnt));        
        if(Cnt.Inc<=Cnt.Dec){
            printf("father %d %d\n",Cnt.Dec,Cnt.Inc);fflush(stdout);
            Cnt.Dec--;Cnt.Inc++;
        }
        write(fd[1],&Cnt,sizeof(cnt));
        kill(pid2,SIGUSR1);// Send signal SIGUSR1 to son2
    }
    close(fd[0]);close(fd[1]);
    wait(NULL);wait(NULL);
    
    return 0;
}   