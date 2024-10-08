#include <stdio.h>
enum {Row=10,Col=10};

int Sum_Max(int (*A)[Col],int Row,int Col)
{
    int sum = 0;
    for(int i = 0;i < Row;i++)
    {
        int jmax = 0;
        for(int j = 1; j < Col;j++)
        {
            if(A[i][j]>A[i][jmax])
            jmax = j;
        }
        sum += A[i][jmax];
    }
return sum;
}

int main(){
    int Matr[Row][Col] = {{0}};
    for(int i = 0;i<Row;i++){
        for(int j = 0;j < Col;j++){
            scanf("%d",Matr[i]+j);
            
        }
    }
    printf("%d\n",Sum_Max(Matr,Row,Col));
    return 0;
}