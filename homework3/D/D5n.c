#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

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


    int i,j,h=1,gap,tmp,inum,jnum,tnum;
    off_t iP,jP;
    struct stat sfd;
    long size = sfd.st_size / sizeof(int);
    if(read(fd,&i,sizeof(int))==sizeof(int))
    {
        tmp = i;
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
                inum = read(fd,,sizeof(int));
                jnum = read(fd,,sizeof(int));
                tnum = read(fd,,sizeof(int));
            for (int j = i; j >= h && array[j] < array[j - h]; j -= h) {
                swap(array[j], array[j - h]);
                jnum = read(fd,,);
                tnum = ;
                lseek(fd,,SEEK_SET);
                write(fd,,sizeof(int));
                lseek(fd,,SEEK_SET);
                write(fd,,sizeof(int));
            }
        }
        h = h / 3;
    }


    close(fd);
    close(fd2);
    return 0;
}