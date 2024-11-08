#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int open(const char *file,int flags);
int open(const char *file,int flags,mode_t);//仅在flags为O_CREAT时使用
// flags: 
// O_RDONLY
// O_WRONLY
// O_RDWR
// O_CREAT
// O_TRUNC
// O_APPEND
// O_EXCL

typedef struct { // 使用typedef定义一个新的类型别名
    int cnt; // 成员变量cnt，通常用来记录缓冲区中剩余的字符数
    char *ptr; // 成员变量ptr，指向缓冲区中当前要读取或写入的字符
    char *base; // 成员变量base，指向缓冲区的起始地址
    int flags; // 成员变量flags，用来存储文件的状态标志，比如是否打开成功、读写模式等
    int fd; // 成员变量fd，文件描述符，用于系统调用中标识文件
} FILE; // 
