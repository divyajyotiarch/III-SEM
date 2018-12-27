#include<iostream>
#include<bits/stdc++.h>
#include<ctime>
#include<fstream>
using namespace std;

class date
{
  private:
    int dd;
    int mm;
    int yy;
  public:
friend class student;
  date(int d,int m,int y)
  {
  		dd=d; mm=m; yy=y;
	  }
   void read();
   void display();
   int diff(date d1,date d2);

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
   
   int date:: diff(date d1,date d2)
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
	return dd;
   }

struct bnode
{
	string bknam;
	string bkId;
	int copies;
	bnode *next;
};

struct snode
{
	string name;
	int rno;
	string bId;
	char str1[100],str2[100];
	snode *next;
	bnode *down;
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
			void ret(book);
	friend class book;
};

void book::insert()
{
	ofstream out;
	out.open("book.txt",ios::app);
	if(out.is_open())
	{
	cout<<"enter book name , book id , no. of copies \n";
	bnode *new1=NULL;
	if(sb==NULL){
		sb=new bnode;
		cin>>sb->bknam>>sb->bkId>>sb->copies;
		sb->next=NULL;
		lb=sb;
		out<<lb->bknam<<"\t\t\t"<<lb->bkId<<"\t\t"<<lb->copies<<"\n";
	}
	else
	{
		new1=new bnode;
		cin>>new1->bknam>>new1->bkId>>new1->copies;
		lb->next=new1;
		new1->next=NULL;
		lb=new1;
		out<<lb->bknam<<"\t\t\t"<<lb->bkId<<"\t\t"<<lb->copies<<"\n";
	}
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
{	
	ofstream out;
	out.open("student.txt",ios::app);
	if(out.is_open())
	{
	cout<<"enter student name and rno \n";
	snode *new1=NULL;
	if(s==NULL){
		s=new snode;
		cin>>s->name>>s->rno;
		s->next=NULL;
		l=s;
		out<<l->name<<"\t\t\t"<<l->rno<<"\n";
	}
	else
	{
		new1=new snode;
		cin>>new1->name>>new1->rno;
		l->next=new1;
		new1->next=NULL;
		l=new1;
		out<<l->name<<"\t\t\t"<<l->rno<<"\n";
	}
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
	//date d1,d2;
	string bid;   //bid =book id no = rollno
	int no;
	cout<<"Enter student roll no. \n";
	cin>>no;
	
	bnode *c=NULL;
	snode *p=NULL;
	c=bk.sb;
	p=s;
		while(p->rno!=no)
	{
		p=p->next;
	}
	 if(p==NULL)
		{
		cout<<"This roll no. does not exist\n";	
		}
		else
		{
	cout<<"Enter the book ID \n";
	cin>>bid;
		while(c->bkId!=bid)
	{
		c=c->next;
	}
		}

		if(c->copies!=0&&c!=NULL&&p!=NULL&&p->down!=c)
		{
		c->copies--;
		p->bId=bid;
		p->down=c;
	
	cout<<p->name<<"  "<<p->rno<<"  "<<p->down->bkId<<"  "<<p->down->copies<<"  "<<" issued \nno. of copies left : "<<c->copies;
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
			    else if(c->copies==0)
			    cout<<"\n No copies left\n";
			    else if(c==NULL)
			    cout<<"Book not available\n";
			    else if(p->down!=NULL)
			    cout<<"You have already issued the book\n";
			       
}
void student::ret(book bk)
{
    int num;
    string id;
    snode *q=NULL;
    bnode*r=NULL;
    q=s;
    r=bk.sb;
    cout<<"enter roll no.";
    cin>>num;
    while(q->rno!=num)
    {
        q=q->next;
    }
    while(r->bkId!=q->down->bkId)
    {
        r=r->next;
    }
    if(r!=NULL&&q!=NULL&&q->down==r)
    {
        id=q->bId;
		r->copies++;
        q->down=NULL;
    
    int act_date,act_m,act_y;
    std::time_t isd = std::time(NULL);
			    std::tm due_tm = *std::localtime(&isd);
			    due_tm.tm_mday += 7;
			    std::time_t due = std::mktime(&due_tm);
     char str[100];
			    if (std::strftime(str, 100, "%d %m %y", std::localtime(&isd)))
			        std::cout << "issued on: " << str << '\n';
			       

			    if (std::strftime(str, 100, "%d %m %y", std::localtime(&due)))
			        std::cout << "due to: " << str << '\n';
			        
			      act_date = atoi(str);
			        date d2(act_date,0,0);
    cout<<"book returned : "<<r->bknam<<"\t book id : "<<r->bkId<<"\t copies : "<<r->copies;
    cout<<"\nenter current date";
    struct tm ret_tm;
    int dd,mm,yy, res;
    
    cin>>ret_tm.tm_mday>>ret_tm.tm_mon>>ret_tm.tm_year;
    if(!(dd>1 && dd<31))
    {
    	cout<<"Invalid date\n";
    	cout<<"Enter date: ";
    	cin>>ret_tm.tm_mday;
	}
	date d1(ret_tm.tm_mday,ret_tm.tm_mon,ret_tm.tm_year);
 	res=d1.diff(d1 , d2);
	cout<<"\n Fine is Rs."<<res*5;
}
else
cout<<"not issued";
}

int main()
{
	student st;
	book b;
	int c;
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
	do
	{
		cout<<"1. Issue\n";
		cout<<"2. Return\n";
		switch(c)
	{
		case 1: 
	st.issue(b);
	break;
	case 2:
	st.ret(b);
	break;
}
cout<<"Enter choice\n";
cin>>c;
	}while(c<3);

	return 0;
}

