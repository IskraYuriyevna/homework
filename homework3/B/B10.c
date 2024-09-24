# include <stdio.h>

int main(){
    int cnt=0,zsf=0,bf=0,sf=0,c;
    // zsf for "Zero Start Flag",bf for "Bad Flag",sf for "Symbol Flag"

    while((c=getchar())!='\n'){
        if((sf==1)&&(c=='-')){
            bf = 1;
            break;

        }else if(zsf==1){
            bf = 1;
            break;

        }else if ((c=='-')&&(cnt==0)){
            sf = 1;
            continue;

        }else if((c=='0')&&(cnt==0)){
            zsf = 1;
            continue;
            
        }else if ((c>='0')&&(c<='9')){
            cnt++;
            continue;
            
        }else{
            bf = 1;
            break;
            
        }

    }
    
    if (bf==1){
        printf("NO");

    }else if ((zsf==1)&&(sf==1)){
        printf("NO");

    }else if ((zsf==1)&&(cnt==0)){
        printf("YES");

    }else if (cnt==0){
        printf("NO");

    }else{
        printf("YES");

    }
   
    return 0;
}   

        

