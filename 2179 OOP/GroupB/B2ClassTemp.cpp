#include<iostream>
#include<string.h>
using namespace std;

template<class T>
class tsort
{
	T *x,n;
	public:
		tsort()
		{
			x = new T [10];
		}
		void getdata();
		void select_sort();
		void display();
};

template<class T>void tsort<T>::getdata()
{
	cout<<"Enter no. of elements you want to enter\n";
	cin>>n;
	cout<<"Elements:";
	for(int i=0;i<n;i++)
	{
		cin>>x[i];	
	}
}

template<class T>void tsort<T>::select_sort()
{
	int min;
	T temp;
	for(int i=0;i<n-1;i++)
	{	min=i;
	for(int j=i+1;j<n;j++)
	{	
		if(x[min]>x[j])
		{
		min=j;
		}
	}
		//swap(&min, &x[i]);
		temp=x[min];
		x[min]=x[i];
		x[i]=temp;
	}
}

template<class T>void tsort<T>::display()
{
	for(int i=0;i<n;i++)
	{
		cout<<x[i]<<" ";
	}
	cout<<"\n";
}

int main()
{
	tsort<int>a;
	tsort<float>b;
	
	cout<<"Integers\n";
	a.getdata();
	a.select_sort();
	a.display();
	
	cout<<"Float numbers\n";
	b.getdata();
	b.select_sort();
	b.display();
	
	return 0;
}
