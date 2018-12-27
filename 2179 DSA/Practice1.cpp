#include<iostream>
using namespace std;

class queue
{
	int a[10];
	int front,rear,item;
	public:
	queue()
	{
		front=-1;
		rear=-1;
	}	
	void insert();
	void display();
	void del();
};

void queue::insert()
{
	if(front==-1&&rear==-1)
	{
		front=0;
		rear=0;
	}
	else if((rear==9&&front==0)||front==rear+1)
	{
		cout<<"overflow\n";
	}
	else if(front!=0&&rear==9)
	{
		rear=0;
	}
	else
	{
		rear=rear+1;
	}
	cin>>item;
	a[rear]=item;
}

void queue::display()
{
	for(int i=front;i!=rear+1;i++)
	{
		cout<<a[i]<<" ";
	}
}

void queue::del()
{
	if(front==-1)
	{
		cout<<"underflow\n";
	}
	else if(front==rear+1)
	{
		front=0;
		front=front+1;
	}
	else
	{
		front=front+1;
	}
}

int main()
{
	queue q;
	int c;
	do
	{
		cout<<"1.insert \t2.delete \t3.display\n";
		cin>>c;
		switch(c)
		{
			case 1: q.insert();
			break;
			case 2: q.del();
			break;
			case 3: q.display();
			break;
		}
	}while(c<4);
	return 0;
}
