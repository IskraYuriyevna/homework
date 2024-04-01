#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
//父进程从stidin读入数列并在管道中传输，子进程从管道中读取并计算加和
int main(){
    pid_t pid;
    int fd[2];
    if(pipe(fd)==-1){perror("pipe");return 1;}

    pid = fork();//建立进程
    if(pid<0){perror("fork");return 2;}
    if(pid>0){//父进程
        int num;
        close(fd[0]);
        while(scanf("%d",&num)==1)//读入数列
            write(fd[1],&num,sizeof(int));//从管道输入子进程
        close(fd[1]);
        wait(NULL);//等待子进程
    }else{//子进程 pid = 0；
        int num,sum = 0;
        close(fd[1]);
        while(read(fd[0],&num,sizeof(int))>0)//从管道中读取数字
            sum += num;
        printf("%d\n",sum);
        close(fd[0]);
    }//race condition2
    return 0;
}