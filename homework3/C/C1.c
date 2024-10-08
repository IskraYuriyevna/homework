#include<stdio.h>
#include<stdlib.h>

int main(){
    int i,n,num=0;
    if(scanf("%d",&n) != 1){
        return 1;
    }
    int* a = (int*)malloc(n*sizeof(int));
    if (a == NULL){
        printf("Error:can't allocate memory\n");
        return 1;
    }
    
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    int max = a[0],min = a[0];
    for(i=0;i<n;i++){
        if (a[i]>max){
            max = a[i];
        }else if(a[i]<min){
            min = a[i];
        }
    }
    num = ((n+1)*(min+max))/2;
    for(i=0;i<n;i++){
        num -= a[i];
    }

    printf("%d",num);
    
    free(a);
    return 0;
}