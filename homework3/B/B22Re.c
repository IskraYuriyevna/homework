#include<stdio.h>
void translate(char* str1,  char* str2){
    int flag = 0;
    int cur = 0;
    
    for (int i = 0; str1[i] != '\0'; i++){
        char c = str1[i];
        if(c == ' ') {
            continue;
        }

        flag = 0;

        for (int j = 0; j < cur; j++){
            if (str2[j] == c){
                flag = 1;  
                break;
            }
        }

        if (!flag) str2[cur++] = c;
    }

    str2[cur] = '\0';
}      


int main(){
    enum {SIZE = 1001};
    char str1[SIZE];
    char str2[SIZE];

    fgets(str1,SIZE,stdin);
    translate(str1, str2);

    printf("%s\n", str2);
    return 0;
}