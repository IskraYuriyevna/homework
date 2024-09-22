#include <stdio.h>

int main(){
    int yy,mm,dd;unsigned int maskd = 65535<<5,maskm = 65535<<9;unsigned short date;
    scanf("%hu",&date);
    yy = (date&maskm)>>9;
    mm = ((date&maskd)-(date&maskm))>>5;
    dd = date - (date&maskd);
    
    if (yy>=50){
        yy+=1900;
    }else{
        yy+=2000;
    }

    printf("%d %d %d",yy,mm,dd);
}