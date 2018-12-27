/*
 ============================================================================
 Name        : Assignment3.cpp
 Author      : hh
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C++,
 ============================================================================
 */

#include <iostream>
#include <math.h>
using namespace std;

class term
{
	int c,e;

public:

	friend class polynomial;
};

class polynomial
{
	term a[10];
	int n;

public:

	void getdata();
	void eval();
	void add(polynomial,polynomial);
	void multiply(polynomial,polynomial);
	void display();
	void displaysum();
	void displaymul();
}u,v,w,y;


void polynomial::getdata()
{
	cout<<"No of terms";
	cin>>n;

	cout<<"Input coefficient and exponent";
	for(int i=0;i<n;i++)
	{
		cin>>a[i].c>>a[i].e;
	}
}

void polynomial::eval()
{
	int m,val=0;
	cout<<"Input x";
	cin>>m;

	for(int i=0;i<n;i++)
	{
		val=val + a[i].c*pow(m,a[i].e);
	}
        cout<<val<<endl;
}

void polynomial::add(polynomial u1,polynomial v1)
{   int n1,n2;
	n1=u1.n;n2=v1.n;
	int i=0,j=0,k=0;
	do
	{
	if(u1.a[i].e==v1.a[j].e)
	{
		a[k].c=u1.a[i].c+v1.a[j].c;
		a[k].e=u1.a[i].e;
		i++;
		j++;
		k++;
	}
	else if(u1.a[i].e>v1.a[j].e)
	{
		a[k]=u1.a[i];
		i++;
	    k++;
	}
	else
	{
		a[k]=v1.a[j];
		j++;
		k++;
	}
	}while(i<n1&&j<n2);
	while(j<n1)
	{
		a[k]=v1.a[j];
		j++;
		k++;
	}
	while(i<n2)
	{
		a[k]=u1.a[i];
		i++;
		k++;
	}

}

void polynomial::display()
{
	for (int i=0;i<(n);i++)
	{
		cout<<a[i].c<<"x^"<<a[i].e<<" +"<<" ";
	}
	cout<<"\n";
}
void polynomial::displaysum()
{
	for(int i=0;i<(u.n+v.n);i++)
		{
			cout<<a[i].c<<"x^"<<a[i].e<<" +"<<" ";
		}
	cout<<"\n";
}
void polynomial::multiply(polynomial u1,polynomial v1)
{
	int i,j,k=0,n1,n2;
	n1=u1.n;n2=v1.n;
	for (int i=0;i<n1;i++)
	{
		for(int j=0;j<n2;j++)
		{
			{
				a[k].e=u1.a[i].e+v1.a[j].e;
				a[k].c=u1.a[i].c*v1.a[j].c;
				k++;
			}
		}
	}
}
void polynomial::displaymul()
{
	for (int i=0;i<(u.n*v.n);i++)
			{
				cout<<a[i].c<<"x^"<<a[i].e<<" +"<<" ";
			}
		cout<<"\n";
}


int main()
{
u.getdata();
cout<<"Evaluating polynomial 1 \n";
u.eval();
u.display();
v.getdata();
cout<<"Evaluating polynomial 2 \n";
v.eval();
v.display();
cout<<"Addition is \n";
w.add(u,v);
w.displaysum();
cout<<"Multiplication is \n";
y.multiply(u,v);
y.displaymul();
return 0;
}















