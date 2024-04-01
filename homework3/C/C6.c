#include<stdio.h>

enum{N=10};

int find_max(int arr[],int n){
    int max =arr[0];
    int i;
    for(i=1;i<n;i++)
        if (arr[i]>max)
            max=arr[i];
    return max;
}

int sum_max(int (*ptr)[N],int n){
    int i,max,sum=0;
    for (i=0;i<n;i++){
        max = find_max(ptr[i],n);
        sum += max;
    }
    return sum;
}

int main(){
    int matr[N][N];
    int i,j,max,sum = 0;
    for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                scanf("%d",&matr[i][j]);
            }
    }
    sum = sum_max(matr,N);

    printf("%d\n",sum);
}