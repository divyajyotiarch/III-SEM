/*
Author : Divyajyoti Ukirde
Roll No. 2179
Batch : H1
 */
 
#include<iostream>
#include<string.h>

using namespace std;

class database
{
	char name[20],address[50];
	int rno,j,d,m,y;
	long long int ph;
	public:
	struct subject
	{
		char sub[20];
		int code,internal,mks;	
	}stu[10];
		database()
		{
			j=0;
		}
	int insert();
	void output();
	friend class student;
};
static int maxSize=20;
class student
{ 
	int currentSize;
	database* list;

	public:
	student()				//default constructor
	{
	   currentSize=0;
	   list=new database[maxSize];
	}
	student(int x)	//parameterized constructor
	{
		x=currentSize;
	}
	~student()
	{
		delete list;
	}
	void input();
	void display();
};

inline void student::input()
{
    list[currentSize++].insert();   //reads new  entry
}

inline void student :: display()
{
    if(currentSize==0)
    {
        cout<<"Empty database \n";
    }
    else
    {
    for(int i=0;i<currentSize;i++)
	{
		list[i].output();
	}	
	}
}

int database::insert()
{
	char ch;
	cout<<"Enter Student's Name and Roll no. \n";
	cin.ignore();
	cin.getline(name,20);
	cin>>rno;
	cout<<"Enter DOB(dd/mm/yy): ";
	cin>>d>>m>>y;
	cout<<"Enter Address: \n";
	cin.ignore();
	cin.getline(address,50);
	cout<<"Enter Phone no. : \n";
	cin>>ph;
	while(ch!='n')
	{
	cout<<"Enter Subject and subject code \n";
	cin.ignore();
	cin.getline(stu[j].sub,20);
	cin>>stu[j].code;
	cout<<"Enter Internal marks out of 25 and University marks out of 50 \n";
	cin>>stu[j].internal>>stu[j].mks;	
	cout<<"Add more subjects? y/n  \n";
	cin>>ch;
	j++;
	}
	return(j);		
}

void database::output()
{	
	int i=0;
	cout<<"\n Student's Name: "<<name;
	cout<<"\n Roll no.: "<<rno;
	cout<<"\n DOB: "<<d<<"/"<<m<<"/"<<y;
	cout<<"\n Address: "<<address;
	cout<<"\n Phone no. "<<ph;
	while(i!=j)
    {
    cout<<"\n Subject: "<<stu[i].sub<<"\t Subject code: "<<stu[i].code;
	cout<<"\t Internal marks: "<<stu[i].internal<<"/25 \t University Marks: "<<stu[i].mks<<"/50"<<endl;
	i=i+1;	
	}	
}

int main()
{
	student s;
	int ch;
	do 
	{
		cout<<"1. Enter a new student database"<<endl;
		cout<<"2. Display the database"<<endl;
		cout<<"3. Exit"<<endl;
		cout<<"4. Enter choice: \n";
		switch(ch)
		{
			case 1: s.input();
			break;
			case 2: s.display();
			break;
		}
		cin>>ch;
	}while(ch!=3);
	
	return 0;
}

//OUTPUT
/*Student's Name: Divya
 Roll no.: 2179
 DOB: 5/4/98
 Address: pune dhankavdi3
 Phone no. 9098987898
 Subject: engg chem	 Subject code: 212	 Internal marks: 24/25 	 University Marks: 45/50

 Subject: engg maths	 Subject code: 234	 Internal marks: 23/25 	 University Marks: 43/50

 Student's Name: harry
 Roll no.: 2534
 DOB: 23/4/98
 Address: usa
 Phone no. 9098987867
 Subject: english	 Subject code: 333	 Internal marks: 23/25 	 University Marks: 34/50
*/
