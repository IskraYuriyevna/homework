#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    pid_t pid;
    pid = fork();
    if (pid == -1){perror("fork");return 1;}
    if (pid == 0){
        char *arg[] = {"ls","-l",NULL};
        execv("/bin/ls",arg);
        //execvp("ls",arg);
        //execlp("bin/ls","ls",NULL);
        fprintf(stderr,"Can't start ls\n");
        return 1;
    }else{
        wait(NULL);
    }
    return 0;
}
