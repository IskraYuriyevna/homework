#include <stdio.h>
#include <stdlib.h>

int Mul_mat(int Mat1,int Mat2){
    

    return 0;
}

void freemat(int **Mat,int Row){
    for(int i = 0;i < Row;i++){
        free(Mat[i]);
    }
    free(Mat);
    Mat = NULL;
}

int main(){
    int **Mat1 = NULL;
    int **Mat2 = NULL;
    int n,m,k,l;

    //input first matrix
    scanf("%d %d",&n,&m);
    Mat1 = (int**)malloc(n*sizeof(int*));
    if (Mat1 == NULL)
    {
        printf("-1\n");
        return -1;
    }
    for(int i = 0;i < n;i++)
    {
        Mat1[i] = (int*)malloc(m*sizeof(int));
        if (Mat1[i] == NULL){
            printf("-1\n");
            freemat(Mat1,i);
            return -1;
        }
    }
    for(int i;i < n;i++){
        for(int j = 0;j < m;j++){
            scanf("%d",Mat1[i]+j);
        }
    }

    //input second matrix
    scanf("%d %d",&k,&l);
    Mat2 = (int**)malloc(k*sizeof(int*));
    if (Mat2 == NULL)
    {
        printf("-1\n");
        return -1;
    }
    for(int i = 0;i < k;i++)
    {
        Mat2[i] = (int*)malloc(l*sizeof(int));
        if (Mat2[i] == NULL){
            printf("-1\n");
            freemat(Mat2,i);
            return -1;
        }
    }
    for(int i;i < k;i++){
        for(int j = 0;j < l;j++){
            scanf("%d",Mat2[i]+j);
        }
    }

    //Compute matrix multiplication
    if(m!=k){
        return -1;
    }else{
        Mul_mat(Mat1,Mat2);
    }

    freemat(Mat1,n);
    freemat(Mat2,k);
    return 0;
}