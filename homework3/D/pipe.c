
int fd[2];
pipe(fd);

    pid = fork();
    if (pid == -1){perror("fork");return 1;}
    if (pid == 0){
        int num = 8;
        close(fd[0]);
        printf("Son send num = %d\n",num);
        //while(1){}
        write(fd[1],&num,sizeof(int));
        close(fd[1]);
    }else{
        int num2;
        close(fd[1]);
        read(fd[0],&num2,sizeof(int));
        printf("Father received num2",num2);
        close(fd[0]);
    }
    return 0;