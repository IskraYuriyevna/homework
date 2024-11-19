#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc,char **argv){
	if(argc<5){
		fprintf(stderr,"Use %s com1 arg1 arg2 com2\n",argv[0]);
		return 1;
	}
	int fd[2];
	if (pipe(fd)<0){perror("pipe");return 1;}
	pid_t pid1 = fork();
	if(pid1<0){perror("fork");return 1;}
	if(pid1==0)//process son 1
	{
		if (dup2(fd[1],1)<0){perror("dup2");return 1;}
		close(fd[0]);close(fd[1]);
		execlp(argv[1],argv[1],argv[2],argv[3],NULL);
		perror("execlp");
		return 1;
	}
	pid_t pid2 = fork();
	if(pid2<0){perror("fork");return 1;}
	if(pid2==0)//process son 2
	{
        if (dup2(fd[0],0)<0){perror("dup2");return 1;}
        close(fd[0]);close(fd[1]);
        execlp(argv[4],argv[4],NULL);
        perror("execlp");
        return 1;
	}
	close(fd[0]);close(fd[1]);
	wait(NULL);
	wait(NULL);
	return 0;
}
