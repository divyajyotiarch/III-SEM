/*
 ============================================================================
 Name        : Assignment.cpp
 Author      : OS
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C++,
 ============================================================================
 */
/*Write a c++ program using stack to check whether given expression is well parenthesized or not*/
#include <iostream>

using namespace std;

class stack
{
	char st[20];
	int top;
public:
	stack()
	{
		top=-1;
	}
	void pop();
	void push(char);
	void display();
	friend class expression;
}s;

class expression
{
	char E[20],e;
public:
	void input(int);
	void check(int);
};

void expression::input(int no)
{
	cout<<"Enter expression \n";
	for(int i=0;i<no;i++)
	{
		cin>>E[i];
	}
/*	for(int j=0;j<n;j++)
	{
		if(e=='('||e==')'||e=='['||e==']'||e=='{'||e=='}')
		{
			count++;
		}
	}*/
	for(int i=0;i<no;i++)
		{
			cout<<E[i];
		}
}
void stack::push(char x)
{
    if(top>19)
	{
		cout<<"stack overflow \n";
		return;
	}
    	st[++top]=x;
}

void stack::pop()
{
	if(top==-1)
	{
		cout<<"stack underflow \n";
		return;
	}
	st[top--];
}

void expression::check(int x)
{
	for(int i=0;i<x;i++)
	{
	if(E[i]=='('||E[i]==')')
	{
		s.push(E[i]);
	}
	else if(E[i]=='('||E[i]==')')
	{
		s.pop();
	}
	if(E[i]=='['||E[i]==']')
	{
		s.push(E[i]);
	}
	else if(E[i]=='['||E[i]==']')
	{
		s.pop();
	}
	if(E[i]=='{'||E[i]=='}')
	{
		s.push(E[i]);
	}
	else if(E[i]=='{'||E[i]=='}')
	{
		s.pop();
	}
	}
}
void stack::display()
{
	if(top==-1)
		{
			cout<<"Expression is valid";
		}
		else
		{
			cout<<"Expression is invalid";
		}
}

int main()
{
	expression e;
	int n;
	cout<<"No. of terms in your expression \n";
	cin>>n;
	e.input(n);
	e.check(n);
	s.display();
	return 0;
}

