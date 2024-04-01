#include<stdio.h>
#include<string.h>

#define MAX_STRING 20

struct color{
    char name[20];
    int count;
};

int main(){
    struct color col[MAX_STRING];
    char buf[20];
    int num_colors = 0,i;
    while(scanf("%19s",buf)!=EOF)
    {
        int exist = 0;
        for(i=0;i<num_colors;i++)
        {
            if(!strcmp(col[i].name,buf))
            {
                col[i].count++;
                exist = 1;
            }
        }
        if(!exist)
        {
            if(num_colors >= MAX_STRING)
            break;
            strcpy(col[num_colors].name,buf);
            col[num_colors].count = 1;
            num_colors++;
        }
    }
    for (i=0;i<num_colors;i++)
        {printf("%s %d\n",col[i].name,col[i].count);}
    return 0;
}