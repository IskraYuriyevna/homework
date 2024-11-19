#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
struct msgbuf{
    long mtype;
    int cnt;
};

int msg_ping_pong_1(key_t key){
    struct msgbuf message;
    int msgid;
    msgid=msgget(key,IPC_CREAT|0666);
    if(msgid<0){perror("msgget");return 1;}
    while(1){
        msgrcv(msgid,&message,sizeof(int),2,0);
        printf("process1 %d\n", message.cnt);
        fflush(stdout);
        if(message.cnt==-1)
            break;
        message.cnt++;
        message.mtype=1;
        msgsnd(msgid,&message,sizeof(int),0);
    }
    msgctl(msgid,IPC_RMID,0);
    return 0;
}