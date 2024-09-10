#include<stdio.h>
#include<stdlib.h>

int main(){	
	int flag=0,i=0,j=0;char* m=(char*)malloc(100*sizeof(char)),n[100]={0};
    //gets(m);
    //gets(n);
    scanf("%s\n%s",m,n);
    for(i=0;m[i]!='\0';i++){
        if(m[i]!='='){flag=1;break;}
    }
	//printf("hr1");
    for(j=0;n[j]!='\0';j++){
        if(n[j]!='='){flag=1;break;}
    }
    //printf("%s\n%s",m,n);
	//printf("%d",flag);
	if(flag==0){
		if(i>j){
			printf("First");
		}else if(i<j){
			printf("Second");
		}else{
			printf("Equal");
        }
    }else{
		printf("Incorrect");
	}
    return 0;
}