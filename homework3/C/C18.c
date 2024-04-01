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
    while(cur->next != NULL)
        cur = cur->next;//找到最后一个元素
    while(cur->prev != NULL)
    {
        printf("%s\n",cur->str);
        cur = cur->prev;
    }
    printf("%s\n",cur->str);
}

struct node* Delect_node(struct node *cur,const char* buf){
    struct node *head = cur;
    if(strcmp(cur->str,buf)==0){//删除首个节点
        struct node *tmp = cur;
        if(cur->next==NULL){
            free(cur);
            return NULL;
        }
        cur = cur->next;
        free(tmp);
        cur->prev = NULL;
        return cur;
    }
    while(cur->next != NULL){//删除中间任意节点
        if (strcmp(cur->str,buf) == 0){
            struct node *tmp = cur;
            cur ->next ->prev = cur -> prev;
            cur ->prev ->next = cur -> next;
            free(tmp);
            return head;
        }
        cur = cur->next;
    }
    if (strcmp(cur->str,buf)==0){//
            cur->prev->next = NULL;
            free(cur);
            return head;
    }
    return head;
}

struct node* Delete_list(struct node* head){
    struct node *tmp = head;
    while(head->next != NULL)
    {
        head = head->next;
        free(tmp);
        tmp = head;
    }
    return head;
}

void Print_forward(struct node *cur){
    if (cur==NULL){
        printf("empty");
        return ;
    }
    while(cur->next != NULL){
        printf("%s ",cur->str);
        cur = cur->next;
    }
    printf("%s\n",cur->str);
}

int main(){
    struct node *head = NULL;
    char buf[20];
    char word[20];
    scanf("%19s",word);

    if(scanf("%19s",buf) != EOF)
    {
        head = (struct node*)malloc(sizeof(struct node));
        if (head == NULL)
            return 1;
        strcpy(head->str,buf);//将buf输入str
        head->next = NULL;//没有下一个元素了
        head->prev = NULL;//没有前面的元素
    }
    while(scanf("%19s",buf)!=EOF){    
        if(add_last(head,buf))
            break;
    }
    if(head != NULL){
        head = Delect_node(head,word);
    }
    Print_forward(head);
    
    if (head != NULL){
        head = Delete_list(head);
        free(head);
    }
    return 0;
}