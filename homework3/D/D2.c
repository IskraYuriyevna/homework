#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>

#define BUF_SIZE 99

int main(int argc,char **argv){
    int fd1,fd2,size,cnt,sin=0,i=0,j=0,k=0;
    char buf[BUF_SIZE];
    char *in = NULL;
    char *out = NULL;

    if(argc<3){
        printf("Use: %s flie_source file_dest\n",argv[0]);
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
        close(fd1);
        return 2;
    }

    int sizein = BUF_SIZE;
    in = (char *)malloc(sizein*sizeof(char));
    if(in == NULL){
        fprintf(stderr,"Can't allocate memory\n");
        return 1;
    }

    while((size = read(fd1,buf,BUF_SIZE)) > 0){
        for(i = 0;i<size;i++){
            in[sin]=buf[i];
            sin++;
        }
        if (sin == sizein){
            char *buf2 = NULL;
            sizein *= 2;
            buf2 = (char*)realloc(in,sizein*sizeof(char));
            if(buf2==NULL){
                sizein /= 2;
                fprintf(stderr,"Can't realloc memory\n");
                break;
            }else{
                in = buf2;
            }
        }
    }
    //printf("sin= %d,sizein = %d\n",sin,sizein);

    int sizeout = sin;
    out = (char *)malloc(sizein*sizeof(char));
    if(out == NULL){
        fprintf(stderr,"Can't allocate memory\n");
        return 1;
    }
    cnt = 0;j=0;
    for(i=0;i<sizein;i++){
        if(((in[i]!=',')&(in[i]!='.')&(in[i]!=' ')&(in[i]!='\n')))
        {
            out[j]=in[i]; 
            cnt = cnt+1;
            j++;

        }else{
            if((cnt!=0)&(cnt<=99)){
                if((cnt>0)&(cnt<=9)){
                    out[j]=cnt+'0';
                    j++;
                }else{
                    out[j+1]= cnt%10+'0';
                    out[j]= cnt/10+'0';
                    j+=2;
                }
            }
            out[j]=in[i];
            j++;
            cnt=0;
        }
        if (j == sizeout){
            char *bufout = NULL;
            sizeout *= 2;
            bufout = (char*)realloc(out,sizeout*sizeof(char));
            if(bufout==NULL){
                sizeout /= 2;
                fprintf(stderr,"Can't realloc memory\n");
                break;
            }else{
                out = bufout;
            }
        }
    }
    write(fd2,out,j-1);

    free(in);
    free(out);
    close(fd1);
    close(fd2);    
    return 0;
}