#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    //Define node
    struct node *prev;
    char str[20];
    struct node *next;
};

int insert_element(struct node *head, const char *find_str, const char *insert_str)
    //insert element *insert_str after find_str
{
    struct node *cur = head,*insert=NULL;

    if (cur == NULL){
        //if the list is emptyhead
        //printf("empty\n");
        return 1;
    }
    while (cur != NULL){
        if(strcmp(cur->str,find_str)==0){
                insert = (struct node*)malloc(sizeof(struct node));
                if(insert == NULL){return 1;}
                strcpy(insert->str,insert_str);
                if (cur->next){
                    //if add in the middle
                    cur->next->prev = insert;
                    insert->next = cur->next;
                    cur->next = insert;
                    insert->prev = cur;
                }else{
                    //if add at the and
                    cur->next = insert;
                    insert->prev = cur;
                    insert->next = NULL;
                }
                return 0;
        }else{
            cur = cur->next;
        }
    }
    // if none of strings match
    return 1;
}

int add_last(struct node *cur,const char* buf){
    //add new node after the last element of list
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

void Print_forward(struct node *cur)
    //Print list form the first element to the last
{
    if(cur == NULL)
    {
        //printf("empty\n");
        return;
    }
    while(cur)
    {
        printf("%s ",cur->str);
        cur = cur->next;
    }
}

void Delete_tree(struct node *cur)
    //Delete the entire list and free up resources
{
    while(cur->next){cur = cur->next;}
    while(cur->prev)
    {
        struct node *tmp = cur->prev;
        free(cur);
        cur = tmp;
    }
}

int main(int argc,char *argv[]){
    struct node *head = NULL;
    char find_str[20];
    char insert_str[20];
    char buf[20];

    // Processing special cases of CLI input
    if (argc<3)
    {
        printf("-1");
        return -1;
    }
    if (sscanf(argv[1],"%19s",find_str)!=1)
    {
        printf("-1");
        return -1;
    }
    if (sscanf(argv[2],"%19s",insert_str)!=1)
    {
        printf("-1");
        return -1;
    }

    //Input first node from stdin
    if(scanf("%19s",buf)!=EOF)
    {
        head = (struct node*)malloc(sizeof(struct node));
        if (head == NULL){return 1;}
        strcpy(head->str,buf);
        head->next = NULL;
        head->next = NULL;
    }

    //Input following node from stdin
    while(scanf("%19s",buf)!=EOF)
    {
        if(add_last(head,buf)){break;}
    }

    //insert and print
    insert_element(head,find_str,insert_str);
    Print_forward(head);

    //free up resources
    if(head)
    {
        Delete_tree(head);
        free(head);
        head = NULL;
    }

    return 0;
}
