
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