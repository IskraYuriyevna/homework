#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct msgbuf
{
    long mtype;
    int cnt;
};

int msg_ping_pong_1(key_t key){
    struct msgbuf message;
    int Cnt_Max;
    int msgid = msgget(key,IPC_CREAT|0666);
    if(msgid<0){perror("msgget");return 1;}

    scanf("%d",&Cnt_Max);

    message.mtype=2;
    message.cnt=0;
    msgsnd(msgid,&message,sizeof(int),0);

    while(1){
        msgrcv(msgid,&message,sizeof(int),1,0);
        printf("process1 %d\n",message.cnt);
        fflush(stdout);
        if(message.cnt<Cnt_Max){
            message.cnt++;
            message.mtype = 2;
            msgsnd(msgid,&message,sizeof(int),0);
        }else{
            message.cnt = -1;
            message.mtype = 2;
            msgsnd(msgid,&message,sizeof(int),0);
            break;
        }
    }
    return 0;
}

// int main(){
//     struct msgbuf message;

//     key_t key=ftok("aaa.txt",8);
//     if(key<0){perror("ftok");return 1;}

//     if(msg_ping_pong_1(key)==1){
//         return 1;
//     }
//     return 0;
// }