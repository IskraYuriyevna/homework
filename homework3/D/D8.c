#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    pid_t pid;
    int n,num=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        pid = fork();
        //创建子进程，并将其进程号写入pid
        if(pid==-1){perror("fork");return 1;}
        //创建进程失败时的错误处理
        if(pid==0){
            //pid == 0也就是在子进程运行的时候
            num++;
            printf("son %d\n",num);
            fflush(stdout);
            fprintf(stderr,"PID=%d PPID=%d\n",getpid(),getppid());
            fflush(stderr);
        }else{
            break;
            //如果在父进程，停止循环。防止父进程反复输出。
        }
        wait(NULL);
        //父进程等待子进程结束后再结束
    }

    while((pid=wait(NULL))>0);
    //等待所有子进程结束之后再结束
    return 0;
}