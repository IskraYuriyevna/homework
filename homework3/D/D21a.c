#include<stdio.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/shm.h>

int shm_ping_pong_1(key_t key){
    int shmid,semid,Cnt_Max;
    int flag=1;
    struct sembuf V0 = {0,1,0};
    struct sembuf P1 = {1,-1,0};
    int *shmaddr;
    scanf("%d",&Cnt_Max);
    shmid=shmget(key,sizeof(int),IPC_CREAT|0666);
    if(shmid<0){perror("shmget");return 1;}
    
    shmaddr=shmat(shmid,NULL,0);
    if(shmaddr==(void*)-1){perror("shmat");return 1;}
    semid = semget(key,2,IPC_CREAT|0666);
    if(semid<0){perror("semget");return 1;}

    *shmaddr=0;
    semop(semid,&V0,1);
    do{
        semop(semid,&P1,1);
        if(*shmaddr<Cnt_Max)
        {
            printf("process1:%d\n",*shmaddr);
            fflush(stdout);
            (*shmaddr)++;
        }else{
            *shmaddr=-1;
            flag=0;
        }
        semop(semid,&V0,1);
    }while(flag);
    shmdt(shmaddr);
    return 0;
}