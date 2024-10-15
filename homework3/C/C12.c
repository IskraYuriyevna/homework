#include<stdio.h>
#include<string.h>
#include<math.h>

int main(int argc, char **argv)
{
	char *str[7] = {"sin","cos","tan","log","fabs","sqrt","exp"};
	
	double x;
	double a,b,h;
    int i;
	double (*m[7])(double) = {sin,cos,tan,log,fabs,sqrt,exp};

	if (argc < 5)
	{
		printf("-1");
		return 1;
	}
	for(i = 0; i< 7; i++)
	{
		if (!strcmp(argv[1], str[i]))
			break;
	}
	if (i == 7)
	{
		printf("-1");
		return 2;
	}
	if (sscanf(argv[2], "%lf", &a)!=1){
        printf("-1");
		return 3;
    }	
    if (sscanf(argv[3], "%lf", &b)!=1){
        printf("-1");
		return 3;
    }
    if (sscanf(argv[4], "%lf", &h)!=1){
        printf("-1");
		return 3;
    }
    if(h <= 0){
        printf("-1");
		return 3;
    }
    if((b-a)<h){
        printf("-1");
		return 3;
    }
    if(b<a){
        printf("-1");
		return 3;
    }

    for(x = a;x <= b;x += h){
        printf("%.3lf ", m[i](x));
    }

	
	return 0;
}