#include<stdio.h>
#include<string.h>

#define SIZE 1001

int main(int argc,char **argv){
    FILE *fin,*fout;
    char buf[SIZE];
    int cnta=0,cntl=0,flga=0;

    if(argc<3){
        fprintf(stderr,"Something's wrong");
        return 1;
    }
    fin = fopen(argv[1],"r");
    if(fin == NULL){
        fprintf(stderr,"Something's wrong");
        return 2;
    }
    fout = fopen(argv[2],"w");
    if(fout == NULL){
        fprintf(stderr,"Something's wrong"); 
        fclose(fin);
        return 2;
    }

    while(fgets(buf,SIZE,fin) != NULL){
        int len = strlen(buf);
        for (int i=0;i<len;i++){
            if((buf[i]==' ')||(buf[i]=='.')){
                if(buf[i-1]=='a'){
                    cnta++;
                    flga++;
                    // printf("find a at %d\n",i);
                }
            }
            if((buf[i]=='\n')||(buf[i]==EOF)){
                if (buf[i-1]=='a'){
                    cnta++;
                    flga++;
                    // printf("find a on end at %d\n",i);
                }
                if(flga){
                    cntl++;
                    flga = 0;
                    // printf("another line,i = %d\n",i);
                }
            }
        }
    }

    fprintf(fout,"%d %d",cnta,cntl);

    fclose(fin);
    fclose(fout);
    return 0;
}