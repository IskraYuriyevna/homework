#include <stdio.h>

enum {Row=5,Col=5};

float average_diago(int (*A)[Col],int Row,int Col)
{
    int sum = 0;float aver;
    for(int i = 0;i < Row;i++)
    {
        for(int j = 0; j < Col;j++)
        {
            if(i==j)
            sum += A[i][j];
        }
    }
    aver = sum/Row;
    return aver;
}

int main(){
    float aver;
    int Matr[Row][Col] = {{0}};
    for(int i = 0;i<Row;i++){
        for(int j = 0;j < Col;j++){
            scanf("%d",Matr[i]+j);
        }
    }

    aver = average_diago(Matr,Row,Col);
    int cnt = 0;
    //printf("%f\n",aver);

    for(int i = 0;i<Row;i++){
        for(int j = 0;j < Col;j++){
            if (Matr[i][j]>aver){
                cnt++;
            }
        }
    }
    printf("%d",cnt);

    return 0;
}