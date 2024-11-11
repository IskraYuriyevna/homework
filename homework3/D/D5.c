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
    off_t iP,jP;
    if(read(fd,&i,sizeof(long))==sizeof(long))
    {
        i = tmp;
        iP = 0;
    }else{
        close(fd);
        close(fd2);
        return 0;
    }
    while(read(fd,&i,sizeof(long))==sizeof(long))
    {
        if()
        {        

        }
    }
    

    close(fd);
    close(fd2);
    return 0;
}