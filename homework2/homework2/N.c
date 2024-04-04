#include <stdio.h>
#include <string.h>

int main() {
    int n,strp;
    scanf("%d", &n);
    char num[20];
    sprintf(num, "%d", n);

    for (int i = 1; i <= 10000; i++) {
        char current[20];
        sprintf(current, "%d", i);
        if (strstr(current, num) != NULL) {
            strp= strlen(current) - strlen(num) + 1;
        }
    }

    printf("%d",strp);
    return 0;
}