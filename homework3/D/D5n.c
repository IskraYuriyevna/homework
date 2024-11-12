#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#define BUF_SIZE 1001

int main(int argc,char **argv){
    if(argc<2){
        fprintf(stderr,"Use:%s file_name\n",argv[0]);
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

    int i,j,h=1,inum,jnum,tnum;
    //off_t iP,jP,tP;
    struct stat sfd;
    stat(argv[1],&sfd);
    long size = sfd.st_size / sizeof(int);
    if(read(fd,&i,sizeof(int))==sizeof(int))
    {
        ;
    }else{
        close(fd);
        close(fd2);
        return 0;
    }

    while (h < size / 3) {
        h = 3 * h + 1;
    }
    while (h >= 1) {
        for (int i = h; i < size; i++) {
                lseek(fd,i*sizeof(int),SEEK_SET);
                read(fd,&inum,sizeof(int));
                read(fd,&jnum,sizeof(int));
                lseek(fd,(i-h)*sizeof(int),SEEK_SET);
                read(fd,&tnum,sizeof(int));
            for (j = i; j >= h && jnum > tnum; j -= h) {
                lseek(fd,j*sizeof(int),SEEK_SET);
                read(fd,&jnum,sizeof(int));
                lseek(fd,(j-h)*sizeof(int),SEEK_SET);
                read(fd,&tnum,sizeof(int));
                write(fd,&jnum,sizeof(int));
                lseek(fd,j*sizeof(int),SEEK_SET);
                write(fd,&tnum,sizeof(int));
            }
        }
        h = h / 3;
    }

    char buf[BUF_SIZE];
    while((size = read(fd,buf,BUF_SIZE))>0){
        write(fd2,buf,size);
    }

    close(fd);
    close(fd2);
    return 0;
}