#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct msgbuf
{
    long mtype;
    int cnt;
};

int msg_ping_pong_2(key_t key){
    struct msgbuf message;
    int msgid =  msgget(key,IPC_CREAT | 0666);
    if(msgid<0){perror("msgget");return 1;}

    while(1){
        msgrcv(msgid,&message,sizeof(int),2,0);
        printf("process2 %d\n",message.cnt);
        fflush(stdout);
        if(message.cnt==-1){break;}
        message.cnt++;
        message.mtype = 1;
        msgsnd(msgid,&message,sizeof(int),0);
    }
    msgctl(msgid,IPC_RMID,NULL);
    return 0;
}