#include<stdio.h>
#include<string.h>

struct color
{
    char name[20];
    int count;
};

int main()
{
    struct color white = {"WHITE",0};
    struct color black = {"BLACK",0};
    struct color other = {"OTHER",0};
    char buf[20];
    while(scanf("%19s",buf)!=EOF)
    {
        //printf("/hr1");
        if (!strcmp(white.name,buf))
            white.count++;
        else if (!strcmp(black.name,buf))
            black.count++;
        else 
            other.count++;
    }
    printf("%s %d\n",white.name,white.count);
    printf("%s %d\n",black.name,black.count);
    printf("%s %d\n",other.name,other.count);
    return 0;
}