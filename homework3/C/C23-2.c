#include <stdio.h>
#include <stdlib.h>

#define SIZE 51

int main(int argc,char **argv){
    FILE *fin,*fout;
    char buf[SIZE];
    int num_str_copy = 0;

    if(argc<4){
        fprintf(stderr,"Use: %s input_file output_file num_of_string \n",argv[0]);
        return 1;
    }

    fin = fopen(argv[1],"r");
    if (fin == NULL){
        fprintf(stderr,"Can't open file %s\n",argv[1]);
        return 2;
    }
    fout = fopen(argv[2],"w");
    if (fout == NULL)
    {
        fprintf(stderr,"Can't open file %s\n",argv[2]);
        fclose(fin);
        return 2;
    }

    num_str_copy = atoi(argv[3]);
    if(num_str_copy <= 0)
    {
        fprintf(stderr,"Not correct number\n");
        fclose(fin);fclose(fout);
        return 3;
    }
    
    int count = 0;
    int ch;
    while ((ch = fgetc(fin)) != EOF && count < num_str_copy)
    {
        if(ch == '\n')
            count ++;
        fputc(ch,fout);
    }
    
    fclose(fin);
    fclose(fout);
    return 0;
}

