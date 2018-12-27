//quicksort
#include<iostream>

using namespace std;

class data
{
	int rno;
	float mks;
	public:
	friend class sort;
}d[80],temp;

class sort
{
	public:
		int n;
		int input();
		void quick_sort(int,int);
		void display();
		void display_top();
}s;

int sort::input()
{
	cout<<"Enter no. of entries \n";
	cin>>n;
	cout<<"Enter roll no. and percentages \n";
	for(int i=0;i<n;i++)
	{
		cin>>d[i].rno>>d[i].mks;
	}
	return n;
}

void sort::quick_sort(int l,int u)
{
	int i,j;
	float pivot;
	if(l>=u)
	{
		return;
	}
	else
	{
		pivot=d[l].mks;
		i=l+1;
		j=u;
	}
	
	do
	{
		while(d[i].mks < pivot && i<=u)
		{
			i=i+1;
		}
		while(d[j].mks > pivot && j>=l)
		{
			j=j-1;
		}
		if(i<j)
		{
			temp=d[i];
			d[i]=d[j];
			d[j]=temp;
			i=i+1;
			j=j-1;
		}
	}while(i<j);
	
		temp=d[l];
		d[l]=d[j];
		d[j]=temp;
		
		s.quick_sort(l,j-1);
		s.quick_sort(j+1,u);
}

void sort::display()
{
	cout<<"Roll No. \t\t"<<"Marks\n";
	for(int i=0;i<n;i++)
	{
		cout<<d[i].rno<<"\t\t\t"<<d[i].mks<<"\n";
	}
}

void sort::display_top()
{
	cout<<"Top 5 are \n";
	cout<<"Roll No. \t\t"<<"Marks\n";
	for(int i=n-1;i>=n-5;i--)
	{
		cout<<d[i].rno<<"\t\t\t"<<d[i].mks<<"\n";
	}
}

int main()
{
	s.input();
	cout<<s.n<<"\n";
	s.quick_sort(0,s.n-1);
	s.display();
	s.display_top();
	return 0;
	
}
