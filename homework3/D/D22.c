#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<string.h>
#include<sys/wait.h>

struct msgbuf{
    long mtype;
    char data[256];
};



int main(){
    int n;
    struct msgbuf message;
    pid_t pid1,pid2,pid3;

    key_t key = ftok("aaa.txt",8);
    if(key<0){perror("ftok");return 1;}
    
    int msgid = msgget(key,IPC_CREAT | 0666);
    if(msgid<0){perror("msgget");return 1;}

    scanf("%d",&n);//Read before fork, so that all subsequent child processes will inherit this variable
    //printf("inputed\n");
    if(n==0){printf("%s","\0");return 0;}

    char *str = NULL;
    str = (char*)malloc((n+1)*sizeof(int));
    if(str==NULL){perror("malloc");return 1;}
    str[0]='\0';
    message.mtype = 1;
    strcpy(message.data, str);
    msgsnd(msgid,&message,1,0);

    pid1 = fork();
    if(pid1<0){perror("fork");return 1;}
    if(pid1==0){//son1

        while(1){
            msgrcv(msgid,&message,256,1,0);
            strcpy(str,message.data);
            //printf("DATA1: %ld\n",strlen(message.data));
            //printf("STR1: %ld\n",strlen(str));
            //printf("%s\n",message.data);

            message.data[strlen(str)]='a'+(strlen(str)/3%26);
            message.data[strlen(str)+1]='\0';
            //printf("%s\n",message.data);
            //printf("STRR1: %ld\n",strlen(message.data));
            //sleep(1);
            message.mtype = 2;
            msgsnd(msgid,&message,strlen(message.data)+1,0);

            if(strlen(message.data)>=n){
                break;
            }
        }
        message.mtype = 4;
        msgsnd(msgid,&message,strlen(message.data)+1,0);
        //printf("son1 terminated\n");
        free(str);
    }else{
        pid2 = fork();
        if(pid2<0){perror("fork");return 1;}
        if(pid2==0){//son2

            while(1){
                msgrcv(msgid,&message,256,2,0);
                strcpy(str,message.data);
                //printf("DATA2: %ld\n",strlen(message.data));
                //printf("STR2: %ld\n",strlen(str));
                //printf("%s\n",message.data);

                message.data[strlen(str)]='0'+(strlen(str)/3%10);
                message.data[strlen(str)+1]='\0';
                //printf("%s\n",message.data);
                //sleep(1);
                message.mtype = 3;
                msgsnd(msgid,&message,strlen(message.data)+1,0);

                if(strlen(message.data)>=n){
                    break;
                }
            }
            message.mtype = 4;
            msgsnd(msgid,&message,strlen(message.data)+1,0);
            //printf("son2 terminated\n");
            free(str);
        }else{
            pid3 = fork();
            if(pid3<0){perror("fork");return 1;}
            if(pid3==0){//son3

                while(1){
                    msgrcv(msgid,&message,256,3,0);
                    strcpy(str,message.data);
                    //printf("%s\n",message.data);

                    //printf("DATA3: %ld\n",strlen(message.data));
                    //printf("STR3: %ld\n",strlen(str));
                    message.data[strlen(str)]='A'+(strlen(str)/3%26);
                    message.data[strlen(str)+1]='\0';
                    //printf("%s\n",message.data);
                    //sleep(1);
                    message.mtype = 1;
                    msgsnd(msgid,&message,strlen(message.data)+1,0);

                    if(strlen(message.data)>=n){
                        break;
                    }
                }
                message.mtype = 4;
                msgsnd(msgid,&message,strlen(message.data)+1,0);
                //printf("son3 terminated\n");
                free(str);
            }else{//father
            
                //printf("DATA: %ld\n",strlen(message.data));
                //printf("STR: %ld\n",strlen(str));
                while(1){
                    msgrcv(msgid,&message,256,4,0);
                    if(strlen(message.data)>=n){break;}
                }

                printf("%s\n",message.data);

                msgctl(msgid,IPC_RMID,0);
                wait(NULL);wait(NULL);wait(NULL);
                //printf("father terminated\n");
                free(str);str=NULL;
                return 0;
            }
        }
    }
}