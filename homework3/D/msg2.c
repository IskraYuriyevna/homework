#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct msgbuf
{
    long mtype;
    char data[256];
};

int main(){
    struct msgbuf message;

    key_t key=ftok("aaa.txt",8);
    if(key<0){perror("ftok");return 1;}

    int msgid = msgget(key,IPC_CREAT|0666);
    if(msgid<0){perror("msgget");return 1;}

    while(1){
        msgrcv(msgid,&message,256,1,0);
        if (strcmp(message.data,"Quit")==0){
            break;
        }else{
            printf("Process2 received: %s\n",message.data);
        }
    }
    return 0;
}