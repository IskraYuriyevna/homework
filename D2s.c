#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <ctype.h>
#include <string.h>
#define BUF_SIZE 100

int main(int argc, char **argv){
    int fd1, fd2, size;
    char buf[BUF_SIZE];
    char word[BUF_SIZE];

    int wordLen = 0, sFlag = 0;
    if(argc < 3){
        fprintf(stderr, "Use: %s file_source file_dest\n", argv[0]);
        return 1;
    }

    fd1 = open(argv[1], O_RDONLY);
    if(fd1 == -1){
        perror("open");
        return 2;
    }

    struct stat s;
    stat(argv[1], &s);
    fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, s.st_mode);
    if(fd2 == -1){
        perror("open2");
        close(fd1);
        return 2;
    }

    while((size = read(fd1, buf, BUF_SIZE)) > 0){
        for(int i = 0; i < size; i++){
            if(isalpha(buf[i]) && (i == 0 || !isalpha(buf[i-1]))){
                sFlag = 1;
                wordLen = 0;
            }
            
            if(sFlag && isalpha(buf[i])){
                word[wordLen] = buf[i];
                wordLen++;
            }
            
            if(sFlag && !isalpha(buf[i]) && wordLen > 0){
                write(fd2, word, wordLen); 

                char lenStr[3]; 
                sprintf(lenStr, "%d", wordLen); 
                write(fd2, lenStr, strlen(lenStr)); 
                wordLen = 0; 
                sFlag = 0; 
            }
            
            if(sFlag == 0){
                write(fd2, &buf[i], 1);
            }
        }
    }

    close(fd1);
    close(fd2);

    return 0;
}