#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/sem.h>
#include<string.h>

#define MAX_SIZE 256

int main(){
    struct sembuf V = {0,1,0};
    key_t key = ftok("a.txt",88);
    if(key<0){perror("ftok");return 1;}

    int semid = semget(key,1,IPC_CREAT | 0666);//
    if (semid<0){perror("semget");return 1;};

    int shmid = shmget(key,MAX_SIZE,IPC_CREAT | 0666);
    if(shmid < 0){perror("shmget");return 1;}

    char *shmaddr = shmat(shmid,NULL,0);//
    if(shmaddr == (char*)-1){perror("shmat");return 1;}

    char str[MAX_SIZE];
    fgets(str,MAX_SIZE,stdin);

    strcpy(shmaddr,str);

    semop(semid,&V,1);

    shmdt(shmaddr);
    return 0;
}    