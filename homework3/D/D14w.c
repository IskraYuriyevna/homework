#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int execcmd(char **args, int infd, int otfd) {
    // 将管道的输入段重定向到stdin
    if (infd != 0) {
        dup2(infd, 0);
        close(infd);
    }
    // 将管道的输出端重定向到stdout
    if (otfd != 1) {
        dup2(otfd, 1);
        close(otfd);
    }
    // execvp使用字符串数组传递参数，execlp使用可变参数列表传递参数，这里更适合execvp
    execvp(args[0], args);
    perror("execvp");
    return 5;
}

int main(int argc, char **argv) {
    // 虽然可以有任意个命令，但最少不能少于两个参数
    if (argc < 2) {
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

    // 创建并且用一个数组来存储所有的管道
    // 除了头尾只需要一半之外，每个进程需要一个，共ncmd-1个
    // 有 ncmd 个命令，就有 ncmd-1 个管道。
    // 每个管道有两个文件描述符：读端和写端。因此，总共有 2*(ncmd-1) 个文件描述符。
    // 其中的偶数标号是读端，奇数标号是写端。
    int fd[2*(ncmd-1)];
    for (int i=0;i<ncmd-1;i++) {
        if (pipe(fd+i*2) == -1) {
            perror("pipe");
            return 3;
        }
    }

    // 创建子进程并运行命令，子进程数量就是ncmd
    for (int i=0;i<ncmd;i++) {
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            return 4;
        }
        // 子进程
        if (pid == 0) {
            // 从前一个管道读取，也就是第i-1个进程的读端(i-1)*2
            if (i > 0) {
                dup2(fd[(i-1)*2], 0); 
            }
            // 写入下一个管道，也就是本进程的写端(i*2)+1
            if (i < ncmd - 1) {
                dup2(fd[i*2+1], 1); 
            }
            // 关闭所有管道
            for (int j=0;j<2*(ncmd-1);j++) {
                close(fd[j]);
            }
            // 执行命令行命令
            if(execcmd(cmd[i], 0, 1)==5){
                return 5;
            }
        }
    }
    // 父进程，这个爹的孩子还可能特别多
    // 关闭所有管道
    for (int i=0;i<2*(ncmd-1);i++) {
        close(fd[i]);
    }
    // 等待所有子进程结束
    for (int i=0;i<ncmd;i++) {
        wait(NULL);
    }
    // 释放动态分配的内存
    for (int i=0;i<ncmd;i++) {
        free(cmd[i]);
    }
    free(cmd);

    return 0;
}