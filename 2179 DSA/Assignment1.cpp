#include<iostream>
#include<string.h>
using namespace std;

class data
{
	int roll;
	string name;
	public:
		friend class sets;
};

class sets
{
	data a[10];
	int n;
	public:
		void input();
		void inputset(sets);
		void displayset();
		void unionn(sets,sets);
		void intersection(sets,sets);
		void difference(sets,sets);
};

void sets::input()
{
	cout<<"Enter the no. of students\n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter roll no. and name\n";
		cin>>a[i].roll>>a[i].name;
	}
}

void sets::inputset(sets all)
{
	cout<<"Enter the no. of students\n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter roll no.\n";
		cin>>a[i].roll;
		for(int j=0;j<all.n;j++)
		{
			if(all.a[j].roll == a[i].roll)
			{
				a[i] = all.a[j];
				break;
			}
			else if(j==all.n-1)
			{
				cout<<"Student does not exist\n";
				exit(1);
			}
		}
		
	}
}

void sets::displayset()
{
	cout<<"Students\n";
	for(int i=0;i<n;i++)
	{
		cout<<a[i].roll<<"  "<<a[i].name<<endl;
	}
}

void sets::unionn(sets p,sets q)
{
	int k=0,flag=0;
	for(int i=0;i<p.n;i++)
	{
			a[k] = p.a[i];
			k++;
	}
	for(int i=0;i<q.n;i++)
	{
		flag=0;
		for(int j=0;j<k;j++)
		{
			if(a[j].roll!=q.a[i].roll)
			{
				flag=1;
			}
			else
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			a[k] = q.a[i];
			k++;
		}
	}
	n=k;
}

void sets::intersection(sets p,sets q)
{
	int k=0;
	for(int i=0;i<p.n;i++)
	{
		for(int j=0;j<q.n;j++)
		{
			if(p.a[i].roll==q.a[j].roll)
			{
				a[k] = p.a[i];
				k++;
			}
		}
	}
	n=k;
}

void sets::difference(sets p,sets q)
{
	int k=0,flag=0;
	for(int i=0;i<p.n;i++)
	{
		flag=0;
		for(int j=0;j<q.n;j++)
		{
			if(p.a[i].roll==q.a[j].roll)
			{
				flag=0;
				break;
			}
			else
			{
				flag=1;
			}
		}
		if(flag==1)
		{
			a[k]=p.a[i];
			k++;
		}
	}
	n=k;
}

int main()
{
	sets a,b,c,u,in,o,bad,cric;
	cout<<"All students\n";
	a.input();  a.displayset();
	cout<<"Students playing badminton\n";
	b.inputset(a);	b.displayset();
	cout<<"Students playing cricket\n";	
	c.inputset(a);	c.displayset();
	cout<<"Students playing either\n";
	u.unionn(b,c);
	u.displayset();
	cout<<"Students playing both\n";
	in.intersection(b,c);
	in.displayset();
	cout<<"Only badminton\n";
	bad.difference(b,c);
	bad.displayset();
	cout<<"Only cricket\n";
	cric.difference(c,b);
	cric.displayset();
	cout<<"others\n";
	o.difference(a,u);
	o.displayset();
	
	return 0;
}
