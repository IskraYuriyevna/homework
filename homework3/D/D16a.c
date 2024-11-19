#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<fcntl.h>

int main(){
    int fd[2],semid,cnt = 0;
    int Cnt_Max,ff;
    key_t key;
    pid_t pid;
    struct sembuf P1 = {0,-1,0},V1 = {0,1,0};
    struct sembuf P2 = {1,-1,0},V2 = {1,1,0};

    ff = creat("a.txt",0664);
    if(ff<0){perror("create");return 1;}
    key = ftok("a.txt",3);
    if(key<0){perror("key");return 2;}
    close(ff);

    semid = semget(key,2,IPC_CREAT | 0666);
    if(semid<0){perror("semget");return 3;}
    semctl(semid,0,SETVAL,0);
    semctl(semid,1,SETVAL,0);

    scanf("%d",&Cnt_Max);

    pipe(fd);

    pid = fork();
    if(pid<0){perror("fork");return 3;}
    if(pid>0){

        write(fd[1],&cnt,sizeof(int));
        semop(semid,&V1,1);
        while(cnt<Cnt_Max){
            semop(semid,&P2,1);
            read(fd[0],&cnt,sizeof(int));
            printf("father %d\n",cnt++);fflush(stdout);
            write(fd[1],&cnt,sizeof(int));
            semop(semid,&V1,1);
        }
        close(fd[0]);
        wait(NULL);
        semctl(semid,0,IPC_RMID,0);
    }else{
        while(cnt<Cnt_Max){
            semop(semid,&P1,1);
            read(fd[0],&cnt,sizeof(int));
            printf("son %d\n",cnt++);fflush(stdout);
            write(fd[1],&cnt,sizeof(int));
            semop(semid,&V2,1);
        }
        close(fd[0]);close(fd[1]);
    }
    return 0;
}