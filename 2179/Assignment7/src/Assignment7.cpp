/*Write a c++ program using stack to check whether given expression is well parenthesized or not*/
#include <iostream>
#include<string.h>
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
    char E[20];
    int no;
public:
bool Brackets(char,char);
    void input();
    bool check();
}e;
bool expression::Brackets(char opening, char closing)
{
if( opening == '(' && closing == ')' ) return true;
else if ( opening == '[' && closing == ']' ) return true;
else if ( opening == '{' && closing == '}' ) return true;
return false;
}
void expression::input()
{
    cout<<"Enter expression \n";
    cin>>E;
    e.no=strlen(E);
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
bool expression::check()
{
    for(int i=0;i<e.no;i++)
    {
			if(E[i]=='('||E[i]=='['||E[i]=='{')
		   {
			   s.push(E[i]);
		   }
		   else if( E[i] == ')' || E[i] == '}' || E[i] == ']' )
		{
		if(!Brackets( s.st[s.top], E[i] ) )
		{
		return false;
		}
		else
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
    e.input();
    e.check();
    s.display();
    return 0;
}
