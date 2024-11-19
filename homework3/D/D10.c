#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc,char **argv)
{
	if (argc < 5)
	{
		fprintf(stderr,"Use: %s command arg1 arg2 file\n",argv[0]);
		return 1;
	}
	pid_t pid = fork();
	if(pid == -1){perror("fork");return 2;}
	if(pid == 0)// son
	{
		int fd = open(argv[4],O_WRONLY | O_CREAT | O_TRUNC,0664);
		if(fd == -1)
		{
			perror("open");
			return 3;
		}
		dup2(fd,1); // copy fd to 1 
		close(fd);// close 3
		execlp(argv[1],argv[1],argv[2],argv[3],NULL);
		perror("execlp");
		return 4;
	}
	else//father
	{
		wait(NULL);
	}
	return 0;
}

