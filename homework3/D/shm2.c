#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/sem.h>
#include<string.h>

#define MAX_SIZE 256

int main(){
    struct sembuf P = {0,-1,0};
    key_t key = ftok("a.txt",88);
    if(key < 0){perror("ftok");return 1;}

    int semid = semget(key,1,IPC_CREAT | 0666);
    if (semid < 0){perror("semget");return 1;}

    int shmid = shmget(key,MAX_SIZE,IPC_CREAT | 0666);
    if(shmid < 0){perror("shmget");return 1;}

    char* shmaddr = shmat(shmid,NULL,0);
    if(shmaddr==(char*)-1){perror("shmat");return 1;}

    semop(semid,&P,1);//s=s-1,if == 0,lock
    char buf[MAX_SIZE];
    strcpy(buf,shmaddr);

    printf("%s",buf);

    shmdt(shmaddr);
    semctl(semid,0,IPC_RMID,0);
    shmctl(shmid,IPC_RMID,0);
    return 0;
}   