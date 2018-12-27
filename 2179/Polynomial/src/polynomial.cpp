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
class polynomial;
class term
{
	int c,e;

public:

	friend class polynomial;
	friend istream & operator >>(istream &, polynomial &);
	friend ostream & operator <<(ostream &, polynomial &);
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
	friend istream & operator >>(istream &, polynomial &);
	friend ostream & operator <<(ostream &, polynomial &);
}u,v,w,y;

istream & operator >>(istream &input , polynomial &n1)
{
	input>>n1.n;
	for(int i=0;i<n1.n;i++)
	{
	input>>n1.a[i].c>>n1.a[i].e;
	}
	return input;
}

ostream & operator <<(ostream &output, polynomial &n1)
{
	for (int i=0;i<n1.n;i++)
		{
			output<<n1.a[i].c<<"x^"<<n1.a[i].e<<" +"<<" ";
		}
		output<<"\n";
		return output;
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
	cout<<"No of terms";
	cout<<"Input coefficient and exponent";
	cin>>u;

cout<<"Evaluating polynomial 1 \n";
u.eval();
cout<<u;

    cout<<"No of terms";
	cout<<"Input coefficient and exponent";
	cin>>v;
cout<<"Evaluating polynomial 2 \n";
v.eval();
cout<<v;
cout<<"Addition is \n";
w.add(u,v);
w.displaysum();
cout<<"Multiplication is \n";
y.multiply(u,v);
y.displaymul();
return 0;
}














