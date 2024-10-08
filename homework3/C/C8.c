#include<stdio.h>
#include<stdlib.h>

int Sum_Max(int **A,int Row,int Col){
    int sum = 0;
    for(int i = 0;i < Row;i++){
        int jmax = 0;
        for(int j = 1;j < Col;j++){
            if (A[i][j] > A[i][jmax]){
                jmax = j;
            }
        }
        sum += A[i][jmax];
    }
    return sum;
}

int main(){
    int **Matr = NULL;
    int Row,Col;

    scanf("%d %d",&Row,&Col);

    Matr = (int**)malloc(Row*sizeof(int*));
    if (Matr == NULL)
    {
        printf("Can't allocate memory\n");
        return 1;
    }
    for(int i = 0;i < Row;i++)
    {
        Matr[i] = (int*)malloc(Col*sizeof(int));
        if (Matr[i] == NULL){
            printf("Can't allocate memory\n");
            for(int j = 0;j < i ;j++){
                free(Matr[j]);
            }
            free(Matr);
            return 1;
        }
    }
    for(int i;i < Row;i++){
        for(int j = 0;j < Col;j++){
            scanf("%d",Matr[i]+j);//&Matr[i][j]
        }
    }
    printf("%d",Sum_Max(Matr,Row,Col));

    for(int i = 0;i < Row;i++){
        free(Matr[i]);
    }
    free(Matr);
    Matr = NULL;
    return 0;
}