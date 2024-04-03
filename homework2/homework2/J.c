#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;
    int flag = 0;
    while((c=getchar())!='.')
    {
        if(flag<0)
        {
            break;
        }
        switch(c)
        {
        case('('):
            flag++;
            break;
        case(')'):
            flag--;
            break;
        default:
            break;
        }
    }

    if (flag==0)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }

    return 0;
}