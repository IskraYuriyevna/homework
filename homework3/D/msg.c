#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<unistd.h>
#include<string.h>

struct msgbuf
{
    long mtype;
    char data[256];
};

int main(){
    struct msgbuf message;
    char str[256];

    key_t key = ftok("aaa.txt",8);
    if(key<0){perror("ftok");return 1;}

    int msgid = msgget(key,IPC_CREAT | 0666);
    if(msgid<0){perror("msgget");return 1;}

    while(1){
        fgets(str,255,stdin);
        strcpy(message.data,str);
        switch(str[0]){
            case'a':
            case'A':
                message.mtype = 1;
                msgsnd(msgid,&message,strlen(str)+1,0);
                break;
            case 'b':
            case 'B':
                message.mtype = 2;
                msgsnd(msgid,&message,strlen(str)+1,0);
                break;
            case 'q':
            case 'Q':
                strcpy(message.data,"Quit");
                message.mtype = 1;
                msgsnd(msgid,&message,strlen(("Quit"))+1,0);
                message.mtype = 2;
                msgsnd(msgid,&message,strlen(("Quit"))+1,0);
                sleep(1);
                msgctl(msgid,IPC_RMID,0);//delete
                return 0;
        } 
    }
}