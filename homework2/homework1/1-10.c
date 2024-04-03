#include <stdio.h>
#include <string.h>

struct pack_array {
    uint32_t array; // поле для хранения упакованного массива из 0 и 1
    uint32_t count0 : 8; // счетчик нулей в array
    uint32_t count1 : 8; // счетчик единиц в array
}packs;

void array2struct(int arr[], struct pack_array *packs){
    packs->count0 = 0;packs->count1 = 0;
    int i,l=32;

    const char hex_table[] =
    {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    
    while(l--){
        *(&(packs->array)+2*l+1) = hex_table[(*(arr+1))&0x0f];
        *(&(packs->array)+2*l) = hex_table[(*(arr+1)>>4)];
    }
    //(int)packs->array;
    
    for(i=0;i<32;i++){
        if (arr[i]==0){
            packs->count0++;
        }else{
            packs->count1++;
        }
    }      
    
}