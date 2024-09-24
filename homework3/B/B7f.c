#include<stdio.h>

int main(){
    int i,j,k,l,m;
    scanf("%d %d %d",&k,&l,&m);

    for(i=k-1;i<l;i++){
        if (i==(k-1)){printf("%*s ",m," ");}
        else {printf("%*d ",m,i);}
        for(j=k;j<l-1;j++){
            if (i==(k-1)){printf("%*d ",m,j);}
            else {printf("%*d ",m,i*j);}
        }
        if (i!=(k-1)){printf("%*d\n",m,i*(l-1));}
        else {printf("%*d\n",m,l-1);}
    }

    return 0;
}