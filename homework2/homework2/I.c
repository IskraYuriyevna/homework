#include <stdio.h>

int main() {
    int num;
    scanf("%d", &num);

    if (num >= 1 && num < 1000){
        printf("%d", num % 3 ? 1 : 2); 
    } else {
		num = num - 1000;
        printf("%d", num % 3 ? 2 : 1); 
    }
    return 0;
}
