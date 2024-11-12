#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

void swapmax(int fd, long i, long j) {
    int m,n;
    //读取第i/j的位置的数字，并输入到m/n
    lseek(fd, i, SEEK_SET);
    read(fd,&m, sizeof(int));
    lseek(fd, j, SEEK_SET);
    read(fd,&n, sizeof(int));
    
    //如果m小于n,则交换
    if (m < n) {
        lseek(fd,j, SEEK_SET);
        write(fd,&m, sizeof(int));
        lseek(fd,i, SEEK_SET);
        write(fd,&n, sizeof(int));
    }
}

int main(int argc,char **argv){
    if(argc<3){
        fprintf(stderr,"Use:%s source_file target_file\n",argv[0]);
        return 1;
    }
    int fd = open(argv[1],O_RDWR);
    if(fd == -1){
        perror("open");
        return 2;
    }
    struct stat s;
    stat(argv[1],&s);
    int fd2 = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC,s.st_mode);
    if(fd2==-1){
        perror("open2");
        close(fd);
        return 2;
    }

    //获取文件大小，并且计算有多少int
    struct stat sfd;int i=0;long m,n;
    stat(argv[1],&sfd);
    long size = sfd.st_size;
    long ncnt = size / sizeof(int);

    //这段只是检测文件能不能读
    if(read(fd,&i,sizeof(int))==sizeof(int))
    {
        ;
    }else{
        close(fd);
        close(fd2);
        return 0;
    }

    //每次找出最大值写入目标文件
    for (i = 0; i < ncnt; i++) {
        int max;
        // 读取第一个数
        for (int j = 0; j < ncnt-1-i; j++) {
            m = j * sizeof(int);
            n = (j + 1) * sizeof(int);
            swapmax(fd,m,n);
        }
    }    
    //其实就是冒泡排序的文件版本

    int buf,j=0;
    for(i=size-sizeof(int);i>=0;i-=sizeof(int)){
        lseek(fd,i,SEEK_SET);
        read(fd,&buf,sizeof(int));
        lseek(fd2,i,SEEK_SET);
        write(fd2,&buf,sizeof(int));
        j += sizeof(int);
    }
    //将排好序的fd中的文件反向输入到fd2中
    
    close(fd);
    close(fd2);
    return 0;
}