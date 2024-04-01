#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

#define BUF_SIZE 256

int main(int argc,char *argv[]){
    int fd1,fd2,size,cnt=0,j=0;
    char buf[BUF_SIZE];
    char otst[2*BUF_SIZE];
    struct stat s;

    if(argc<3){
       fprintf(stderr,"Use: %s file1 file2",argv[0]);
       return 1;
    }

    fd1 = open(argv[1],O_RDONLY);
    if(fd1 == -1){
        fprintf(stderr,"Error:Can't open %s",argv[1]);
        return 1;
    }
    stat(argv[1],&s);
    fd2 = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC,s.st_mode);    
    if(fd2 == -1){
        fprintf(stderr,"Error:Can't open %s",argv[2]);
        close(fd1);
        return 1;
    }
   
    while((size = read(fd1,buf,BUF_SIZE)) > 0){
        for(int i=0;i<size;i++){
            if((buf[i]!=','&buf[i]!='.'&buf[i]!=' '&buf[i]!='\n')){otst[j]=buf[i]; cnt = cnt+1;j++;}
            else{
                if(cnt!=0&cnt<=99){otst[j]=(int)(cnt+48);j++;}
                otst[j]=buf[i];j++;cnt=0;
            //printf("(%d,%d)",i,j);
            }
        }
        write(fd2,otst,j);
    } 
    //printf("buf = %s",buf);
    //printf("output stream,%s",otst);

close(fd1);
close(fd2);
return 0;
}