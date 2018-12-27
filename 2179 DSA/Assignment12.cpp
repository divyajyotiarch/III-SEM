/*
 ============================================================================
 Name        : Assignment12A.cpp
 Author      : OS
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C++,
 ============================================================================
 */
//insert sort and shell sort
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
	void insert_sort();
	void shell_sort();
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

void sort::insert_sort()
{
	float temp;
	char tempn[10];
	int i, j;
   for (i = 1; i < 10; i++)
   {
       temp = d[i].mks;
       strcpy(tempn,d[i].name);
       j = i-1;
       /* Move elements of arr[0..i-1], that are
          greater than temp, to one position ahead
          of their current position */
       while (j >= 0 && d[j].mks > temp)
       {
           d[j+1].mks = d[j].mks;
           strcpy(d[j+1].name,d[j].name);
           j = j-1;
       }
       d[j+1].mks = temp;
       strcpy(d[j+1].name,tempn);
   }
}

void sort::shell_sort()
{
	int step,i,j;
	float temp;
	char tempn[10];
	for(step=10/2;step>0;step=step/2)
	{
		for(i=step;i<10;i++)
		{
			temp=d[i].mks;
			strcpy(tempn, d[i].name);
			for(j=i;j>=step && d[j-step].mks > temp ;j=j-step)
			{
					d[j].mks=d[j-step].mks;
					strcpy(d[j].name,d[j-step].name);
			}
				d[j].mks=temp;
				strcpy(d[j].name,tempn);
		}
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
		cout<<"2. Insertion sort \n";
		cout<<"3. Shell sort \n";
		cout<<"4. Display list \n";
		cout<<"5. Display toppers \n";
		cout<<"6. Exit \n";
		cin>>c;
		switch(c)
		{
		case 1:   s.input();
					s.display();
			break;
		case 2:		s.insert_sort();
			break;
		case 3:		s.shell_sort();
			break;
		case 4:		s.display();
			break;
		case 5:		s.display_5();
			break;
		}

	}while(c<6);
	return 0;
}
