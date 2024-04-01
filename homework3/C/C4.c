#include <stdio.h>
#include <stdlib.h>

int main(){
    int i=0,cnt=0,n=0;char s;
    int* a = (int*)malloc(10*sizeof(int));
    int* n = (int*)malloc(10*sizeof(int));
    if (arr == NULL){
        printf("Error:can't allocate memory\n");

        return 1;
    }

    while(1){
        scanf("%d",&a[n]);
        n++;
        if(s=getchar()=='\0'){break;}
        cnt++;
        if (cnt==10){
            a = (int*)realloc(a,10*sizeof(int));
            cnt = 0;
        }
    }

    free();
    free();
    return 0;
}