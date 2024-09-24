#include <stdio.h>

void Swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubble_sort(int* Arr,int len){
    for (int i = 0;i<len-1;i++){
        for (int j = 0;j<len-i-1;j++){
            if(Arr[j]%10>Arr[j+1]%10){
                Swap(Arr + j,Arr+j+1);
            }
        }
    }
}

int main(){
    enum {SIZE = 10};
    int arr[SIZE];

    for(int i = 0;i<SIZE;i++){
        scanf("%d",arr+i);
    }

    bubble_sort(arr,SIZE);

    for (int i = 0; i< SIZE;i++){
        printf("%d ",arr[i]);
    }
    
    printf("\n");
    
    return 0;
}