/*
Author : Divyajyoti Ukirde
Roll No. 2179
Batch : H1
 */
#include<iostream>
using namespace std;

class complex
{
	int re,im;
	public:
	complex()
	{
		re=0;
		im=0;	
	}
	complex operator +(complex);
	complex operator -(complex);
	complex operator *(complex);
	friend ostream & operator<<(ostream &, complex &);
	friend istream & operator>>(istream &, complex &);
};

complex complex::operator +(complex n1)
{
	complex n3;
    n3.re = this -> re + n1.re;
    n3.im = this -> im + n1.im;
    return n3;
}

complex complex::operator -(complex n1)
{
	complex n3;
    n3.re = this -> re - n1.re;
    n3.im = this -> im - n1.im;
    return n3;
}

complex complex::operator *(complex n1)
{
	complex n3;
	n3.re = this -> re*n1.re - im*n1.im;
	n3.im = this -> im*n1.re + re*n1.im;
	return n3;
}
istream & operator>>(istream &input, complex &n)
{
	input>>n.re;
	input>>n.im;
	return input;
}
ostream & operator<<(ostream &output, complex &n)
{
	if(n.im>0)
	{
		output<<n.re<<"+"<<n.im<<"i"<<endl;
	}
	else if(n.im==0)
	{
		output<<n.re<<endl;
	}
	else
	{
		output<<n.re<<n.im<<"i"<<endl;
	}
}

int main()
{
	complex n1,n2,n3,n4,n5;
	cout<<"Enter the first complex no \n";
	cin>>n1;
	cout<<n1;
	cout<<"Enter the second complex no \n";
	cin>>n2;
	cout<<n2;
	n3=n1+n2;
	n4=n1*n2;
	n5=n1-n2;
	cout<<"Addition is \n"<<n3;
	cout<<"\n Multiplication is \n"<<n4;
	cout<<"\n Subtraction is \n"<<n5;
	return 0;	
}
//OUTPUT
/*[pict@localhost GroupA]$ ./a.out
Enter the first complex no 
5
-1
Enter the second complex no 
-2
6
Addition is 
3+5i

 Multiplication is 
-4+32i
*/









