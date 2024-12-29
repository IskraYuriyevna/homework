#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/wait.h>

typedef struct{
    int Dec;
    int Inc;
}cnt;

volatile sig_atomic_t flag = 1;
volatile sig_atomic_t pctl = 1;

int main(){
    cnt Cnt;
    int fd[2];
    struct sembuf P1={0,-1,0},V1={0,1,0};//father
    struct sembuf P2={1,-1,0},V2={1,1,0};//son1
    struct sembuf P3={2,-1,0},V3={2,1,0};//son2
    pid_t pid,pid2;

    key_t key = ftok("/bin/ls",8);
    if(key<0){perror("ftok");return 0;}

    int semid = semget(key,4,IPC_CREAT|0666);
    if(semid<0){perror("semget");return 1;}
    semctl(semid,0,SETVAL,0);//s1=0
    semctl(semid,1,SETVAL,0);//s2=0
    semctl(semid,2,SETVAL,0);//s3=0

    if(pipe(fd)<0){perror("pipe");return 1;}

    scanf("%d %d",&Cnt.Dec,&Cnt.Inc);

    pid = fork();
    if(pid<0){perror("fork");return 1;}
    if(pid>0){
        pid2 = fork();
        if(pid2<0){perror("fork");return 1;}
        if(pid2>0){//father
            write(fd[1],&Cnt,sizeof(cnt));
            semop(semid,&V2,1);
            while(Cnt.Inc<Cnt.Dec){
                semop(semid,&P1,1);
                read(fd[0],&Cnt,sizeof(cnt));
                if(Cnt.Inc<=Cnt.Dec){
                    printf("father %d %d\n",Cnt.Dec,Cnt.Inc);fflush(stdout);
                    Cnt.Dec--;Cnt.Inc++;
                }
                write(fd[1],&Cnt,sizeof(cnt));
                if(pctl){
                    semop(semid,&V3,1);
                }else{
                    semop(semid,&V2,1);
                }
            }
            close(fd[0]);close(fd[1]);
            wait(NULL);wait(NULL);
            semctl(semid,0,IPC_RMID,0);
        }else{//son2
            while(Cnt.Inc<Cnt.Dec){
                semop(semid,&P3,1);
                read(fd[0],&Cnt,sizeof(cnt));
                if(Cnt.Inc<=Cnt.Dec){
                    printf("son2 %d %d\n",Cnt.Dec,Cnt.Inc);fflush(stdout);
                    Cnt.Dec--;Cnt.Inc++;
                }
                write(fd[1],&Cnt,sizeof(cnt));
                pctl = 
                semop(semid,&V1,1);
            }
            close(fd[0]);close(fd[1]);
        }
    }else{//son1
        if(flag){
            if(Cnt.Inc==Cnt.Dec){printf("son1 %d %d\n",Cnt.Dec,Cnt.Inc);fflush(stdout);}
            flag--;
        }
        while(Cnt.Inc<Cnt.Dec){
            semop(semid,&P2,1);
            read(fd[0],&Cnt,sizeof(cnt));
            if(Cnt.Inc<=Cnt.Dec){
                printf("son1 %d %d\n",Cnt.Dec,Cnt.Inc);fflush(stdout);
                Cnt.Dec--;Cnt.Inc++;
            }
            write(fd[1],&Cnt,sizeof(cnt));
            pctl = 
            semop(semid,&V1,1);
        }
        close(fd[0]);close(fd[1]);
    }
    return 0;
}