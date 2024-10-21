#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
//链表节点
{   
    struct node * next;
    char str[20];
    struct node * prev;
};

int add_last(struct node *cur,const char* buf)
//增加新的节点
{
    struct node *new = NULL;

    while(cur->next){cur = cur->next;}
    new = (struct node*)malloc(sizeof(struct node));
    if(new == NULL){return 1;}
    strcpy(new->str,buf);
    cur->next = new;
    new->prev = cur;
    new->next = NULL;
    return 0;
}

void  Print_revers(struct node* cur)
{
    if (cur == NULL)
    {       
            printf("empty\n");
            return;
    }
    while(cur->next){cur = cur->next;}
    while(cur->prev)
    {
        printf("%s\n",cur->str);
        cur = cur->prev;
    }

    printf("%s\n",cur->str);
}

void Delete_tree(struct node *cur)
{
    while(cur->next){cur = cur->next;}
    while(cur->prev)
    {
        //cur = cur->prev;
        //free(cur->next);
        //上面两句和下面是一样的
        struct node *tmp = cur->prev;
        free(cur);
        cur = tmp;
    }
}

int main(){
    struct node *head = NULL;
    char buf[20];

    if (scanf("%19s",buf)!=EOF)
    //输入节点数值并获取内存
    {
        head=(struct node*)malloc(sizeof(struct node));
        if (head == NULL){return 1;}
        strcpy(head->str,buf);
        head->prev = NULL;
        head->next = NULL;
    }

    while(scanf("%19s",buf)!=EOF)
    //
    {
        if (add_last(head,buf)){break;}
    }
    Print_revers(head);
    if(head)
    {
        Delete_tree(head);
        free(head);
        head = NULL;
    }
    return 0;
}