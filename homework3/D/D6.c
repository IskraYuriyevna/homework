#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    pid_t pid;
    int fd[2];
    if (pipe(fd)== -1){
        perror("pipe");return 1;
    }
    pid = fork();
    if(pid==-1){perror("fork");return 1;}
    if(pid>0){
        int num;
        close(fd[0]);
        while(scanf("%d",&num)==1){
            write(fd[1],&num,sizeof(int));
        }
        close(fd[1]);
        wait(NULL);
    }
    else {
        int num,sum = 0;
        close(fd[1]);
        while(read(fd[0],&num,sizeof(int))>0){
            sum += num;
        }
        close(fd[0]);
        printf("%d\n",sum);
    }
    return 0;
}