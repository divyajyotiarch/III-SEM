/*
 ============================================================================
 Name        : Assignment10.cpp
 Author      : OS
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C++,
 ============================================================================
 */

#include <iostream>

using namespace std;

class deque
{
	int q[10],f,r,info;
public:
	deque()
	{
		f=-1;
		r=-1;
		info=0;
	}
	void insert_front();
	void insert_rear();
	void del_front();
	void del_rear();
	void display();
};

void deque::insert_rear()
{
	cout<<"Enter data \n";
	cin>>info;
	if(f==-1 && r==-1)
	{
		f=0; r=0;
		q[f]=info;
	}
	else if(f==0 && r==9)
	{
		cout<<"Overflow\n";
	}
	else if(r!=5)
	{
		r=r+1;
		q[r]=info;
	}
	else if(f!=0 && r==9)
	{
		for(int i=f;i<=r && f>-1;i++)
		{
			q[i-1]=q[i];
			f=f-1;
			q[r]=info;
		}
	}
}

void deque::insert_front()
{
	cout<<"Enter data\n";
	cin>>info;
	if(f==-1 && r==-1)
	{
		f=0; r=0;
		q[f]=info;
	}
	else if(f==0 && r==9)
	{
		cout<<"Overflow \n";
	}
	else if(f!=0 && r==9)
	{
			f=f-1;
			q[f]=info;
	}
	else if(f==0 && r<9)
	{
		int i=r;
		while(i!=-1)
		{
			q[i+1]=q[i];
			i--;
		}
		r=r+1;
		q[f]=info;
	}
	else if(f!=0 && r<9)
	{
		f=f-1;
		q[f]=info;
	}
}

void deque::del_front()
{
	if(f==-1 && r==-1)
	{
		cout<<"Underflow \n";
	}
	else if(f==r)
	{
		f=-1; r=-1;
	}
	else
	{
		f=f+1;
	}
}

void deque::del_rear()
{
	if(f==-1 && r==-1)
	{
		cout<<"Underflow \n";
	}
	else if(f==r)
	{
		f=-1; r=-1;
	}
	else
	{
		r=r-1;
	}
}

void deque::display()
{
	for(int i=f;i<=r;i++)
	{
		cout<<q[i]<<" ";
	}
	cout<<"\n";
}

int main()
{
	deque d;
	int c;
	do
	{
		cout<<"1. Enter from front \n";
		cout<<"2. Enter from rear \n";
		cout<<"3. Delete from front \n";
		cout<<"4. Delete from rear \n";
		cout<<"5. Exit \n";
		cout<<"Enter choice \n";
		cin>>c;
		switch(c)
		{
		case 1: d.insert_front();
				d.display();
				break;
		case 2: d.insert_rear();
				d.display();
				break;
		case 3: d.del_front();
				d.display();
				break;
		case 4: d.del_rear();
				d.display();
				break;
		}

	}while(c!=5);

	return 0;
}
