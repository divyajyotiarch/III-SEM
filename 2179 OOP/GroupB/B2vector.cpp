#include<iostream>
#include<string>
#include<vector>
using namespace std;

template<class T>
class tsort
{
	vector<T>v1;
	public:
		void getdata();
		void select_sort();
		void display();
};

template<class T>void tsort<T>::getdata()
{
	int n;
	T x;
	cout<<"Enter no. of elements you want to enter\n";
	cin>>n;
	cout<<"Elements:";
	for(int i=0;i<n;i++)
	{
		cin>>x;
		v1.push_back(x);	
	}
}

template<class T>void tsort<T>::select_sort()
{
	int min;
	T temp;
	for(int i=0;i<v1.size()-1;i++)
	{	min=i;
	for(int j=i+1;j<v1.size();j++)
	{	
		if(v1.at(min)>v1.at(j))
		{
		min=j;
		}
	}
		//swap(&min, &x[i]);
		temp=v1.at(min);
		v1.at(min)=v1.at(i);
		v1.at(i)=temp;
	}
}

template<class T>void tsort<T>::display()
{
	for(int i=0;i<v1.size();i++)
	{
		cout<<v1.at(i)<<" ";
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
