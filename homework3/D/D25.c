#include<signal.h>
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/shm.h>
#include<sys/wait.h>
#include<unistd.h>

int main(){
    int N;
    pid_t pid1,pid2;

    struct sembuf V0 = {0,1,0};
    struct sembuf P0 = {0,-1,0};
    struct sembuf V1 = {1,1,0};
    struct sembuf P1 = {1,-1,0};

    scanf("%d",&N);

    key_t key = ftok("/bin/ls",18);
    if(key<0){perror("ftok");return 1;}

    int semid = semget(key,2,IPC_CREAT | 0666);
    if(semid<0){perror("semget");return 1;}

    int shmid = shmget(key,(N+1)*sizeof(long long),IPC_CREAT | 0666);
    if(shmid<0){perror("shmget");return 1;}

    long long *shmaddr = shmat(shmid,NULL,0);
    if(shmaddr == (long long *)-1){perror("shmat");return 1;}

    shmaddr[0] = 0;shmaddr[1]=1;shmaddr[N]=2;
    semop(semid,&V1,1);//to son 1;

    pid1 = fork();
    if(pid1<0){perror("fork");return 1;}
    if(pid1==0){//son1
        int i;
        do{
            semop(semid,&P1,1);
            if(shmaddr[N]==N){
                shmdt(shmaddr);
                break;
            }
            i = shmaddr[N];
            shmaddr[i] = shmaddr[i-2] + shmaddr[i-1];
            shmaddr[N]++;
            //printf("son1: %lld \n",shmaddr[i]);
            semop(semid,&V0,1);
        }while(1); 
        return 0;
    }else{

    pid2 = fork();
    if(pid2<0){perror("fork");return 1;}
    if(pid2==0){//son2
        int i;
        do{
            semop(semid,&P0,1);
            if(shmaddr[N]==N){
                shmdt(shmaddr);
                break;
            }
            i = shmaddr[N];
            shmaddr[i] = shmaddr[i-2] + shmaddr[i-1];
            shmaddr[N]++;
            //printf("son2: %lld \n",shmaddr[i]);
            semop(semid,&V1,1);
        }while(1);
        return 0;
    }else{
    
    wait(NULL);
    semctl(semid,0,IPC_RMID,0);//delete all semophore
    wait(NULL);

    for(int i;i<N;i++){
        printf("%lld ",shmaddr[i]);
    }

    shmdt(shmaddr);//detaching from the shared memory segment
    shmctl(shmid,IPC_RMID,NULL);//delete shm
    return 0;
    }
    }

}