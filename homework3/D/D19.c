#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/wait.h>

typedef struct{
    int Dec;
    int Inc;
}cnt;

int main(){
    int cnt = 0;
    int fd[2];
    struct sembuf P1={},V1={};
    struct sembuf P2={},V2={};
    key_t key = ftok("/bin/ls",8);


}