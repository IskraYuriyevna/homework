#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

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

    long max,tmp;
    off_t maxP;
    if(read(fd,&tmp,sizeof(long))==sizeof(long))
    {
        max = tmp;
        maxP = 0;
    }else{
        close(fd);
        return 3;
    }
    while(read(fd,&tmp,sizeof(long))==sizeof(long))
    {
        if(tmp>max)
        {
            max = tmp;
            maxP = lseek(fd,0,SEEK_CUR)-sizeof(long);
        }
    }
    lseek(fd,maxP,SEEK_SET);
    tmp = max*2;
    write(fd,&tmp,sizeof(long));

    close(fd);
    return 0;
}