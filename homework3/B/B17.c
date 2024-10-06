#include <stdio.h>
double max(double *arr,int SIZE){
    double max = arr[0];
    for(int i=1;i<SIZE;i++){
        if (arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}

double min(double *arr,int SIZE){
    double min = arr[0];
    for(int i=1;i<SIZE;i++){
        if (arr[i]<min){
            min = arr[i];
        }
    }
    return min;
}

double sum_prod(double *arr,int SIZE){
    double sum = 0;
    for(int i=0;i<SIZE;i+=2){
        sum += arr[i]*arr[i+1];
    }
    return sum;
}

double sum_abs(double *arr,int SIZE){
    double sum=0.0;
    for(int i=0;i<SIZE;i++){
        if(arr[i]>=0){
            sum += arr[i];
        }else{
            sum -= arr[i];
        }
    }
    return sum;
}

int main(){
    enum {SIZE = 10};
    double arr[SIZE],key;int sym;
    for(int i=0;i<SIZE;i++){
        scanf("%lf",&arr[i]);
    }
    scanf("%d",&sym);

    switch (sym){
    case (0):
        key = max(arr,SIZE);
        break;

    case (1):
        key = min(arr,SIZE);
        break;

    case (2):
        key = sum_abs(arr,SIZE);
        break;

    case (3):
        key = max(arr,SIZE)+min(arr,SIZE);
        break;

    case (4):
        key = sum_prod(arr,SIZE);
        break;

    default:
        key = -1;
        break;
    }

    printf("%g",key);

    return 0;
}