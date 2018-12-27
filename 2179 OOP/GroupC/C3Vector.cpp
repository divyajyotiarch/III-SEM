#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;

class personal
{
	public:
		string name;
		long long int ph;
		void get()
		{
			cout<<"Enter name and ph\n";
			cin>>name>>ph;
		}
		void set()
		{
			cout<<name<<"  "<<ph<<endl;
		}
};

bool sortname(const personal &rhs,const personal &lhs)
{
	if(rhs.name<lhs.name)
		return true;
	
	return false;
}

int main()
{
	int n;
	vector<personal>v1;
	personal p;
	
	cout<<"No. of entries\n";
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		p.get();
		v1.push_back(p);
	}
	
	sort(v1.begin(),v1.end(),sortname);
	
	for(int i=0;i<n;i++)
	{
		v1[i].set();
	}
	
	vector<personal>::iterator it;
	vector<string>temp;
	vector<string>::iterator it1;
	string naam;
	cout<<"Enter name to be searched\n";
	cin>>naam;
	it=v1.begin();
	while(it!=v1.end())
	{
		temp.push_back((*it).name);
		it++;
	}
	
	it1 = temp.begin();
	it1 = find(temp.begin(),temp.end(),naam);
	if(it1!=temp.end())
	{
		int pos = it1-temp.begin();
		v1[pos].set();
	}
	else
	{
		cout<<"not found";
	}
}
