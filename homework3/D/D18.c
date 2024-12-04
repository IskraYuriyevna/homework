#include<stdio.h>
#include<unistd.h>// Unix标准函数的头文件，比如pipe和fork
#include<sys/ipc.h>// 进程间通讯的头文件，semget,semctl和semop
#include<sys/sem.h>// 信号量操作的头文件,struct,sembuf和SETVAL等
#include<sys/wait.h>// 等待进程状态改变的头文件，基本上就用到wait

int main(){
    int cnt = 0,Cnt_Max;
    int fd[2];
    // 定义两个信号量操作结构体P1和V1，分别用于等待（P操作）和释放（V操作）信号量0。
    struct sembuf P1={0,-1,0},V1={0,1,0};
    // 定义另外两个信号量操作结构体P2和V2，分别用于等待（P操作）和释放（V操作）信号量1。
    struct sembuf P2={1,-1,0},V2={1,1,0};
    // 使用ftok函数生成一个键值，用于创建信号量。"/bin/ls"是路径名，8是项目ID。
    key_t key = ftok("/bin/ls",8);
    
    if(key<0){perror("ftok");return 1;}

    //使用semget函数创建一个包含两个信号量的信号量集，IPC_CREAT标志表示如果信号量集不存在则创建它，0666是权限设置。
    //如果 key 为非零值，系统会根据这个键值查找一个已经存在的信号量集。
    //如果找到了，就返回这个信号量集的标识符；如果没有找到，就会根据后面的参数创建一个新的信号量集。
    //在八进制权限中，0666 表示文件所有者、文件所在组以及其他用户都有读写权限（即 rw-rw-rw-）。
    //这个权限设置允许多个用户对信号量进行操作。
    int semid = semget(key,2,IPC_CREAT | 0666);
    //创建两个信号量
    if(semid < 0){perror("semget");return 1;}
    semctl(semid,0,SETVAL,0);// s1 = 0，使用semctl函数设置信号量0的值为0。
    semctl(semid,1,SETVAL,0);// s2 = 0，使用semctl函数设置信号量1的值为0。

    if(pipe(fd)<0){perror("pipe");return 1;}
    scanf("%d",&Cnt_Max);
    pid_t pid = fork();
    if(pid<0){perror("fork");return 1;}
    if(pid>0){//father
        write(fd[1],&cnt,sizeof(int));
        semop(semid,&V1,1);// 父进程释放信号量0。
        while(cnt<Cnt_Max){
            semop(semid,&P2,1);// 父进程等待信号量1。
            read(fd[0],&cnt,sizeof(int));
            printf("father %d\n",cnt++);fflush(stdout);
            write(fd[1],&cnt,sizeof(int));
            semop(semid,&V1,1);// 父进程释放信号量0。
        }
        close(fd[0]);close(fd[1]);
        wait(NULL);
        semctl(semid,0,IPC_RMID,0);// 父进程删除信号量集。
    }else{//son
        while(cnt < Cnt_Max){
            semop(semid,&P1,1);// 子进程等待信号量0。
            read(fd[0],&cnt,sizeof(int));
            printf("son %d\n",cnt++);fflush(stdout);
            write(fd[1],&cnt,sizeof(int));
            semop(semid,&V2,1);// 子进程释放信号量1。
        }
        close(fd[0]);close(fd[1]);
    }

    return 0;
}
