#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>//UNIX的系统操作接口库
#include<sys/stat.h>//获取文件的属性，例如，在打开文件失败时返回-1，成功则返回0；

#define BUF_SIZE 256

int main(int argc,char *argv[]){
//argc是argument count,argv是argument vector，argv[0]必是程序名称，故传入的参数个数应为argc-1个；
    int fd1,fd2,size;
    char buf[BUF_SIZE];//输入文件内容的缓冲区；
    struct stat s;//该结构体位于<sys/stat.h>，用于保存unix下的文件信息

    if (argc < 3){//侦测是否输入了足够多的参数（文件）；
        fprintf(stderr,"Use: %s file1 file2\n",argv[0]);
        return 1;
    }
    fd1 = open(argv[1],O_RDONLY);
    if(fd1 == -1){//输入文件无法打开的错误处理；
        fprintf(stderr,"Error:Can't open file %s\n",argv[1]);
        return 1;
    }
    stat(argv[1],&s);//获取文件的信息
    fd2 = open(argv[2],O_WRONLY | O_CREAT |O_TRUNC,s.st_mode);
    //第一个略，第二个指文件不存在时自动创建，第三个指打开文件时丢弃其中原有的内容；
    if(fd2 == -1){//输出文件无法打开的错误处理；
        fprintf(stderr,"Error:Can't open file %s\n",argv[2]);
        close(fd1);
        return 1;
    }

    while((size = read(fd1,buf,BUF_SIZE))>0)
    //将文件fd1的内容读取到缓冲区buf中;
        write(fd2,buf,size);
    //将buf中的内容写入到fd2中;
    close(fd1);
    close(fd2);
    return 0;
}