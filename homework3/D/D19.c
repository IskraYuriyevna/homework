#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
struct msgbuf{
    long mtype;
    int cnt;
};

int msg_ping_pong_2(key_t key){
    struct msgbuf message;
    int msgid,Cnt_Max;
    msgid = msgget(key,IPC_CREAT|0666);
    if(msgid<0){perror("msgget");return 1;}
    scanf("%d",&Cnt_Max);
    message.cnt=0;
    message.mtype=2;
    msgsnd(msgid,&message,sizeof(int),0);
    while(1){
        msgrcv(msgid,&message,sizeof(int),1,0);
        printf("process2 %d\n",message.cnt);fflush(stdout);
        if (message.cnt<Cnt_Max){
            message.cnt++;
            message.mtype=2;
            msgsnd(msgid,&message,sizeof(int),0);
        }else{
            message.cnt=-1;
            message.mtype=2;
            msgsnd(msgid,&message,sizeof(int),0);
            break;
        }
    }
    return 0;
}