#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUF_SIZE 1001

int main(int argc,char **argv){
    int fd1,fd2,size,cnt=0,i=0,j=0;
    char buf[BUF_SIZE];
    char out[2*BUF_SIZE];

    if(argc<3){
        fprintf(stderr,"Use: %s flie_source file_dest\n",argv[0]);
        return 1;
    }   
    
    fd1 = open(argv[1],O_RDONLY);
    if(fd1==-1){
        perror("open");
        return 2;
    } 

    struct stat s;
    stat(argv[1],&s);
    fd2 = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC,s.st_mode);
    if(fd2==-1){
        perror("open2");
        close(fd2);
        return 2;
    }

    

    while((size = read(fd1,buf,BUF_SIZE)) > 0){
        for(i=0;i<size;i++){
            if(((buf[i]!=',')&(buf[i]!='.')&(buf[i]!=' ')&(buf[i]!='\n')))
            {
                out[j]=buf[i]; 
                cnt = cnt+1;
                j++;
            }else{
                if((cnt!=0)&(cnt<=99))
                {out[j]=(int)(cnt+48);j++;}
                out[j]=buf[i];
                j++;
                cnt=0;
            }
        }
        write(fd2,out,j);
    } 

    close(fd1);
    close(fd2);    
    return 0;
}