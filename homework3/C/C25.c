#include<stdio.h>

int main(int argc,char **argv)
{
    FILE *fin;
    FILE *fout;
    int num;

    if (argc < 3)
    {
        fprintf(stderr,"Use: %s text_file bin_file\n",argv[0]);
        return 1;
    }
    fin = fopen(argv[1],"r");
    if (fin==NULL)
    {
        fprintf(stderr,"Can't open %s this file\n",argv[1]);
        return 2;
    }
    fout = fopen(argv[2],"w");
    if(fout == NULL)
    {
        fprintf(stderr,"Can't open %s this file\n",argv[2]);
        fclose(fin);
        return 2;
    }

    while(fscanf(fin,"%d",&num)==1)
    {
        fwrite(&num,sizeof(int),1,fout);
    }

    fclose(fin);
    fclose(fout);
    return 0;
}