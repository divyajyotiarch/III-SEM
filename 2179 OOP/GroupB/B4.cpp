#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string.h>
#include<iomanip>

using namespace std;

void create();
void add();
void display();
void DisplayP();
void modify();
void del();

class directory
{
		char name[20];
		long long ph;
	public:
		void getdata()
		{
			cout<<"Enter name and phone no. \n";
			cin>>name>>ph;
		}
		void show()
		{
			cout<<setw(10)<<name<<setw(5)<<ph<<"\n";
		}
		char *modifyPh()
		{
			return name;
		}
		long long int modifyN()
		{
			return ph;	
		}
}s;

fstream file,temp;
int main()
{
	int c;
	do
	{
		cout<<"1. Create\n";
		cout<<"2. Add \n";
		cout<<"3. Display\n";
		cout<<"4. Modify\n";
		cout<<"5. Delete \n";
		cout<<"6. Search \n";
		cout<<"Enter choice:\n";
		cin>>c;
		switch(c)
		{
		case 1:	create();
		break;
		case 2:	add();
		break;
		case 3:	display();
		break;
		case 4:	modify();
		break;
		case 5: del();
		break;
		case 6: DisplayP();
		break;
		}
		
	}while(c<7);

return 0;	
}

void create()
{
	char ch='y';
	file.open("Directory.txt", ios::out | ios::binary);
	if(file.is_open())
	{
		while(ch=='y'||ch=='Y')
		{
			s.getdata();
			file.write((char*)&s,sizeof(s));
			cout<<"Want to continue? y/n \n";
			cin>>ch;
		}
		file.close();
	}	
}
void add()              //Function to Add New Record in Data File
{
	char ch='y';
	file.open("Directory.txt", ios::app|ios::in|ios::binary|ios::out);
	while(ch=='y' || ch =='Y')
	{
		s.getdata();
		file.write((char*)&s, sizeof(s));
		cout<<"Want to Continue? y/n \n";
		cin>>ch;
	}
	file.read((char*)&s, sizeof(s));
	file.close();
}

void display()		//Function to Display All Record from Data File
{
	file.open("Directory.txt",ios::in| ios::binary);
	if(!file)
	{
		cout<<"File not Found \n";

	}
	else
	{
		file.read((char*)&s, sizeof(s));
		while(!file.eof())
		{
			s.show();
			file.read((char*)&s, sizeof(s));
		}
	}
	file.close();
}

void DisplayP()		//Function to Display particular Record from Data File
{
	int c;
	char nam[10];
	long long int p;
	file.open("Directory.txt",ios::in | ios::binary);
	if(!file)
	{
		cout<<"File not Found";
	}
	else
	{
		do
		{
		cout<<"1. Search by name\n";
		cout<<"2. Search by phone no. \n";
		cout<<"3. Exit to main menu \n";
		cin>>c;
		switch(c)
		{
			case 1: 
			{
				file.seekg(0,ios::beg);
					cout<<"Enter Name that should be searched:";
					cin>>nam;
				file.read((char*)&s, sizeof(s));
		while(!file.eof())
		{
			if(strcmp(nam,s.modifyPh())==0)
			{
				s.show();
				break;
			}
			file.read((char*)&s, sizeof(s));
		}
		}
		break;
		
		case 2: 
		{
			file.seekg(0,ios::beg);
				cout<<"Enter phone no. to search \n";
				cin>>p;
				file.read((char*)&s, sizeof(s));
		while(!file.eof())
		{
			if(s.modifyN()==p)
			{
				s.show();
				break;
			}
			file.read((char*)&s, sizeof(s));
		}
		}
		break;
		
	}
		
		}while(c!=3);
	}
	file.close();
}

void modify()		//Function to Modify Particular Record from Data File
{
	char nam[20];
	cout<<"Enter Name that should be searched:";
	cin>>nam;
	file.open("Directory.txt",ios::in| ios::out|ios::binary);
	if(!file)
	{
		cout<<"File not Found";
	}
	else
	{
		int i=0;
		file.read((char*)&s, sizeof(s));
		while(!file.eof())
		{
			if(strcmp(nam,s.modifyPh())==0)
			{
				file.seekg(0,ios::cur);
				cout<<"Enter New Record.."<<endl;
				s.getdata();
				file.seekg( (i*sizeof(s)), ios::beg);
			//	file.seekp(file.tellg() - sizeof(s));
				file.write((char*)&s, sizeof(s));
				break;
			}
			i++;
			file.read((char*)&s, sizeof(s));
		}
	}
	file.close();
}

 
void del()		//Function to Delete Particular Record from Data File
{
	char nam[10];
	cout<<"Enter Name that should be Deleted :";
	cin>>nam;
	file.open("Directory.txt",ios::out | ios::in | ios::binary);
	file.seekg(0);
	temp.open("temp1.txt",ios::out|ios::binary);
	if(file)
	{
		file.read((char*)&s, sizeof(s));
		while(!file.eof())
		{
			if(strcmp(nam,s.modifyPh())!=0)
			{
				temp.write((char*)&s, sizeof(s));
			}
			file.read((char*)&s, sizeof(s));
		}
	}
	else
	{
		cout<<"not found \n";
	}
	temp.close();
	file.close();
	remove("Directory.txt");
	rename("temp1.txt", "Directory.txt");
}
