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
    int max,min,tmp;
    off_t maxP,minP;

    if(read(fd,&tmp,sizeof(int))==sizeof(int)){
        max = min = tmp;
        maxP = minP = 0;
    }else{
        close(fd);
        return 3;
    }
    while(read(fd,&tmp,sizeof(int))==sizeof(int)){
        if(tmp>max){
            max = tmp;
            maxP = lseek(fd,0,SEEK_CUR)-sizeof(int);
        }
        if(tmp<min){
            min = tmp;
            minP = lseek(fd,0,SEEK_CUR)-sizeof(int);
        }
    }
    lseek(fd,maxP,SEEK_SET);
    write(fd,&min,sizeof(int));
    lseek(fd,minP,SEEK_SET);
    write(fd,&max,sizeof(int));
    close(fd);

    return 0;
}
