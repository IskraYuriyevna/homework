#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc,char **argv){
    // 虽然可以有任意个命令，但最少不能少于四个参数
    if (argc < 4) {
        fprintf(stderr, "Usage: %s cmd1 arg1 ...| cmd2 arg2 ...| ...\n", argv[0]);
        return 1;
    }

    // 动态分配命令数组，这将是一个二维数组所以应该多一个*
    // 最多的情况：除了"|"全是命令，也就是argc/2+1个
    char ***cmd = malloc(sizeof(char **) * (argc/2+1));
    int ncmd = 0;//number of commands
    int narg = 0;//number of arguments

    // 创建第二层数组的第一个，并分配存储空间
    cmd[ncmd] = malloc(sizeof(char *) * (argc+1));
    {
        if(cmd[ncmd]==NULL){
            fprintf(stderr,"Can't allocate memory\n");
            return 2;
        }
    }
    // 循环的输入参数，以"|"为间隔，存储在第二层数组
    for (int i=1;i<argc;i++) {
        if (strcmp(argv[i], "|") == 0) {
            cmd[ncmd][narg] = NULL; // 在结尾添加NULL表示命令结束
            ncmd++;
            narg = 0;
            // 给下一个命令的数组分配存储空间
            cmd[ncmd] = malloc(sizeof(char *) * (argc+1)); 
            if(cmd[ncmd] == NULL){
                fprintf(stderr,"Can't allocate memory\n");
                return 2;
            }
        } else {
            cmd[ncmd][narg++] = argv[i];// 将命令的参数添加到数组
        }
    }
    cmd[ncmd][narg] = NULL; // 在最后一个命令结尾添加NULL表示命令结束
    ncmd++;

    //创建一个二维数组储存所有的管道，其中管道的数量比命令数量少1，共ncmd-1个
    int **fd = malloc(sizeof(int*)*(ncmd-1));
    if(fd == NULL){
        for(int i=0;i<ncmd;i++){
            free(cmd[i]);
        }
        free(cmd);
        fprintf(stderr,"Can't allocate memory\n");
        return 2;
    }

    //创建所有管道
    for(int i=0;i<(ncmd-1);i++){
        fd[i]=malloc(sizeof(int)*2);
        
        if (pipe(fd[i])==-1){
            perror("pipe");
            for (int j = 0; j < i; j++) {
                close(fd[j][0]);
                close(fd[j][1]);
                free(fd[j]);
            }
            free(fd);
            return 3;
        }
    }

    //创建子进程并运行命令，子进程数量就是ncmd
    for (int i=0;i<ncmd;i++) {
        //创建子进程
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            return 4;
        }
        // 子进程
        if (pid == 0) {            
            if(i>0){
                if(dup2(fd[i-1][0],0)<0){perror("dup2");return 1;}
            }
            if(i<ncmd-1){
                if(dup2(fd[i][1],1)<0){perror("dup2");return 1;}
            }
            //关闭所有管道
            for (int j=0;j<(ncmd-1);j++) {
                close(fd[j][0]);close(fd[j][1]);
            }
            //执行命令行命令
            execvp(cmd[i][0],cmd[i]);
            perror("execvp");
            return 5;
        }
    }
    // 父进程，这个爹的孩子还可能特别多
    // 关闭所有管道
    for (int i=0;i<(ncmd-1);i++) {
        // printf("Read end: %d\n", fd[i][0]);
        // printf("Write end: %d\n", fd[i][1]);
        close(fd[i][0]);close(fd[i][1]);
    }
    // 等待所有子进程结束
    for (int i=0;i<ncmd;i++) {
        wait(NULL);
    }
    //释放动态分配的内存
    for(int i=0;i<ncmd;i++){
        free(cmd[i]);
    }
    free(cmd);
    for (int j=0;j<ncmd-1;j++) {
            free(fd[j]);
    }
    free(fd);

    return 0;
}