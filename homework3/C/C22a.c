#include<stdio.h>
int main(int argc,char **argv){
    FILE *fi;
    FILE *fo;
    int num_buf;
    if(argc<3)
    {
        fprintf(stderr,"Use:%s text_file bin_file\n",argv[0]);
        return 1;
    }
    fi = fopen(argv[1],"r");
    if (fi == NULL)
    {
        fprintf(stderr,"Can't open file %s\n",argv[1]);
        return 1;
    }
    fo = fopen(argv[2],"w");
    if (fo==NULL)
    {
        fprintf(stderr,"Can't open file %s\n",argv[2]);
        return 1;
    }
    while(fscanf(fi,"%d",&num_buf)==1)
        fwrite(&num_buf,sizeof(int),1,fo);
    fclose(fi);
    fclose(fo);
    return 0;
}