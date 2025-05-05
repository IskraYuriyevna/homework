#include<iostream>
using namespace std;

char c;
enum{H,I,I1,I2,I3,J,J1,J2,K,K1,L,M,M1,M2,M3,N,N1,N2,O,O1,P,S1,S2,S3,S4,S5,S6,S7,S8,S9,S0};
int flag = 0;

void gc() 
{
	c = cin.get();
}

int Parser()
{
	int CS = H; 
	gc();
	do{ 
		switch(CS)
		{
			case H:
			{
				if(c == '.') 
				{  
					gc();
					CS = I;
				}else if(c == '-')
                {
                    gc();
                    CS = M;
                }
				else throw c;
				break;
			}
            case I:
			{
				if(c == '.') 
				{
					gc();
					CS = J;
				}else if(c == '-')
                {
                    gc();
                    CS = I1;
                }
				else throw c;
				break;
			}
            case I1:
			{
				if(c == '-') 
				{ 
					gc();
					CS = I2;
				}else throw c;
				break;
			}
            case I2:
			{
				if(c == '-') 
				{
					gc();
					CS = I3;
				}else throw c;
				break;
			}
            case I3:
			{
				if(c == '-') 
				{
					gc();
					CS = S1;
				}else throw c;
				break;
			}
            case S1:
			{
				if(c ==' ') 
				{
                    return 1;
				}else if(c == '\n')
                {
                    return 1;
                    flag = 1;
                }else throw c;
				break;
			}
            case J:
			{
				if(c == '.') 
				{
					gc();
					CS = K;
				}else if(c == '-')
                {
                    gc();
                    CS = J1;
                }
				else throw c;
				break;
			}
            case J1:
			{
				if(c == '-') 
				{    
					gc();
					CS = J2;
				}else throw c;
				break;
			}
            case J2:
			{
				if(c == '-') 
				{
    				gc();
					CS = S2;
				}else throw c;
				break;
			}
            case S2:
			{
				if(c ==' ') 
				{
                    return 2;
				}else if(c == '\n')
                {
                    return 2;
                    flag = 1;
                }else throw c;
				break;
			}
            case K:
			{
				if(c == '.') 
				{
					gc();
					CS = L;
				}else if(c == '-')
                {
                    gc();
                    CS = K1;
                }
				else throw c;
				break;
			}
            case K1:
			{
				if(c == '-') 
				{   
					gc();
					CS = S3;
				}else throw c;
				break;
			}
            case S3:
			{
				if(c ==' ') 
				{
                    return 3;
				}else if(c == '\n')
                {
                    return 3;
                    flag = 1;
                }else throw c;
				break;
			}
            case L:
			{
				if(c == '.') 
				{ 
					gc();
					CS = S5;
				}else if(c == '-')
                {
                    gc();
                    CS = S4;
                }
				else throw c;
				break;
			}
            case S4:
			{
				if(c ==' ') 
				{
                    return 4;
				}else if(c == '\n')
                {
                    return 4;
                    flag = 1;
                }else throw c;
				break;
			}
            case S5:
			{
				if(c ==' ') 
				{
                    return 5;
				}else if(c == '\n')
                {
                    return 5;
                    flag = 1;
                }else throw c;
				break;
			}
            case M:
			{
				if(c == '.') 
				{
					gc();
					CS = M1;
				}else if(c == '-')
                {
                    gc();
                    CS = N;
                }
				else throw c;
				break;
			}
            case M1:
			{
				if(c == '.') 
				{ 
					gc();
					CS = M2;
				}else throw c;
				break;
			}
            case M2:
			{
				if(c == '.') 
				{ 
					gc();
					CS = M3;
				}else throw c;
				break;
			}
            case M3:
			{
				if(c == '.') 
				{ 
					gc();
					CS = S6;
				}else throw c;
				break;
			}
            case S6:
			{
				if(c ==' ') 
				{
                    return 6;
				}else if(c == '\n')
                {
                    return 6;
                    flag = 1;
                }else throw c;
				break;
			}
            case N:
			{
				if(c == '.') 
				{
					gc();
					CS = N1;
				}else if(c == '-')
                {
                    gc();
                    CS = O;
                }
				else throw c;
				break;
			}
            case N1:
			{
				if(c == '.') 
				{ 
					gc();
					CS = N2;
				}else throw c;
				break;
			}
            case N2:
			{
				if(c == '.') 
				{        
					gc();
					CS = S7;
				}else throw c;
				break;
			}
            case S7:
			{
				if(c ==' ') 
				{
                    return 7;
				}else if(c == '\n')
                {
                    return 7;
                    flag = 1;
                }else throw c;
				break;
			}
            case O:
			{
				if(c == '.') 
                {
					gc();
					CS = O1;
				}else if(c == '-')
                {
                    gc();
                    CS = P;
                }
				else throw c;
				break;
			}
            case O1:
			{
				if(c == '.') 
				{
					gc();
					CS = S8;
				}else throw c;
				break;
			}               
            case S8:
			{
				if(c ==' ') 
				{
                    return 8;
				}else if(c == '\n')
                {
                    return 8;
                    flag = 1;
                }else throw c;
				break;
			}
            case P:
			{
				if(c == '.') 
				{
					gc();
					CS = S9;
				}else if(c == '-')
                {
                    gc();
                    CS = S0;
                }
				else throw c;
				break;
			}
            case S9:
			{
				if(c ==' ') 
				{
                    return 9;
				}else if(c == '\n')
                {
                    return 9;
                    flag = 1;
                }else throw c;
				break;
			} 
            case S0:
			{
				if(c ==' ') 
				{
                    return 0;
				}else if(c == '\n')
                {
                    return 0;
                    flag = 1;
                }else throw c;
				break;
			}
			default:
				break;
		}
	}while(true);
}

int main()
{
	try{
        while(flag == 0){
		    int i = Parser();
            cout << i;
        } 
    }
	catch(char c)
	{
		cerr<< "Error in Lexeme: " << c << endl;
	}
	return 0;
}

