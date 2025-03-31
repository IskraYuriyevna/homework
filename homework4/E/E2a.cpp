#include <iostream>
#include <cstring>

using namespace std;
char * left(char * str,int N){
	static char re[101];
	if(N<=0) return re;
	int len=0;
	while(str[len]!='\0') len++;
	if(N>=len) return str;
	int i = 0;
	for(i=0;i<N;i++) re[i] = str[i]; re[i]='\0';
	return re;
}
unsigned long left(unsigned long num,int N){
	static char strNum[101];
	int len = 0;
	unsigned long num1 = num;
	if(N<=0) return 0;
	while(num1>0){
		strNum[len++] = '0'+ (num1%10);
		num1/=10;
	}	
	if(N>=len) return num;
	for(int i = 0;i<len/2;i++) swap(strNum[i],strNum[len-i-1]);
	int i = 0;
	unsigned long re = 0;
	while(i<N) re = re*10 + (strNum[i++]-'0');
	return re;
	
}
int main(){
	char str[101];
	int N;
	unsigned long num = 0;
	cin.getline(str,100);
	if(strcmp(str,"string")==0){
		cin.getline(str,100);
		cin >> N;
		cout << left(str,N) << endl;
	}
	if(strcmp(str,"number")==0){
		cin >> num;
		cin >> N;
		cout << left(num,N) << endl;
	}
	return 0;
}
