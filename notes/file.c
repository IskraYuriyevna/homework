# include <stdio.h>

FILE *f;
FILE *fopen(const char * filename,const char * mode);
//return NULL if error

// "r" - 只读模式
// "w" - 写入模式
// "a" - 追加模式
// "r+" - 读写模式，同时读写文件
// "w+" - 读写模式，写入前会清空内容
// "a+" - 读追加模式

int fprintf(FILE *f,const char *str,...);

int fscanf(FILE *f,const char *str,...);

int fclose(FILE *f);
int main(){
int k;
    fscanf(stdin,"%d",&k);
    //scanf("%d",&k);

    fprintf(stdout,"%d",k);
    //printf("%d",k)

    fprintf(stderr,"Can't allocate memory\n");

    fgets(char * str,100,stdin);
    //"abc\n" -> "abc\n\0" 
}

int getchar();
int fgetc(FILE *f);
int putchar(int c);
char * fgets(char *str,int n,FILE *F);
int puts(char * str);
int fputs(char *str,FILE *f);


//EOF - 文件结束符号
//stdin - 标准输入
//stdout - 标准输出
//stderr - 标准错误