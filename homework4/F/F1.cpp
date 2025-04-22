#include <iostream>
using namespace std;
char c;
enum {H,N,P,S};
// 定义一个枚举类型，表示状态机的状态：
// H：初始状态，等待读取第一个有效数字。
// N：读取整数部分。
// P：遇到小数点后，准备读取小数部分的第一个数字。
// S：读取小数部分的后续数字。
     
void gc() // 从标准输入流中读取一个字符并且保存在c中
{
	c = cin.get();
}

double Parser()
{
	double num = 0. , dec = 0.1; // 初始化解析的数字num和用于计算小数部分的权重dec
	int CS = H; // 初始化状态机的当前状态为H
	gc();
	do{ // 状态机循环，直到解析或抛出异常
		switch(CS)
		{
			case H:
			{
				if(c == '0'|| c == '1') //如果是0或1进入N,否则抛出异常c
				{
					num = c - '0';
					gc();
					CS = N;
				}
				else throw c;
				break;
			}
			case N:
			{
				if(c=='0'||c=='1') //如果是0或1保存num*10+c,读取下一个字符，保持状态N
				{
					num = num*10+c -'0';
					gc();
					CS = N;
				}
				else if(c == '.') //如果是.读取下一个字符，进入P
				{
					gc();
					CS = P;
				}
				else throw c;
				break;
			}
			case P:
			{
				if(c=='0'||c=='1') //如果是0或1保存dec*c,状态为S
				{
					num += dec*(c-'0');
					gc();
					CS = S;
				}
				else throw c;
				break;
			}
			case S:
			{
				if(c=='0'||c=='1') //将小数位缩小十倍再读取
				{
					dec *= 0.1;
					num += dec*(c-'0');
					gc();
					CS = S;
				}
				else if(c=='\n') // 如果行结束返回解析的数
				{
					return num;
				}
				else throw c;
				break;
			}
			default:
				break;
		}
	}while(true);
}

int main()
{
	double num = 0.;
	try{
		num = Parser();
		cout << fixed << num << endl; //如果解析成功，输出解析结果（使用 fixed 格式化为固定小数位数，而非科学计数法scientific）
	}
	catch(char c)
	{
		cerr<< "Error in Lexeme: " << c << endl;
	}
	return 0;
}

// gc() 函数封装了 cin.get()，每次从输入流中读取一个字符（包括空白字符和换行符）。
// 它的主要作用是提供对输入流的逐字符控制，使得状态机可以逐字符地解析输入流中的内容。
