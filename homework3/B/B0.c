#include <stdio.h>

int main() {
	long i=0,j=0,k=0;
	long a[10] = {0,};
	for(i=0;i<10;i++){
		scanf("%ld",&a[i]);
	}
	scanf("%ld",&j);
	switch (j){
		case(1):
			for (i=0;i<10;i++){
				k = k+a[i];
			}
			break;
		case(2):
			k=a[0];
			for (i=0;i<10;i++){
				if (k>=a[i]){k=a[i];}					}
			break;
		case(3):
			k = a[0];
			for (i=0;i<10;i++){
				if (a[i]<0){a[i]=-a[i];}
				if (k<=a[i]){k=a[i];}
			}
			break;
		}
	printf("%ld",k);
	
	return 0;
}
