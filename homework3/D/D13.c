#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>

int main(int argc,char **argv)
{
    if (argc<7)
    {
        fprintf(stderr,"Use: %s pr1 arg1 | pr2 arg2 arg3 | pr3\n",argv[0]);
		return 1;
    }
    int fd[2];
    if (pipe(fd)<0){perror("pipe");return 2;}
    int fd2[2];
    if (pipe(fd2)<0){perror("pipe");return 2;}

    pid_t pid = fork();
    if(pid == -1){perror("fork");return 3;}
    if(pid == 0)// son
	{
        
		if (dup2(fd[1],1)<0){perror("dup2");return 1;}
        close(fd[0]);close(fd[1]);
		close(fd2[0]);close(fd2[1]);execlp(argv[1],argv[1],argv[2],NULL);
		perror("execlp");
		return 4;
	}

    pid_t pid2 =fork();
    if(pid2<0){perror("fork");return 3;}
    if(pid2==0)
    {
        if (dup2(fd[0],0)<0){perror("dup2");return 1;}
        if (dup2(fd2[1],1)<0){perror("dup2");return 1;}
		close(fd[0]);close(fd[1]);
        close(fd2[0]);close(fd2[1]);
		execlp(argv[3],argv[3],argv[4],argv[5],NULL);
		perror("execlp");
		return 4;
    }

    pid_t pid3 =fork();
    if(pid3<0){perror("fork");return 3;}
    if(pid3==0)
    {
        if (dup2(fd2[0],0)<0){perror("dup2");return 1;}
		close(fd[0]);close(fd[1]);
        close(fd2[0]);close(fd2[1]);
		execlp(argv[6],argv[6],NULL);
		perror("execlp");
		return 4;
    }

    close(fd[0]);close(fd[1]);
    close(fd2[0]);close(fd2[1]);
    wait(NULL);
    wait(NULL);
    wait(NULL);
    return 0;
}
