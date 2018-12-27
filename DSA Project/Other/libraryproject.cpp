#include<iostream>
#include<bits/stdc++.h>
#include<ctime>
using namespace std;

class date
{
  private:
    int dd;
    int mm;
    int yy;
  public:
  
  date(int d,int m,int y)
  {
  		dd=d; mm=m; yy=y;
	  }
   void read();
   void display();
   void diff(date d1,date d2);
 
};
   void date::read()
   { cout<<"enter dd:";
     cin>>dd;
     cout<<"enter mm:";
     cin>>mm;
     cout<<"enter year:";
     cin>>yy;
   }
   
   void date ::display()
   {
    cout<<"Day : "<<dd<<" Month :"<<mm<<"  Year : "<<yy<<endl;
   }
   void date:: diff(date d1,date d2)
   {   if(d1.dd>=d2.dd)
		 dd= d1.dd-d2.dd;
     	  else
 	{
   d1.dd+=30;
   d1.mm-=1;
   dd= d1.dd-d2.dd;
	 }
       if(d1.mm>=d2.mm)
	   mm= d1.mm-d2.mm;
       else
	 {
   d1.mm+=12;
   d1.yy-=1;
   mm= d1.mm-d2.mm;
 	}
	yy=d1.yy-d2.yy;
	
	cout<<"Fine is: "<<dd*5;
   }
  /* int main()
   {
     date dob,cdate,today;
     cout<<"Enter Date of birth"<<endl;
     dob.read();
     cout<<"enter current date "<<endl;
     cdate.read();
     today.diff(cdate,dob);
     cout<<"Date of birth : ";
     dob.display();
     cout<<"Current date : ";
     cdate.display();
     cout<<"today your age: ";
     today.display();

     return 0;
    }
*/
struct snode
{
	string name;
	int rno;
	string bId;
//	date retDate;
	snode *next;
};

struct bnode
{
	string bknam;
	string bkId;
	int copies;
	bnode *next;
	snode *down;
};


class book
{
	bnode *sb,*lb;
	public:
		book()
		{
			sb=NULL;
			lb=NULL;
		}
		void insert();
		void update();
//		void issue();
		void display();
		friend class student;
};

class student
{
	snode *s,*l;
	public:
		student()
		{
			s=NULL;
			l=NULL;
		}
	void create();
	void show();
	void issue(book);
			void ret();
	friend class book;	
};

void book::insert()
{	cout<<"enter book name , book id , no. of copies \n";
	bnode *new1=NULL;
	if(sb==NULL){
		sb=new bnode;
		cin>>sb->bknam>>sb->bkId>>sb->copies;
		sb->next=NULL;
		lb=sb;
	}
	else
	{
		new1=new bnode;
		cin>>new1->bknam>>new1->bkId>>new1->copies;
		lb->next=new1;
		new1->next=NULL;
		lb=new1;
	}
}

void book::display()
{
	int sno=0;
	bnode *c;
	c=sb;
	cout<<"SNo \t\t Name \t\t\t\t ID \t\t\t NO. of Copies\n";
	while(c!=NULL)
	{
		sno++;
		cout<<sno<<"\t\t"<<c->bknam<<"\t\t\t"<<c->bkId<<"\t\t"<<c->copies<<"\n";
		c=c->next;
	}	
}

void student::create()
{	cout<<"enter student name and rno \n";
	snode *new1=NULL;
	if(s==NULL){
		s=new snode;
		cin>>s->name>>s->rno;
		s->next=NULL;
		l=s;
	}
	else
	{
		new1=new snode;
		cin>>new1->name>>new1->rno;
		l->next=new1;
		new1->next=NULL;
		l=new1;
	}
}

void student::show()
{
	int sno=0;
	snode *c;
	c=s;
	cout<<"SNo \t\t Name \t\t Roll NO \n";
	while(c!=NULL)
	{
		sno++;
		cout<<sno<<"\t\t"<<c->name<<"\t\t\t"<<c->rno<<"\n";
		c=c->next;
	}	
}
void student::issue(book bk)
{	
	string bid;   //bid =book id no = rollno
	int no;
	cout<<"Enter student roll no. \n";
	cin>>no;
	cout<<"Enter the book ID \n";
	cin>>bid;
	bnode *c=NULL;
	c=bk.sb;
	snode *a=NULL;
	while(c!=NULL)
	{
		if(c->bkId == bid)
		{
			break;
		}
		else
		{
		c=c->next;	
		}
	}
	a=s;
	while(a!=NULL)
	{
		if(a->rno==no)
		{
			c->down=a;
			break;	
		}
		else
		{
			a=a->next;
		}
	}
	cout<<a->name<<"  "<<a->rno<<"  "<<c->bkId<<"  "<<c->bknam<<"  "<<" issued \n";
	std::time_t isd = std::time(NULL);
			    std::tm due_tm = *std::localtime(&isd);
			    due_tm.tm_mday += 7;
			    std::time_t due = std::mktime(&due_tm);

			    char str[100];
			    if (std::strftime(str, 100, "%d %B %Y", std::localtime(&isd)))
			        std::cout << "issued on: " << str << '\n';

			    if (std::strftime(str, 100, "%d %B %Y", std::localtime(&due)))
			        std::cout << "due to: " << str << '\n';
}

int main()
{
	student st;
	book b;
	char ch;
	do 
	{
	st.create();
	cout<<"y/n \n";
	cin>>ch;
	}while(ch!='n');
	st.show();
	do 
	{
	b.insert();
	cout<<"y/n \n";
	cin>>ch;
	}while(ch!='n');
	b.display();
			st.issue(b);
	return 0;
}
