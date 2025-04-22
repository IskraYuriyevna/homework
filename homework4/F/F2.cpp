#include <iostream>
#include <string>
using namespace std;
char c;
enum {H,A,B,S};
string str;
     
void gc() 
{
	c = cin.get();
}

string Parser()
{
	
	int CS = H; 
	gc();
	do{ 
		switch(CS)
		{
			case H:
			{
				if(c == 'a') 
				{
                    str += c;
					gc();
					CS = A;
				}
				else throw c;
				break;
			}
			case A:
			{
				if(c=='d') 
				{
                    str += c;
					gc();
					CS = A;
				}
				else if(c == 'a') 
				{
                    str += c;
					gc();
					CS = B;
				}
				else throw c;
				break;
			}
			case B:
			{
				if(c=='a') 
				{
                    str += c;
					gc();
					CS = A;
				}
                else if(c =='\n')
                {
                    return str;
                    // str += c;
                    // gc();
                    // CS = S;
                }
				else throw c;
				break;
			}
			// case S:
			// {
			// 	if(c=='\n') 
			// 	{
			// 		return str;
			// 	}
			// 	else throw c;
			// 	break;
			// }
			default:
				break;
		}
	}while(true);
}

int main()
{
	try{
		string stro = Parser();
		cout << stro << endl; 
	}
	catch(char c)
	{
		cerr<< "Error in Lexeme: " << c << endl;
	}
	return 0;
}

