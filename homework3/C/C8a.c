#include<stdio.h>
#include<stdlib.h>

int find_max(int *arr,int n){
    int i,max =arr[0];
    for(i=1;i<n;i++)
        if(arr[i]>max)
            max = arr[i];
    return max;
}

int sum_max(int **matr,int N,int M){
    int i,max,sum =0;
    for(i=0;i<N;i++){
        max = find_max(matr[i],M);
        sum += max;
    }
    return sum;
}

int main(){
    int i,j,sum,row,col;
    int **matr;
    scanf("%d %d",&row,&col);
    matr = (int**)malloc(row*sizeof(int*));
    if (matr == NULL){
        printf("Error:Can't allocate memory\n");
        return 1;
    }
    for(i=0;i<row;i++){
        matr[i] = (int*)malloc(col*sizeof(int));
        if(matr[i] == NULL)
        {
            printf("Error:Can't allocate memory\n");
            return 2;
        }
    }
    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
            scanf("%d",&matr[i][j]);
    sum = sum_max(matr,row,col);   
    printf("%d",sum);     

    for(i=0;i<row;i++)
        free(matr[i]);
    free(matr);
    return 0;
}