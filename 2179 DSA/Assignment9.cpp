/*
 ============================================================================
 Name        : Assignment9.cpp
 Author      : OS
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C++,
 ============================================================================
 */

#include <iostream>

using namespace std;
class node
{
	char job[5];
	int n;
	node *next;
	friend class queue;
};

class queue
{
	node *front,*rear;
public:
	queue()
	{
		front=NULL;
		rear=NULL;
	}
	void insert();
	void del();
	void display();
	//void push(char);
	//void pop();

};

void queue::insert()
{
	node *new1=NULL;

	if(front==NULL)
	{
		new1=new node;
		cout<<"Enter job as J1,J2,..so on 1\n";
		cin>>new1->job;
	    front = new1;
	    new1->next=NULL;
	}
	else if(front!=NULL && rear==NULL)
	{
		new1=new node;
		cout<<"Enter job as J1,J2,..so on 2\n";
		cin>>new1->job;
		rear=new1;
		front->next=rear;
		new1->next=NULL;
	}
	else
	{
		new1=new node;
		cout<<"Enter job as J1,J2,..so on 3\n";
		cin>>new1->job;
		rear->next=new1;
		rear=new1;
		new1->next=NULL;
	}
}
void queue::del()
{
	node *s=NULL;
	s=front;
	front = front->next;
	s->next=NULL;
	delete(s);
}

void queue::display()
{
	node *c=NULL;
	c=front;
	while(c!=NULL)
	{
		cout<<c->job<<"  ";
		c=c->next;
	}
	cout<<"\n";
}

int main()
{
	queue q;
	int y;
	do
	{
		cout<<"Enter choice\n";
		cout<<"1. Insert jobs \n";
		cout<<"2. Delete jobs \n";
		cout<<"3.Display jobs \n";
		cin>>y;
		switch(y)
		{
		case 1: q.insert();
		break;
		case 2: q.del();
		break;
		case 3: q.display();
		break;
		}

	}while(y!=4);

}
