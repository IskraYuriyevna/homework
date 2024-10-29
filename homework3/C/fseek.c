#include <stdio.h>

int main(int argc,char **argv){
    FILE *f;
    long offset;
    long count;
    if (argc < 2){
        fprintf(stderr,"Use: %s bin_file\n",argv[0]);
        return 1;
    }
    f = fopen(argv[1],"r");
    if (f == NULL){
        fprintf(stderr,"Can't open file%s\n",argv[1]);
        return 1;
    }
    fseek(f,0,SEEK_END);
    offset = ftell(f);
    count = offset/sizeof(int);
    printf("%ld\n",count);
    return 0;
}