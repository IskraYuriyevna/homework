#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
	pid_t pid;
	int fd[2];
	pipe(fd);

	pid = fork();
	if (pipe(fd)==-1){perror("pipe");return 1;}
			
	if(pid == -1){perror("fork");return 1;}
	if(pid == 0){
		int num = 8;
		close(fd[0]);
		printf("Son send num = %d\n",num);
		write(fd[1],&num,sizeof(int));
		close(fd[1]);
	}else{
		int num2;
		close(fd[1]);
		read(fd[0],&num2,sizeof(int));
		printf("Father received num2 = %d\n",num2);
		close(fd[0]);
	}
	return 0;

		
}
