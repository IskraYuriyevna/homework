#include <stdio.h>
 int mas[10],a;
 
void mv1(int mas[10])
{
  int tmp=mas[0];
  for(int i=0;i<9;i++)
  mas[i]=mas[i+1];
  mas[9]=tmp;  
}

int main(void) {
  scanf("%d",&a);
  for(int i=0;i<10;i++)
  scanf("%d",&mas[i]);
  for(int j=0;j<a;j++){
      mv1(mas);
  }
  
  for(int i=0;i<10;i++)
  printf("%d ",mas[i]);
  return 0;
}