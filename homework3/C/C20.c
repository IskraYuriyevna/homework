#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Inode{
    char str[20];
    struct Inode *prev;
    struct Inode *next;
};

struct Inode* add_first(struct Inode *cur,const char* str)
//在链表最前增加结点
{
    struct Inode *head = NULL;

    while(cur->prev){cur = cur->prev;}
    head = (struct Inode*)malloc(sizeof(struct Inode));
    if (head == NULL){return NULL;}
    strcpy(head->str,str);
    cur->prev = head;
    head->prev = NULL;
    head->next = cur;

    return head;
}

void  Print_list(struct Inode* cur)
//按照顺序打印链表的所有元素
{
    if (cur == NULL)
    {       
            printf("empty\n");
            return;
    }
    while(cur->prev){cur = cur->prev;}
    while(cur->next)
    {
        printf("%s\n",cur->str);
        cur = cur->next;
    }

    printf("%s\n",cur->str);
}

void Delete_tree(struct Inode *cur)
//删除整个链表并释放资源
{
    while(cur->next){cur = cur->next;}
    while(cur->prev)
    {
        struct Inode *tmp = cur->prev;
        free(cur);
        cur = tmp;
    }
}

int main(){
    struct Inode *head = NULL;
    char buf[20];

    if (scanf("%19s",buf)!=EOF)
    //输入第个结点并获取内存
    {
        head=(struct Inode*)malloc(sizeof(struct Inode));
        if (head == NULL){return 1;}
        strcpy(head->str,buf);
        head->prev = NULL;
        head->next = NULL;
    }

    while(scanf("%19s",buf)!=EOF)
    //继续输入剩下的结点
    {
        if(add_first(head,buf)==NULL){break;}
    }

    Print_list(head);

    if(head)
    {
        Delete_tree(head);
        //free(head);
        head = NULL;
    }

    return 0;
}