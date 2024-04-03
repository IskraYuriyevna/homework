#include <stdio.h>

unsigned long long MAX_WEIGHT = 1000000;

int main(void) {
    unsigned long long weight, total_weight, curr_weight = 1;
    unsigned m = 0;
    scanf("%llu", &weight);
    total_weight = weight;

    while (weight > 0) {
        if (weight % 3 != 0) {
            m += 1;
            if (weight % 3 == 2) {
                ++weight;
                total_weight += curr_weight;
            }
        }
        weight /= 3;
        curr_weight *= 3;
    }

    if (total_weight <= MAX_WEIGHT) {
        printf("%u\n", m);
    } else {
        printf("-1\n");
    }
    return 0;
}