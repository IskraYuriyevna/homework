#include<stdio.h>
int main(){
	int n=0,nsq=0,ncb=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		nsq = i*i;
		ncb = i*i*i;
		printf("%5d %5d %5d\n",i,nsq,ncb);
	}

	return 0;
}