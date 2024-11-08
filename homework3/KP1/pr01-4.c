#include <stdio.h>
#include<string.h>
#include <sys/types.h>
#include<stdlib.h>

struct Node{
    struct Node *prev,*next;
    char *elem;
};

struct List
{
    struct Node *first, *last;
};

void process(struct List *pl, const char *str);

int main(){
    return 0;
}

void process(struct List *pl,const char *str){
    struct Node *cur = pl->first;
    while(cur->next){
        if(strcmp(cur->elem,str)>0){
            cur=cur->next;
            continue;
        }else if(strcmp(cur->elem,str)==0){
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            free(cur);
            return ;
        }else{
            cur = cur->next;
            continue;
        }
    }
}