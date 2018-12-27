#include<iostream>
#include<bits/stdc++.h>
#include<ctime>
#include<fstream>
#define INVALID_DATE ((d.dd<1)||(d.dd>30)||\
					(d.mm>12)||(d.mm<1)||\
					(d.yy<17||d.yy>19))

using namespace std;

class date		//Calculate late fees
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
   int diff(date d1,date d2);

};

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
		void link();
		void showlink();
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
		void createlink();
		void displaylink();
	void issue(book);
	void ret(book);
	friend class book;
};

void book::link()			//runtime data stored in linked list
{
	cout<<"enter book name , book id , no. of copies \n";
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

void student::createlink()			//runtime data stored in linklist
{
	cout<<"Enter Student Roll No. and Name \n";
	snode *new1=NULL;
	if(s==NULL){
		s=new snode;
		cin>>s->rno>>s->name;
		s->next=NULL;
		l=s;
	}
	else
	{
		new1=new snode;
		cin>>new1->rno>>new1->name;
		l->next=new1;
		new1->next=NULL;
		l=new1;
	}
}

void book::showlink()		//displays linked list
{
	int sno=0;
	bnode *c;
	c=sb;
	cout<<"SNo \t\t Name \t\t ID \t NO. of Copies\n";
	while(c!=NULL)
	{
		sno++;
		cout<<sno<<"\t\t"<<c->bknam<<"\t\t\t"<<c->bkId<<"\t\t"<<c->copies<<"\n";
		c=c->next;
	}	
}


void student::displaylink()				//displays runtime formed linked list
{
	int sno=0;
	snode *c;
	c=s;
	cout<<"SNo \t\t Name \t\t Roll NO \n";
	while(c!=NULL)
	{
		sno++;
		cout<<sno<<"\t\t"<<c->name<<"\t\t"<<c->rno<<"\n";
		c=c->next;
	}	
}

void student::issue(book bk)		//ISSUING BOOK
{
	string bid;   //bid =book id no = rollno
	int no;
	cout<<"Enter student roll no. \n";
	cin>>no;
	
	bnode *c=NULL;
	snode *p=NULL;
	c=bk.sb;
	p=s;			//p pointer to student list
		while(p->rno!=no)
	{
		p=p->next;
	}
	 if(p==NULL)
		{
		cout<<"!! This roll no. does not exist !!\n";	
		}
		else
		{
	cout<<"Enter the book ID \n";  //c pointer to book list
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
	cout<<"Name: "<<p->name<<"  Roll no. "<<p->rno<<" BookId: "<<p->down->bkId<<" Book Name: "<<p->down->bknam<<"  "<<" issued \nCopies left : "<<c->copies<<"\n";
	std::time_t isd = std::time(NULL);
			    std::tm due_tm = *std::localtime(&isd);
			    due_tm.tm_mday += 7;
			    std::time_t due = std::mktime(&due_tm);
                char str[100];
			    if (std::strftime(str, 100, "%d %B %Y", std::localtime(&isd)))
			        std::cout << "Issued on: " << str << '\n';

			    if (std::strftime(str, 100, "%d %B %Y", std::localtime(&due)))
			        std::cout << "DUE ON: " << str << '\n';
			    
			}
			    else if(c->copies==0)
			    cout<<"\n!! No copies left !!\n";
			    else if(c==NULL)
			    cout<<"!! Book not available !!\n";
			    else if(p->down!=NULL)
			    cout<<"!! You have already issued the book !!\n";

}
void student::ret(book bk)		//RETURNING BOOK WITH LATE FEES
{
    int num;
    string id;
    snode *q=NULL;
    bnode*r=NULL;
    q=s;
    r=bk.sb;
    cout<<"Enter Roll No.";
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
			        std::cout << "Issued on: " << str << '\n';
			       

			    if (std::strftime(str, 100, "%d %m %y", std::localtime(&due)))
			        std::cout << "DUE ON: " << str << '\n';
			        
			      act_date = atoi(str);
			        date d2(act_date,0,0);
    cout<<"Book Returned : "<<r->bknam<<"\t Book ID : "<<r->bkId<<"\t Copies : "<<r->copies;
    cout<<"\nTODAY'S DATE : ";
    int res;
    struct ret_date
	{
	    int dd,mm,yy;	
	}d;
    
    cin>>d.dd>>d.mm>>d.yy;
    if(INVALID_DATE)
    {
    	cout<<"!!!!ENTER VALID DATE!!!!\n";
	}
	else
	{
	date d1(d.dd,d.mm,d.yy);
 	res=d1.diff(d1,d2);
	cout<<"\n Fine is Rs."<<res*5;
	}
}
else
cout<<"!!NOT ISSUED!!";
}

int main()
{
	student st;
	book b;
	int c,flag=0;
	char ch;
	do
	{
		cout<<"\n******ADMIN PAGE*******\n\n";
		cout<<"1. Create Student record\n";
		cout<<"2. Create book record\n";
		cout<<"3. Issue Book\n";
		cout<<"4. Return Book\n";
		cout<<"5. Exit\n";
		cout<<"Enter choice\n";
		cin>>c;
	switch(c)
	{
		case 3: 
		{
			st.issue(b);	
		}
	break;
	
	case 4:
	{
	st.ret(b);	
	}
	break;
	
	case 1:
		flag=1;
	do
	{
	st.createlink();
	cout<<"y/n \n";
	cin>>ch;
	
	}while(ch!='n');
	
	st.displaylink();
	break;
	
	case 2:
		flag=2;
	do
	{
	b.link();
	cout<<"y/n \n";
	cin>>ch;
	
	}while(ch!='n');
	
	b.showlink();
	break;
	}
			
		}while(c<5);

	return 0;
}

