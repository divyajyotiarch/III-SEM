#include<iostream>
#include<math.h>
using namespace std;

class calci
{
	float n1;
	public:
	calci()
	{
		n1=0; 
	}	
	inline calci operator + (calci);
	calci operator - (calci);
	calci operator * (calci);
	calci operator / (calci);
	calci operator ^ (calci);
	void operator >> (istream &in)
{
	in>>n1;
}

void operator << (ostream &out)
{
	out<<n1;
}

//	friend ostream & operator << (ostream & , calci &);   without using friend function
//	friend istream & operator >> (istream & , calci &);
};

calci calci::operator + (calci a)
{
	calci b;
	b.n1 = this -> n1 + a.n1;
	return b;
} 

calci calci::operator - (calci a)
{
	calci b;
	b.n1 = this -> n1 - a.n1;
	return b;
}

calci calci::operator * (calci a)
{
	calci b;
	b.n1 = this -> n1*a.n1;
	return b;
}

calci calci::operator / (calci a)
{
	calci b;
	if(b.n1!=0)
	{
		b.n1 = this -> n1/a.n1;
	}
	else
	{
		throw 1;
	}
	return b;
}

calci calci::operator ^ (calci a)
{
	calci b;
	b.n1 =  pow(n1,a.n1);
	return b;
}


int main()
{
	calci no1,no2,sum,sub,mul,div,exp;
	int ch;
	do 
	{
		cout << " 1.Addtion\n 2.Subtraction\n 3.Multiplication\n 4.Division\n 5.Exponent\n 6.Exit\n Enter choice\n";
		cin>>ch;
		switch(ch)
    {
        case 1:
        	cout<<"Enter two numbers:\n";
        	no1>>cin;
			no2>>cin;
            cout <<"Addtion is ";
			sum=no1+no2;
			sum<<cout;	
			cout<<endl;		
            break;

        case 2:
        	cout<<"Enter two numbers:\n";
        	no1>>cin;
			no2>>cin;
            cout <<"Subtraction is ";
			sub=no1-no2;
			sub<<cout;
			cout<<endl;
            break;

        case 3:
        	cout<<"Enter two numbers:\n";
        	no1>>cin;
			no2>>cin;
            cout <<"Multiplication is ";
			mul=no1*no2;
			mul<<cout;
			cout<<endl;
            break;

        case 4:
        	try
        	{
        	cout<<"Enter two numbers:\n";
        	no1>>cin;
			no2>>cin;
            cout <<"Division is ";
        	div=no1/no2;
			div<<cout;
			cout<<endl;	
			}
			catch(int x)
			{
				cout<<"Infinity\n";
			}
			
            break;
            
            case 5:
			cout<<"Enter two numbers:\n";
        	no1>>cin;
			no2>>cin;        
    		cout<<"Exponent is ";
    		exp=no1^no2;
    		exp<<cout;	
    		cout<<endl;
    		break;
    }
		
	}while(ch<6);
}

