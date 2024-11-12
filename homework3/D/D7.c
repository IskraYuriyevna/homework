#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    pid_t pid,cpid;
    //两个进程号，初始进程号和现在的进程号
    int n,num1,num2; 
    //输入的数字，第一个数字和第二个数字
    pid = getpid();
    //保存初始进程号
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        cpid = fork();
        //创建子进程，并将其进程号写入cpid
        if(cpid==-1){perror("fork");return 1;}
        //创建进程失败时的错误处理
        if(cpid==0){
            //cpid == 0也就是在子进程运行的时候
            num1 = getpid()-getppid();
            num2 = getpid()-pid;
            printf("%d %d\n",num1,num2);
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

    while((cpid=wait(NULL))>0);
    //等待所有子进程结束之后再结束
    return 0;
}