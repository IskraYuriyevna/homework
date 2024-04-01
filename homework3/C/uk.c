#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[]){
    int i,num,k;
    float var;
    for ()
        printf("%s\n",argv[i]);
    k = sscanf(argv[1],"%d",&num);
//    num = atoi(argv[1]);
    printf("num = %d k = %d\n",num+1,k);
    sscanf(argv[3],"%f",&var);
//    var = atof(argv[3]);
    printf("var = %f\n",var*2+0.01);
    return 0;
}