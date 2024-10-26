#include <stdio.h>
#include <string.h>
#define MAX_STRINGS 30

struct color
{
    char name[20];//color name
    int count;//how much times this color showed
};

int add_element (struct color *clm,const char *buf,int *ptr_num_colors);

int main(){
    struct color Color[MAX_STRINGS];
    char buf[20];
    int num_colors = 0;

    while(scanf("%19s",buf)!=EOF){
        int exist = 0;
        for(int i = 0;i < num_colors;i++){
            if(strcmp(Color[i].name,buf) == 0){
                Color[i].count++;
                exist = 1;
            }
        }
        if(!exist){
            if (add_element(&Color[num_colors],buf,&num_colors))
                break;
        }
    }
    for (int i = 0;i<num_colors;i++)
        printf("%s %d\n",Color[i].name, Color[i].count);

    return 0;
}

int add_element (struct color *clm,const char *buf,int *ptr_num_colors)
{
    if (*ptr_num_colors >= MAX_STRINGS)
        return 1;
    strcpy(clm->name,buf);
    clm->count = 1;
    (*ptr_num_colors)++;
    return 0;
}