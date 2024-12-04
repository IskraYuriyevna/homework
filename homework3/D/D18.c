#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/wait.h>

int main(){
    int cnt = 0,Cnt_Max;
    int fd[2];
    struct sembuf P1={0,-1,0},V1={0,1,0};
    struct sembuf P2={1,-1,0},V2={1,1,0};
    key_t key = ftok("/bin/ls",8);
    if(key<0){perror("ftok");return 1;}

    int semid = semget(key,2,IPC_CREAT | 0666);
    //创建两个信号量
    if(semid < 0){perror("semget");return 1;}
    semctl(semid,0,SETVAL,0);// s1 = 0
    semctl(semid,1,SETVAL,0);// s2 = 0

    if(pipe(fd)<0){perror("pipe");return 1;}
    scanf("%d",&Cnt_Max);
    pid_t pid = fork();
    if(pid<0){perror("fork");return 1;}
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
        close(fd[0]);close(fd[1]);
        wait(NULL);
        semctl(semid,0,IPC_RMID,0);
    }else{
        while(cnt < Cnt_Max){
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
