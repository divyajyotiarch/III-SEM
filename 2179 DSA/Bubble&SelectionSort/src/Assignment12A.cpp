/*
 ============================================================================
 Name        : Assignment12A.cpp
 Author      : OS
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C++,
 ============================================================================
 */
//Bubble sort and selection sort
#include <iostream>
#include<string.h>

using namespace std;

struct data
{
	char name[10];
	float mks;
}d[10];
class sort
{
public:
	void input();
	void buble_sort();
	void select_sort();
	void display();
	void display_5();
};

void sort::input()
{
	cout<<"Enter 10 names and SGPA of students \n";
	for(int i=0;i<10;i++)
	{
		cin>>d[i].name>>d[i].mks;
	}
}

void sort::buble_sort()
{
	float temp;
	char tempn[10];
	for(int i=1;i<=9;i++)
	{
		for(int j=0;j<10-i;j++)
		{
			if(d[j].mks > d[j+1].mks)
			{
				temp=d[j].mks;
				d[j].mks=d[j+1].mks;
				d[j+1].mks=temp;

				strcpy(tempn, d[j].name);
				strcpy(d[j].name,d[j+1].name);
				strcpy(d[j+1].name,tempn);

			}
		}
	}
}

void sort::select_sort()
{
	int min;
	float temp;
	char tempn[10];
	for(int i=0;i<10;i++)
	{
		min=i;
		for(int j=i+1;j<10;j++)
		{
			if(d[min].mks > d[j].mks)
			{
				min=j;
			}
		}
		temp=d[i].mks;
		d[i].mks=d[min].mks;
		d[min].mks=temp;

		strcpy(tempn, d[i].name);
		strcpy(d[i].name,d[min].name);
		strcpy(d[min].name,tempn);
	}

}


void sort::display()
{
	for(int i=0;i<10;i++)
	{
		cout<<d[i].name<<"  "<<d[i].mks<<"\n";
	}
}

void sort::display_5()
{
	cout<<"Top 5 \n";
	for(int i=9;i>=5;i--)
		{
			cout<<d[i].name<<"  "<<d[i].mks<<"\n";
		}
}

int main()
{
	sort s;
	int c;
	do
	{
		cout<<"1. Input \n";
		cout<<"2. bubble sort \n";
		cout<<"3. selection sort \n";
		cout<<"4. Display list \n";
		cout<<"5. Display toppers \n";
		cout<<"6. Exit \n";
		cin>>c;
		switch(c)
		{
		case 1:   s.input();
					s.display();
			break;
		case 2:		s.buble_sort();
			break;
		case 3:		s.select_sort();
			break;
		case 4:		s.display();
			break;
		case 5:		s.display_5();
			break;
		}

	}while(c<6);
	return 0;
}
