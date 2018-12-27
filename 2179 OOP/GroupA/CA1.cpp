#include<bits/stdc++.h>
using namespace std;

int main(int argc,char *argv[])
{

	if(argc<4)
	{
		cout<<"Enter \n ./a.out <operand1> <operator> <operand2> \n";
		exit(1);
	}
	
	int n1,n2;
	n1 = atoi(argv[1]);
	n2 = atoi(argv[3]);
	
	switch(*argv[2])
	{
		case '+': cout<<"Addition is: "<<n1+n2;
		break;
		case '-': cout<<"Subtraction is: "<<n1-n2;
		break;
		case '*': cout<<"Multiplication is: "<<n1*n2;
		break;
		case '/':
			try
			{
				cout<<"Division is: ";
				if(n2!=0)
				{
					cout<<n1/n2;
				}
				else
				throw 1;
			}
			catch(...)
			{
				cout<<"Infinity\n";
			}
			
			break;
	}
	
	return 0;
}
