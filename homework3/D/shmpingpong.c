#include<stdio.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/shm.h>

int shm_ping_pong_1(key_t key){
    int Cnt_Max;
    struct sembuf V0 = {0,1,0};
    struct sembuf P1 = {1,-1,0};

    int semid = semget(key,2,IPC_CREAT | 0666);
    if(semid<0){perror("semget");return 1;}

    int shmid = shmget(key,sizeof(int),IPC_CREAT | 0666);
    if (shmid<0){ perror("shmget");return 1;}

    int *shmaddr = shmat(shmid,NULL,0);
    if(shmaddr==(int*)-1){perror("shmat");return 1;}

    scanf("%d",&Cnt_Max);

    *shmaddr = 0;
    semop(semid,&V0,1);//s0 = 0+1 process start

    int flag = 1;
    do{
        semop(semid,&P1,1);
        if(*shmaddr<Cnt_Max){
            printf("process1: %d\n",*shmaddr);
            fflush(stdout);
            (*shmaddr)++;
        }else{
            *shmaddr = -1;
            flag = 0;
        }
        semop(semid,&V0,1);
    }while(flag);
    
    shmdt(shmaddr);
    return 0;
}

int main(){
    key_t key = ftok("/bin/ls",18);
    if(key<0){perror("ftok");return 1;}

    if(shm_ping_pong_1(key)){
        return 1;
    }   
    return 0;
}