#include<stdio.h>
void print_bit(char* str1,  char* str2)
{
enum {SIZE = 1001};
     int a = 0;
     int b = 0;
     fgets(str1,SIZE,stdin);
     for (int i = 0; str1[i] != '\0'; i++){
          char c = str1[i];
          if(c == ' ') continue;
          a = 0;
          for (int j = 0; j < b; j++){
              if (str2[j] == c){
                 a = 1;  
                 break;
              }
          }
          if (!a) str2[b++] = c;
      }
      str2[b] = '\0';
}      

enum {SIZE = 1001};
int main(){
    char str1[SIZE];
    char str2[SIZE];
    print_bit(str1, str2);
    printf("%s\n", str2);
    return 0;
}