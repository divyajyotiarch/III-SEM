#include<iostream>
using namespace std;

class node
{
	char ch;
	int b,m,n;
	node *next;
	node *prev;
	public:
		friend class inox;
};

class inox
{
	node *a[10];
	node *s,*l;
	public:
		inox()
		{
			for(int i=0;i<10;i++)
			{
				a[i]=NULL;
			}
			s=NULL;
			l=NULL;
		}
	void create();	
	void initial();
	void display();
	void book();
	void cancel();
};

void inox::create()
{
	node *new1=NULL;
	for(int i=0;i<10;i++)
	{
		a[i]=new node;
		a[i]->b=0;
		a[i]->next=NULL;
		for(int j=0;j<7;j++)
		{
			if(a[i]->next==NULL)
			{
				new1=new node;
				new1->ch='A';
				new1->m=i;
				new1->n=j;
				s=new1;
				l=new1;
				new1->next=s;
				a[i]->next=s;
			}
			else
			{
				new1=new node;
				new1->ch='A';
				new1->m=i;
				new1->n=j;
				l->next=new1;
				new1->prev=l;
				l=new1;
				new1->next=s;
			}
		}
	}
}

void inox::display()
{
	node *c=NULL;
	cout<<"AV\n";
	for(int i=0;i<10;i++)
	{
		c=a[i];
		cout<<7 - c->b<<"  ";
		c=c->next;
		for(int j=0;j<7;j++)
		{
			cout<<c->ch<<"-"<<c->n<<c->m<<"  ";
			c=c->next;	
		}	
		cout<<endl;
	}
}

void inox::initial()
{
	node *c=NULL;
	for(int i=6;i<10;i++)
	{
		c=a[i];
		c=c->next;
		for(int j=0;j<6;j++)
		{
			c->ch='U';
			c=c->next;
			a[i]->b++;
		}
	}
	for(int i=0;i<4;i++)
	{
		c=a[i];
		c=c->next;
		while(c->n!=3)
		{
			c=c->next;
		}
		for(int j=3;j<6;j++)
		{
			c->ch='U';
			c=c->next;
			a[i]->b++;
		}
	}
	for(int i=2;i<6;i++)
	{
		c=a[i];
		c=c->next;
		while(c->n!=1)
		{
			c=c->next;
		}
		for(int j=1;j<3;j++)
		{
			c->ch='U';
			c=c->next;
			a[i]->b++;
		}
	}
}

void inox::book()
{
	node *bk=NULL;
	char ch;
	int s,r,no[10];
	cout<<"Enter the no. of seats to be booked\n";
	cin>>s;
	for(int i=0;i<10;i++)
	{
		if(s< 7 - a[i]->b)
		{
			cout<<"Do you wish to book in row "<<i<<" ? y/n \n";
			cin>>ch;
			if(ch=='y')
			{
				cout<<"Enter seat no.s row (space) seat\n";
				for(int k=0;k<s;k++)
				{
					cin>>no[k]>>r;
					if(r==i)
					{
						bk=a[r];
						bk=bk->next;
						while(bk->n!=no[k])
						{
							bk=bk->next;
						}
							bk->ch='U';
							bk=bk->next;		
					}
					else
					{
						cout<<"invalid seat \n";
						k=0;
					}
				}
				break;
			}
		}
		else
		{
			cout<<"No consecutive seats available in row "<<i<<endl;
			cout<<"Do you wish to proceed with random booking? y/n \n";
			cin>>ch;
			if(ch=='y')
			{
				for(int i=0;i<s;i++)
				{
					bk=a[i];
					bk=bk->next;
					while(bk->n!=6)
					{
						bk=bk->next;
					}
					bk->ch='B';
				}
			}
			else
			{
				cout<<"Thank you\n";
			}
		}
	}
}

int main()
{
	inox c;
	c.create();
	c.initial();
	c.display();
	c.book();
	c.display();
	return 0;
}


