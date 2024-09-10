#include<stdio.h>
int main(){
	int n=0,nsq=0,ncb=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		nsq = i*i;
		ncb = i*i*i;
		printf("%4d %4d %4d\n",i,nsq,ncb);
	}

	return 0;
}