#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    pid_t pid,cpid;
    int fd[2];
    if (pipe(fd)==-1){
        perror("pipe");return 1;
    }
    pid = fork();
    if(pid==-1){perror("fork");return 1;}
    if (pid==0){
        //子进程
        cpid = fork();
        if(cpid==-1){perror("fork");return 1;}
        if(cpid>0){
            //子进程
            int num,max,min,f=0;
            close(fd[1]);//关闭写端
            while(read(fd[0],&num,sizeof(num))){
                if (f){
                    if(num>max){
                        max = num;
                    }else if(num<min){
                        min = num;
                    }
                }else{
                    max = min = num;
                    f++;
                }
            }
            close(fd[0]);//关闭读端
            printf("%d %d",min,max);
            wait(NULL);
        }else{
            //孙子进程
            int num;
            close(fd[0]);//关闭读端
            while(scanf("%d",&num)==1){
                write(fd[1],&num,sizeof(int));
            }
            close(fd[1]);//关闭写端
        }
    }
    //由于父进程不需要读取也不需要输入，所以读端和写端都关闭
    close(fd[1]);
    close(fd[0]);
    //等待子进程和孙进程都结束之后再结束父进程
    wait(NULL);
    wait(NULL);
    return 0;
}