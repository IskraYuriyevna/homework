#include<signal.h>
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/shm.h>
#include<unistd.h>

int main(){
    int N;
    pid_t pid1,pid2;

    struct sembuf V0 = {0,1,0};
    struct sembuf P1 = {1,-1,0};
    
    struct sembuf V1 = {1,1,0};
    struct sembuf P0 = {0,-1,0};

    scanf("%d",&N);

    key_t key = ftok("/bin/ls",18);
    if(key<0){perror("ftok");return 1;}

    int semid = semget(key,2,IPC_CREAT | 0666);
    if(semid<0){perror("semget");return 1;}

    int shmid = shmget(key,N*sizeof(int),IPC_CREAT | 0666);
    if(shmid<0){perror("shmget");return 1;}

    int *shmaddr = shmat(shmid,NULL,0);
    if(shmaddr == (int*)-1){perror("shmat");return 1;}

    pid1 = fork();
    if(pid1<0){perror("fork");return 1;}
    if(pid1==0){//son1
        int flag = 1;
        do{
        semop(semid,&P1,1);

        semop(semid,&V0,1);
        }while(flag); 

    }

    pid2 = fork();
    if(pid2<0){perror("fork");return 1;}
    if(pid2==0){//son2
        do{
            semop(semid,&P0,1);
            if(*shmaddr == -1){
                shmdt(shmaddr);
                break;
            }
        (*shmaddr)++;
        semop(semid,&V1,1);
    }while(1);
    }

    semctl(semid,0,IPC_RMID,0);//delete all semophore
    shmdt(shmaddr);//detaching from the shared memory segment
    shmctl(shmid,IPC_RMID,NULL);//delete shm
    return 0;
}