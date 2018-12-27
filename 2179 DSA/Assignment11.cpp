/*
 ============================================================================
 Name        : Assignment11.cpp
 Author      : OS
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C++,
 ============================================================================
 */

#include <iostream>

using namespace std;

class search
{
	
public:
	void linear_search(int [],int);
	void sentinel_search(int [],int);
	void binary_search(int [],int);
	int fibo_search(int [],int);
};

void search::linear_search(int z[],int x)
{
	int i;
	for(i=0;i<10;i++)
	{
		if(x==z[i])
		{
			cout<<"Using Linear search Student found with Roll no "<<x<<"\n";
			break;
		}
	}
	if(i==10)
	{
		cout<<"Not found \n";
	}

}

void search::sentinel_search(int z[],int x)
{
	int i;
	z[11]=x;
	for(i=0; ;i++)
	{
		if(x==z[i])
		{
			if(i!=11)
			{
				cout<<"Using Sentinel search Student found with Roll no "<<x<<"\n";
				break;
			}
			else if(i==11)
			{
				cout<<"Not found \n";
				break;
			}
		}
	}

}

void search::binary_search(int z[],int x)
{
	int temp,flag=0;
		for(int i=1;i<10;i++)
		{
			for(int j=0;j<10-i;j++)
			{
				if(z[j] >z[j+1])
				{
					temp=z[j];
					z[j]=z[j+1];
					z[j+1]=temp;
				}
			}
		}

	int i=0, j=9,m;
	while(i<=j)
	{
		m=(i+j)/2;
		if(z[m]==x)
		{
			flag=1;
			break;
		}
		else if(z[m]>x)
			{
				j=m-1;
			}
			else if(z[m]<x)
			{
				i=m+1;
			}
	}
	if(flag==1)
	{
		cout<<"Using Binary search Student found with Roll no "<<x<<"\n";
	}
	else
	{
		cout<<"Not found \n";
	}
}

int search::fibo_search(int z[],int x)
{
	int temp,m,m1,m2,flag;
	for(int i=2;i<11;i++)
			{
				for(int j=1;j<11-i;j++)
				{
					if(z[j]>z[j+1])
					{
						temp=z[j];
						z[j]=z[j+1];
						z[j+1]=temp;
					}
				}
			}
m=1;m1=1;m2=0;
int min,y,i;
		while(m<11)
		{
			m2=m1;
			m1=m;
			m=m1+m2;
		}

		y=0;
		while(m>0)
		{
			flag=0;
			//i=min(m1+y,10)
			min=m1+y;
			if(min>10)
			{
				i=10;
			}
			else
			{
				i=min;
			}

			if(x==z[i])
			{
				flag=1;
				break;
			}
			else if(x<z[i])
			{
				if(m2==0)
				{
					return -1;
				}
				m=m1;
				m1=m2;
				m2=m-m1;
			}
			else if(x>z[i])
			{
				if(m1==1)
				{
					return -1;
				}
				m=m-m1;
				m1=m1-m2;
				m2=m-m1;
				y=i;
			}
		}
		if(flag==1)
		{
			cout<<"Using Fibonacci search Student found with Roll no "<<x<<"\n";
		}
		else if(flag==0)
		{
			cout<<"Not found \n";
		}

}

int main()
{
	int rno[10]={2179, 2235, 2282, 2175, 2125, 2145, 2256, 2347, 2341, 2454},
	srno[11]={2179, 2235, 2282, 2175, 2125, 2145, 2256, 2347, 2341, 2454},
	frno[11]={0,2179, 2235, 2282, 2175, 2125, 2145, 2256, 2347, 2341, 2454};
	search s;
	int n;
	int c;
		do
		{
			cout<<"1. Linear search \n";
			cout<<"2. Sentinel search \n";
			cout<<"3. Binary search \n";
			cout<<"4. Fibonacci Search \n";
			cout<<"5. Input\n";
			cout<<"6. Exit \n";
			cin>>c;
			switch(c)
			{
			case 1:   s.linear_search(rno,n);
				break;
			case 2:		s.sentinel_search(srno,n);
				break;
			case 3:		s.binary_search(rno,n);
				break;
			case 4:		s.fibo_search(frno,n);
				break;
				case 5:
					cout<<"Enter the roll no. you wish to search \n";
					cin>>n;
					break;
			}

		}while(c<6);
		return 0;
}
