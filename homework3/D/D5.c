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


    int i,j,gap,tmp;
    off_t iP,jP,nP;
    struct stat sfd;
    long size = sfd.st_size / sizeof(int);
    if(read(fd,&i,sizeof(int))==sizeof(int))
    {
        tmp = i;
        iP = 0;
    }else{
        close(fd);
        close(fd2);
        return 0;
    }
    for(gap = size>>1;gap > 0;gap>>=1){
        while(read(fd,&i,sizeof(int))==sizeof(int))
        {
            tmp = i;
            iP = lseek(fd,,SEEK_CUR)-sizeof(int);
            jP = ;
            for(jP = iP-(gap*sizeof(int));jP>=0&&j>tmp;jP-=gap*(sizeof(int))){
                jP+;
            }
            jP = ;
        }
    }
    

    close(fd);
    close(fd2);
    return 0;
}