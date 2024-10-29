#include<stdio.h>

int main(int argc,char **argv)
{
    FILE *fin;
    FILE *fout;
    int bin;

    if (argc<3){
        fprintf(stderr,"Use: %s bin_file text_file\n",argv[0]);
        return 1;
    }
    fin = fopen(argv[1],"r");
    if (fin == NULL){
        fprintf(stderr,"Can't open %s this file",argv[1]);
        return 2;
    }
    fout = fopen(argv[2],"w");
    if (fout == NULL){
        fprintf(stderr,"Can't open %s this file",argv[2]);
        fclose(fin);
        return 2;
    }

    while(fread(&bin,sizeof(int),1,fin)==1){
        fprintf(fout,"%d ",bin);
    }

    fclose(fin);
    fclose(fout);
    return 0;
}
    