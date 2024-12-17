#include<stdio.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/shm.h>

int shm_ping_pong_2(key_t key){
    struct sembuf P0 = {0,-1,0};
    struct sembuf V1 = {1,1,0};

    int semid = semget(key,2,IPC_CREAT | 0666);
    if(semid<0){perror("semget");return 1;}

    int shmid = shmget(key,sizeof(int),IPC_CREAT | 0666);
    if(shmid<0){perror("shmget");return 1;}

    int *shmaddr = shmat(shmid,NULL,0);
    if(shmaddr == (int*)-1){perror("shmat");return 1;}

    do{
        semop(semid,&P0,1);
        if(*shmaddr == -1){
            shmdt(shmaddr);
            break;
        }
        printf("process2: %d\n",*shmaddr);
        fflush(stdout);
        (*shmaddr)++;
        semop(semid,&V1,1);
    }while(1);
    semctl(semid,0,IPC_RMID,0);
    shmctl(shmid,IPC_RMID,NULL);
    return 0;
}

int main(){
    key_t key = ftok("/bin/ls",18);
    if(key<0){perror("ftok");return 1;}

    if(shm_ping_pong_2(key)){
        return 1;
    }   
    return 0;
}