#include<iostream>
using namespace std;
class node
{
char ch;
int n,n1;
node *next;
node *prev;
public:
    friend class cinemax;
};
class cinemax
{
int b[10];
node *a[10],*s;
public:
cinemax()
{
s=NULL;
for(int i=0;i<10;i++)
{
a[i]=NULL;
b[i]=0;
}
}
void create();
void create_booked();
void avail();
void book();
void cancel();
void display();
};
void cinemax::create()
{
node *new2=NULL,*c=NULL;
int ln=0,m;
for(int i=0;i<10;i++)
{
node *new1=NULL;
if(a[i]==NULL)
{
new2=new node;
a[i]=new2;
new2->ch='A';
new2->n=ln;
new2->n1=1;
new2->next=new2;
new2->prev=NULL;
}
int m=2;
for(int k=0;k<6;k++)
{
if(new1==NULL)
{
new1=new node;
c=new1;
new1->ch='A';
new1->n=ln;
new1->n1=m;
a[i]->next=new1;
new1->prev=a[i];
new1->next=a[i];
m++;
}
else
{
new1=new node;
new1->ch='A';
new1->n=ln;
new1->n1=m;
c->next=new1;
new1->prev=c;
c=new1;
c->next=new2;
m++;
}
}
ln++;
}
}
void cinemax::create_booked()
{
    int count;
    node *ab=NULL;          //ab=already booked
    for(int i=5;i<9;i++)
    {
        ab=a[i];
        for(int j=0;j<4;j++)
        {
            ab->ch='U';
            ab=ab->next;
        }
    }
    for(int i=2;i<6;i++)
    {
        ab=a[i];
        while(ab->n1!=5)
        {
            ab=ab->next;
        }
        for(int j=4;j<6;j++)
                    {
                        ab->ch='U';
                        ab=ab->next;
                    }
    }
    for(int i=0;i<2;i++)
    {
        ab=a[i];
            for(int j=0;j<6;j++)
            {
                ab->ch='U';
                ab=ab->next;
            }
    }
    ab=a[9];
        for(int j=0;j<7;j++)
        {
            ab->ch='U';
            ab=ab->next;
        }
}
void cinemax::avail()
{
    int count;
    node *as=NULL;      //as=available seats
    cout<<"Number of seats available in a row: \n";
    for(int i=0;i<10;i++)
    {
        as=a[i];
        count=0;
        for(int j=0;j<7;j++)
        {
            if(as->ch=='A')
        {
            count++;
        }
            as=as->next;
        }
        b[i]=count;
    }
    for(int k=0;k<10;k++)
    {
        cout<<"Row "<<k<<" = "<<b[k]<<" Available \n";
    }
}
void cinemax::book()
{
int no,t[7],u[7],r;    //t=tens place u=units place
char ny;
node *sb=NULL;
cout<<"Enter the no. of seats to be booked \n";
cin>>no;
cout<<"Enter the row number(0 to 9) \n";
cin>>r;
if(no>4)
{
cout<<"No consecutive seats available.\nDo you wish to book in different rows? y/n \n";
cin>>ny;
if(ny=='y')
{
for(int i=0;i<no;i++)
    {
        sb=a[i];
        while(sb->n1!=7)
        {
            sb=sb->next;
        }
        sb->ch='B';
    }
}
}
else
{
cout<<"Enter the seat no.s if Available(A) e.g for seat A-01, type digit(space)digit \n";
for(int k=0;k<no;k++)
{
cin>>t[k]>>u[k];
}
for(int k=0;k<no;k++)
{
for(int i=0;i<10;i++)
{
sb=a[i];
if(t[k]==sb->n)
{
for(int j=0;j<7;j++)
{
if(u[k]==sb->n1)
{
if(sb->ch=='U')
{
cout<<"Seat no.s: "<<sb->ch<<"-"<<t[k]<<u[k]<<" ";
cout<<"Unavailable \n";
}
else
{
sb->ch='U';
cout<<"Seat no.s: "<<sb->ch<<"-"<<t[k]<<u[k]<<"\n";
}
}
sb=sb->next;
}
}
}
}
cout<<"Successfully booked \n";
}
}
void cinemax::cancel()
{
int no,t[7],u[7];    //t=tens place u=units place
node *sc=NULL;
cout<<"Enter the no. of seats to be canceled \n";
cin>>no;
cout<<"Enter the seat no.s if Unavailable(U) e.g for seat A-01, type digit(space)digit \n";
for(int k=0;k<no;k++)
{
cin>>t[k]>>u[k];
}
for(int k=0;k<no;k++)
{
for(int i=0;i<10;i++)
{
sc=a[i];
if(t[k]==sc->n)
{
for(int j=0;j<7;j++)
{
if(u[k]==sc->n1)
{
if(sc->ch=='A')
{
cout<<"Seat no.s: "<<sc->ch<<"-"<<t[k]<<u[k]<<" ";
cout<<"Already Available : Cannot be canceled \n";
}
else
{
sc->ch='A';
cout<<"Seat no.s: "<<sc->ch<<"-"<<t[k]<<u[k]<<"\n";
}
}
sc=sc->next;
}
}
}
}
cout<<"Successfully canceled \n";
}
void cinemax::display()
{
node *cs=NULL;
for(int i=0;i<10;i++)
{
cs=a[i];
for(int j=0;j<7;j++)
{
cout<<cs->ch<<"-"<<cs->n<<cs->n1<<"  ";
cs=cs->next;
}
cout<<"\n";
}
}
int main()
{
int choice;
cinemax c;
c.create();
c.create_booked();
c.display();
c.avail();
do
{
cout<<"1. Book Seats \n";
cout<<"2. Cancel booking \n";
cout<<"3. Exit \n";
cout<<"Enter choice \n";
cin>>choice;
switch(choice)
{
case 1: c.book();
c.display();
break;
case 2: c.cancel();
c.display();
break;
}
}while(choice!=3);
return 0;
}
