/*
 ============================================================================
 Name        : Asignment9.cpp
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
	node *next=NULL;
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
	void insertsort();
	void del();
	void display();
	//void push(char);
	//void pop();

};


void queue::insertsort()
{
	node *new1=NULL,*prev=NULL,*curr=NULL;
	new1=new node;
	cout<<"Enter job as J1,J2,..so on \n";
	cin>>new1->job;
	cout<<"Add priority\n";
	cin>>new1->n;

	if(front==NULL)
		{
			front = new1;
			new1->next=NULL;
			rear=new1;
		}
	else if(new1->n <= rear->n)   //If the next item is less than the current item, make it "current item"
	{
		rear->next=new1;
		new1->next=NULL;
		rear=new1;
	}
	else if(new1->n > front->n)
	{
		new1->next=front;
		front=new1;
	}
	else if(new1->n > rear->n && rear->n != front->n)
	{
		curr=front;
		while(curr!=NULL)
		{
			if(curr->n < new1->n)
			{
				prev->next=new1;
				new1->next=curr;
			}
			prev=curr;
			curr=curr->next;
		}
		rear=prev;
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
		cout<<c->job<<"  "<<c->n<<"  ";
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
		case 1: q.insertsort();
		break;
		case 2: q.del();
		break;
		case 3: q.display();
		break;
		}

	}while(y!=4);

}
