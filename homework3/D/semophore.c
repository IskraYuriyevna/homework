#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/wait.h>

int main() {
    pid_t pid;
    int fd[2];
    pipe(fd);
    int key;
    int semid;
    struct sembuf P = {0,-1,0}, V = {0,1,0};

    key = ftok("a.txt",5); 



    pid = fork(); //创建子进程
    if(pid == -1) {perror("fork");return 1;}
    if(pid == 0) {
        int num = 8, num2;
        printf("Son's sent num = %d\n",num);
        write(fd[1],&num,sizeof(int));
        semop(semid,&P,1); // P(s) s = s - 1 = 1 - 1 = 0;
        read(fd[0],&num2,sizeof(int));
        printf("Son's received num2 = %d\n",num2);
        close(fd[0]);//
        close(fd[1]);
    } else {
        int num2,num3 = 6;
        read(fd[0],&num2,sizeof(int));
        printf("Father's received num2 = %d\n",num2);
        printf("Father's sent num3 = %d\n",num3);
        write(fd[1],&num3,sizeof(int));
        semop(semid,&V,1);//V(s) = S + 1 = 0 + 1 = 1;
        close(fd[0]);
        close(fd[1]);
        wait(NULL);
        semctl(semid,0,IPC_RMID,0);//
    }

    return 0;
}