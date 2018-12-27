/*
 ============================================================================
 Name        : Assignment8.cpp
 Author      : OS
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C++,
 ============================================================================
 */
//Conversion of infix to post-fix, use atoi and isdigit
#include <iostream>
#include<string>
#include<stdlib.h>
#include<ctype.h>
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
	void push(char);
	void pop();
	int precede(char);
	friend class expression;
}s;

class expression
{
	string E;
public:
	expression()
	{
		E = " ";
	}
	void input();
	void convert();
	void eval();
	void display();
}e;

void stack::push(char x)
{
	if(top>19)
	{
		cout<<"Stack overflow \n";
	}
	else if(top==-1)
	{
		st[++top]='{';
	}
	else
		{
		st[++top]=x;
		}
}

void stack::pop()
{
	if(top==-1)
	{
		cout<<"stack underflow \n";
	}
	else
		{
		top--;
		}
}

int stack::precede(char y)
{
	int a;

	if(y=='-')
	{
		a=1;
	}
	else if(y=='+')
	{
		a=1;
	}
	else if(y=='*')
	{
		a=2;
	}
	else if(y=='/')
	{
		a=3;
	}
	else if(y=='('||y==')'||y=='{')
	{
		a=-1;
	}
	return a;
}

void expression::input()
{
	cout<<"Enter infix expression \n";
	cin>>E;
	E = E + '}';
	cout<<E;
}

void expression::convert()
{
	int i=0;
	string F;
	while(E[i]!='}')
	{
		if(isdigit(E[i]))
		{
			F = F + E[i];
		}
		else
		{
			while(s.precede(s.st[s.top]) >= s.precede(E[i]) && s.st[s.top]!='{')
			{
				F = F+s.st[s.top];
				s.pop();
				s.push(E[i]);
			}
			s.push(E[i]);
		}
		i++;
	}
	cout<<F;
}






int main()
{
	int ch;
	e.input();
	e.convert();
	return 0;
}

