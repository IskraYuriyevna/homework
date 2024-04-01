#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
    pid_t pid;//pid_t typdef
    int n = 9;
    fork();fork();
    pid = getpid();
    printf("n = %d\n,PID = %d",n,pid);
    return 0;
}