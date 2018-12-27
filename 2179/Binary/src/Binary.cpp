/*
 ============================================================================
 Name        : Assignment5.cpp
 Author      : OS
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C++,
 ============================================================================
 */

#include <iostream>

using namespace std;

struct node
{
	int bin;
	node *next;
	node *prev;
};
class binary
{
	node *s,*l;
	public:
	binary()
	{
		s=NULL;
		l=NULL;
	}
	void input();
	void complement1();
	void complement2();
//	void add();
	void display();

};

void binary::input()
{
	node *new1;
	new1=new node;
	cin>>new1->bin;
	if(s==NULL)
	{
		s=new1;
		l=new1;
		new1->prev=NULL;
		new1->next=NULL;
	}
	else
	{
		l->next=new1;
		new1->prev=l;
		new1->next=NULL;
		l=new1;
	}
}

void binary::complement1()
{
	node *c=NULL;
	c=s;
	while(c->next!=NULL)
	{
		if(c->bin==0)
		{
			c->bin=1;
		}
		else
		{
			c->bin=0;
		}
		c=c->next;
	}
	node *cs=NULL;
			cs=s;
			while(cs!=NULL)
			{
				cout<<c->bin<<" ";
				cs=cs->next;
			}
			cout<<endl;
}

void binary::complement2()
{
	node *c=NULL;
	c=l;
	while(c->prev!=NULL)
	{
		if(c->bin==1)
		{
			while(c->prev!=NULL)
			{
				if(c->bin==0)
						{
							c->bin=1;
						}
						else
						{
							c->bin=0;
						}
				c=c->prev;
			}
		}
		c=c->prev;
	}
	node *cs=NULL;
		cs=s;
		while(cs!=NULL)
		{
			cout<<c->bin<<" ";
			cs=cs->next;
		}
		cout<<endl;
}

void binary::display()
{
	node *c=NULL;
	c=s;
	while(c!=NULL)
	{
		cout<<c->bin<<" ";
		c=c->next;
	}
	cout<<endl;
}

int main()
{
	binary b1,b2,b3;
	char ch;
		cout<<"A. Enter a binary digit 0/1"<<endl;
		cout<<"B. 1's Complement"<<endl;
		cout<<"C. 2's Complement"<<endl;
		cout<<"D. Addition of binary numbers"<<endl;
		cout<<"E. Display"<<endl;
	do
	{
		cin>>ch;
		switch(ch)
		{
		case 'A': 	b1.input();
		break;
		case 'B':   b1.complement1();
		break;
		case 'C':   b1.complement2();
		break;
	//	case 'D':   b1.add();
	//	break;
		case 'E':   b1.display();
		break;
		}
	}while(ch!='F');


	return 0;
}




















