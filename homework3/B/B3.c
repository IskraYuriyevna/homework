#include <stdio.h>

int main() {
    double x=0,y=0,x1=0,y1=0,x2=0,y2=0;
    scanf("%lf %lf %lf %lf %lf %lf",&x,&y,&x1,&y1,&x2,&y2);
    if (x == x1){
        if ((y==y2)&(y!=y1)) {printf("YES");}
        else {printf("NO");}
    }
    else if (x == x2){
        if ((y==y1)&(y!=y2)) {printf("YES");}
        else {printf("NO");}
    }
    else {printf("NO");}

    return 0;
}

