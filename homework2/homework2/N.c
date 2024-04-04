#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int Digital;
    scanf("%d", &Digital);
    char StrDigital[12]; 
    sprintf(StrDigital, "%d", Digital);
    int Quantity = 1024;
    char* queue = (char*)malloc(Quantity * sizeof(char));
    
	if (queue == NULL) {
        return 1; 
    }
    queue[0] = '\0'; 

    int num = 1;
    int len = 0; 
	
    while (1) {
        char Cache[20]; 
        sprintf(Cache, "%d", num);
        
        int CacheLen = strlen(Cache);
        while (len + CacheLen >= Quantity) { 
            Quantity *= 2;
            queue = (char*)realloc(queue, Quantity * sizeof(char));
            if (queue == NULL) {
                return 1; 
            }
        }
        
        strcat(queue, Cache); 
        len += CacheLen;
        
        char* found = strstr(queue, StrDigital); 
        if (found != NULL) {
            printf("%ld\n", (found - queue) + 1); 
            break;
        }
        
        num++;
    }
    
    free(queue);
    return 0;
}