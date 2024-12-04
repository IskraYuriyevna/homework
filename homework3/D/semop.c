#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<sys/sem.h>

int main(){
    pid_t pid;
    int fd[2];
    struct sembuf P = {0,1,0};
    struct sembuf V = {0,-1,0};

    key_t key = ftok("aa.txt",6);
    if(key<0){perror("ftok");return 1;}

    int semid = semget(key,1,IPC_CREAT | 0600);
    if(semid<0){perror("semget");return 1;}

    semctl(semid,0,SETVAL,0);

    if(pipe(fd)==-1){
        perror("pipe");
        return 1;
    }

    pid = fork();
    if(pid == -1){perror("fork");return 2;}
    else if(pid == 0)
    {
        int num1 = 3,num4;
        write(fd[1],&num1,sizeof(int));
        printf("Son num1 = %d\n",num1);
        semop(semid,&P,1);//s = s-1 = 1-1 = 0 lock
        read(fd[0],&num4,sizeof(int));
        printf("Son num4 = %d\n",num4);
        close(fd[0]);close(fd[1]);
    }else{
        int num2,num3 = 8;
        read(fd[0],&num2,sizeof(int));
        printf("Father num2 = %d\n",num2);
        write(fd[1],&num3,sizeof(int));
        printf("Father num3 = %d\n",num3);
        semop(semid,&V,1); // s = s+1 = 0+1 = 1
        wait(NULL);
        close(fd[0]);close(fd[1]);
    }
    return 0;
}