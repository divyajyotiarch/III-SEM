//============================================================================
// Name        : mini.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include <ctime>
using namespace std;
int n;
class details
{
	int bno;
	string bname;
	string aname;
	bool val;
	int stid;
	char dt[100];
	details *next;
public:
	friend class book;
	friend class student;
	details()
	{
		bname='\0';
		bno=0;
		aname='\0';
		val=0;
		stid=0;
		dt[100]='\0';
		next=NULL;
	}
};
class book
{
	details *start;
	details *last;
	int m;
public:
	book()
		{
			start=NULL;
			last=NULL;
			m=0;
		}
	friend class student;
	void create();
	void display();
	void dis_author(string s);
	void avail();
};
class info
{
	int id;
	string name;
	bool b;
	int bid;
	char date[100];
	info *nxt;

public:
	info()
{
		name='\0';
		id=0;
		b=0;
		bid=0;
		date[100]='\0';
		nxt=NULL;
}
	friend class student;
};
class student
{
	info *s,*l;
public:
	student()
{
		s=NULL;
		l=NULL;
}
	void issue(book b);
	void deposit();
	void sdisplay();
};
void book::create()
{
	details *p=new details;
		cout<<"Enter book  name,book id and author name\n";
		cin>>p->bname;
		cin>>p->bno;
		cin>>p->aname;
		if(start==NULL)
			 	 {
			 	   start=p;
			 	   last=p;
			 	  last->next='\0';
			 	 }
			 else
			 {
				last->next=p;
			         last=p;
				 last->next='\0';
			 }
}
void book::avail()
{
	details *c=start;
		int count=0;
		if(c==NULL)
		{
			cout<<"\nNO BOOKS AVAILABLE!";
		}
		else
		{
			cout<<"\tBOOK ID \t\t BOOK NAME\t\tAUTHOR NAME\t\tISSUED\t\tSTUDENT ID\t\tRETURN DATE\n";
					    cout<<"__________________________________________________________________________________________________________________"<<endl;
			while(c!=NULL)
			{


				if(c->val==0)
				{
					cout<<"\t"<<c->bno;
					cout<<"\t\t"<<c->bname<<"\t\t"<<c->aname<<" \t available"<<endl;
				}
				c=c->next;
				count++;
			}
		}
			m=count;
		cout<<"\nTotal count is : "<<count;
}
void book::display()
{
	details *c=start;
	int count=0;
	if(c==NULL)
	{
		cout<<"\nNO BOOKS AVAILABLE!";
	}
	else
	{
		cout<<"\tBOOK ID \t\t BOOK NAME\t\tAUTHOR NAME\t\tISSUED\t\tSTUDENT ID\t\tRETURN DATE\n";
				    cout<<"__________________________________________________________________________________________________________________"<<endl;
		while(c!=NULL)
		{

			if(c->val==1)
			{
			cout<<"\t"<<c->bno;
			cout<<"\t\t\t\t"<<c->bname<<"\t\t"<<c->aname<<"\t\t"<<c->val<<"\t\t"<<c->stid<<"\t\t"<<c->dt<<"not available"<<endl;
			}
			else
			{
				cout<<"\t"<<c->bno;
				cout<<"\t\t"<<c->bname<<"\t\t"<<c->aname<<"available"<<endl;
			}
			c=c->next;
			count++;
		}
	}
		m=count;
	cout<<"\nTotal count is : "<<count;
}
void book::dis_author(string s)
{
	details *c=start;
	int count=0;
	if(c==NULL)
	{
		cout<<"\nNO BOOKS AVAILABLE!";
	}
	else
	{
		cout<<"\tBOOK ID \t\t BOOK NAME\t\tAUTHOR NAME\t\tISSUED\t\tSTUDENT ID\t\tRETURN DATE\n";
				    cout<<"__________________________________________________________________________________________________________________"<<endl;
		while(c!=NULL)
		{

			if(c->val==1&& c->aname==s)
			{
			cout<<"\t"<<c->bno;
			cout<<"\t\t\t\t"<<c->bname<<"\t\t"<<c->aname<<"\t\t"<<c->val<<"\t\t"<<c->stid<<"\t\t"<<endl;
			cout<<"RETURN DATE:";
			for(int j=0;j<100;j++)
			{
				cout<<c->dt[j];
			}
			}
			else if(c->aname==s)
						{
							cout<<"\t"<<c->bno;
							cout<<"\t\t"<<c->bname<<"\t\t"<<c->aname<<"available"<<endl;
						}
						c=c->next;
						count++;
					}
				}
					m=count;
				cout<<"\nTotal count is : "<<count;
}
void student::issue(book b)
{
	info *p=new info;
	int n;
	cout<<"Enter your student ID and name.\n";
	cin>>p->id;
	cin>>p->name;
	if(s==NULL)
				 	 {
				 	   s=p;
				 	   l=p;
				 	  l->nxt='\0';
				 	 }
				 else
				 {
					l->nxt=p;
				         l=p;
					 l->nxt='\0';
				 }
	cout<<"Enter the Book ID that you want to issue.\n";
	cin>>n;
	details *a;
	a=b.start;
	while(a!=NULL)
	{
		if(a->bno==n&&a->val!=1)
		{
			cout<<"The book you have issued is:";
			cout<<"BOOK NAME:"<<a->bname<<"\t\t"<<"AUTHOR NAME:"<<a->aname<<"\t\t"<<"BOOK ID:"<<a->bno<<"\n";
			a->val=1;
			std::time_t issued = std::time(NULL);
			    std::tm due_tm = *std::localtime(&issued);
			    due_tm.tm_mday += 7;
			    std::time_t due = std::mktime(&due_tm);

			    char mbstr[100];
			    if (std::strftime(mbstr, 100, "%d %B %Y", std::localtime(&issued)))
			        std::cout << "issued on: " << mbstr << '\n';

			    if (std::strftime(mbstr, 100, "%d %B %Y", std::localtime(&due)))
			        std::cout << "due to: " << mbstr << '\n';
			   for(int i=0;i<100;i++)
			   {
			    a->dt[i]=mbstr[i];
			    s->date[i]=mbstr[i];
			   }
			   a->stid=p->id;
		}
		else if(a->bno==n&&a->val==1)
		{
			cout<<"ALREADY ISSUED";
		}
		a=a->next;
	}
}
void student::deposit()
{
	cout<<"Enter your student id:";
	cin>>s->id;
}
int main()
{
	book b;
	b.create();
	b.create();
	b.create();
	b.dis_author("ww");
	b.avail();
	b.display();
	student s;
	s.issue(b);
	b.avail();
	b.display();
return 0;
}
