#include<iostream>
using namespace std;

template<typename T>

void sort(T x[],int no)
{
	int min;
	for(int i=0;i<no-1;i++)
	{	min=i;
	for(int j=i+1;j<no;j++)
	{	
		if(x[min]>x[j])
		{
		min=j;
		}
	}
		swap(x[min],x[i]);
	}
	
}
template<typename T>
void swap(int &x,int &y)
{
	T temp;
	temp=x;
	x=y;
	x=temp;
}

int main()
{
	int *b;
	b = new int [10];
	float *a = new float [10];
	cout<<"Enter the no. of elements you wish to enter\n";
	int n;
	cin>>n;
	cout<<"Enter integers \n";
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	sort(b,n);
	cout<<"Sorted array \n";
	for(int i=0;i<n;i++)
	{
		cout<<b[i]<<"  ";
	}
	cout<<"Enter decimals\n";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,n);
	cout<<"Sorted array \n";
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<"  ";
	}

return 0;
}
