#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct node{
    char str[20];
    struct node *next;
    struct node *prev;
};

int add_last(struct node* cur,const char *buf)
{
    struct node *new;
    while(cur->next)    //找到最后一个元素
        cur = cur->next;
    new = (struct node*)malloc(sizeof(struct node));//给新元素分配内存
    if(new == NULL) return 1;//内存分配检查
    strcpy(new->str,buf);//将buf存入新节点
    new->prev = cur;
    cur->next = new;
    new->next = NULL;
    return 0;
}

void Print_list(struct node *cur)
{
    while(cur->next)
        cur = cur->next;//找到最后一个元素
    while(cur->prev)
    {
        printf("%s\n",cur->str);
        cur = cur->prev;
    }
    printf("%s\n",cur->str);
}


int main(){
    struct node *head = NULL;
    char buf[20];

    if(scanf("%19s",buf) != EOF)
    {
        head = (struct node*)malloc(sizeof(struct node));
        if (head == NULL)
            return 1;
        strcpy(head->str,buf);//将buf输入str
        head->next = NULL;//没有下一个元素了
        head->prev = NULL;//没有前面的元素
    }
    while(scanf("%19s",buf)!=EOF)
    {
        if(add_last(head,buf))
            break;
    }
    
    Print_list(head);

    free(head);
    return 0;
}