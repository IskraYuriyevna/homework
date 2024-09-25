#include <stdio.h>
double max(double *arr){
    double max = arr[0];
    for(int i=1;i<10;i++){
        if (arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}

double min(double *arr){
    double min = arr[0];
    for(int i=1;i<10;i++){
        if (arr[i]<min){
            min = arr[i];
        }
    }
    return min;
}

double sum_prod(double *arr){
    double sum = 0;
    for(int i=0;i<10;i+=2){
        sum += arr[i]*arr[i+1];
    }
    return sum;
}

double sum_abs(double *arr){
    double sum=0.0;
    for(int i=0;i<10;i++){
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
    for(int i=0;i<10;i++){
        scanf("%lf",&arr[i]);
    }
    scanf("%d",&sym);

    switch (sym){
    case (0):
        key = max(arr);
        break;

    case (1):
        key = min(arr);
        break;

    case (2):
        key = sum_abs(arr);
        break;

    case (3):
        key = max(arr)+min(arr);
        break;

    case (4):
        key = sum_prod(arr);
        break;

    default:
        key = -1;
        break;
    }

    printf("%g",key);

    return 0;
}