#include<iostream>
#include<stack>

using namespace std;

int main()
{
	char ch;
	stack<int>s1,s2,s3;
	char bit[100];
	int carry=0,sum;
	cout<<"first binary no. \n";
	cin>>bit;
	for(int i=0;bit[i]!='\0';i++)
	{
		if(bit[i]=='0')
		s1.push(0);
		else if(bit[i]=='1')
		s1.push(1);
		else
		{
			cout<<"Not a binary number.\n";
		}
	}
	cout<<"second binary no. \n";
	cin>>bit;
	for(int i=0;bit[i]!='\0';i++)
	{
		if(bit[i]=='0')
		s2.push(0);
		else if(bit[i]=='1')
		s2.push(1);
		else
		{
			cout<<"Not a binary number.\n";
		}
	}
	
			stack<int>c1;
	
	if(s1.size()>s2.size())
	{
		int diff = s1.size() - s2.size();
		while(!s2.empty())
		{
			c1.push(s2.top());
			s2.pop();
		}
		for(int i=0;i<diff;i++)
		{
			s2.push(0);
		}
		while(!c1.empty())
		{
			s2.push(c1.top());
			c1.pop();
		}
	}
	else if(s1.size()<s2.size())
	{
		int diff = s2.size() - s1.size();
		while(!s1.empty())
		{
			c1.push(s1.top());
			s1.pop();
		}
		for(int i=0;i<diff;i++)
		{
			s1.push(0);
		}
		while(!c1.empty())
		{
			s1.push(c1.top());
			c1.pop();
		}
	}
	
	while(!s1.empty() && !s2.empty())
	{
		sum = (s1.top()+s2.top()+carry)%2;
		carry = (s1.top()+s2.top()+carry)/2;
		s3.push(sum);
		s1.pop(); s2.pop();
	}
	if(carry==1)
	{
			s3.push(carry);
	}
	cout<<"Sum is \n";
	while(!s3.empty())
	{
		cout<<s3.top()<<" ";
		s3.pop();
	}
	return 0;
}
