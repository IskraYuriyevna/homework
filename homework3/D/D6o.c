#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>

int main(){
    pid_t pid;
    int fd[2];

    if(pipe(fd)==-1){
        perror("pipe");
        return 1;
    }

    pid = fork();
    if(pid == -1){perror("fork");return 2;}
    else if(pid == 0){
        int num1 = 3;
        close(fd[0]);
        write(fd[1],&num1, sizeof(int));
        printf("Son num1 = %d\n",num1);
    }
    else{
        int num2;
        read(fd[0],&num2,sizeof(int));
        read();
        printf("Father num2 = %d\n",num2);
    }

    return 1;
}