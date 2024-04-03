#include <stdio.h>
#include <stdint.h>

struct pack_array {
    uint32_t array;
    uint32_t count0 : 8; 
    uint32_t count1 : 8; 
};

void array2struct(int arr[], struct pack_array *p) {
    p->array = 0;
    p->count0 = 0;
    p->count1 = 0;

    for (int i = 0; i < 32; ++i) {
        p->array |= (uint32_t)arr[i] << (31 - i);
        if (arr[i] == 1) {
            p->count1++;
        } else {
            p->count0++;
        }
    }
}

int main() {
    struct pack_array packed;
    int data[32];
   // printf("Входной массив\n");
    for (int i = 0; i < 32; ++i) {
        if (scanf("%d", &data[i]) != 1) {
            return 1;
        }
    }

    array2struct(data, &packed);
  //  printf("Поля структуры\n");
    printf("array = %08x\n", packed.array);
    printf("count0 = %d\n", packed.count0);
    printf("count1 = %d\n", packed.count1);
    return 0;
}

第二段
void array2struct(int arr[], struct pack_array *p) {
    p->array = 0;
    p->count0 = 0;
    p->count1 = 0;
    for (int i = 0; i < 32; ++i) {
        p->array |= (uint32_t)arr[i] << (31 - i);
        if (arr[i] == 1) {
            p->count1++;
        } else {
            p->count0++;
        }
    }
}