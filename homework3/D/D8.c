#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    pid_t pid;
    int n,num=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        pid = fork();
        if(pid==-1){perror("fork");return 1;}
        num++;
        //创建子进程，并将其进程号写入pid
        if(pid==0){
            //pid == 0也就是在子进程运行的时候
            printf("son %d\n",num);
            fflush(stdout);
            fprintf(stderr,"PID=%d PPID=%d\n",getpid(),getppid());
            fflush(stderr);
            break;//如果在子进程，停止循环。防止反复输出和产生下一次分支。
        }
        wait(NULL);
    }
    //wait(NULL);
    for(int i=0;i<n;i++){wait(NULL);}
    //等待所有子进程结束之后再结束
    return 0;
}