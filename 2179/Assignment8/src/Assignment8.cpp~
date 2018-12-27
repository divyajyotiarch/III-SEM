//Conversion of infix to post-fix, use atoi and isdigit
#include <iostream>
#include<string>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
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
    void insert(int);
    void pop();
    int precede(char);
    friend class expression;
}s;
class expression
{
    string E,F;
public:
    expression()
    {
        E = " ";
        F = " ";
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
    else
        {
        st[++top]=x;
        }
}
void stack::insert(int z)
{
    if(top>19)
    {
        cout<<"Stack overflow \n";
    }
    else
        {
        st[++top]=z;
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
    if(y=='-')
    {
        return 1;
    }
    else if(y=='+')
    {
        return 1;
    }
    else if(y=='*')
    {
        return 2;
    }
    else if(y=='/')
    {
        return 3;
    }
    else if(y=='^')
    {
    return 4;
}
    else
    {
        return -1;
    }
}
void expression::input()
{
    cout<<"Enter infix expression \n";
    cin>>E;
    E = E + '}';
}
void expression::convert()
{
    int i=0;
    s.push('{');
    while(E[i]!='}')
    {
        if(isdigit(E[i]))
        {
            F = F + E[i];
        }
        else
        {
        if(E[i]=='(')
        {
        s.push(E[i]);
}
else
{
if(E[i]==')')
{
while(s.st[s.top]!='(')
{
F=F + s.st[s.top];
s.pop();
}
s.pop();
}
else
{
while(s.precede(E[i]) <= s.precede(s.st[s.top]))
{
F = F + s.st[s.top];
s.pop();
}
s.push(E[i]);
}
}
        }
        i=i+1;
    }
    while(s.st[s.top]!='{')
    {
  F = F + s.st[s.top];
   s.pop();
}
        cout<<"\n"<<F;
}
void expression::eval()
{
int k=0,j=0,ix,x;
F = F + '}';
while(F[k]!='}')
{
if(isdigit(F[k]))
{
   ix = F[k] - '0';
s.insert(ix);
}
else
{
if(F[k]=='+')
{
s.st[s.top-1]=s.st[s.top-1] + s.st[s.top];
}
else if(F[k]=='-')
{
s.st[s.top-1]=s.st[s.top-1] - s.st[s.top];
}
else if(F[k]=='*')
{
s.st[s.top-1]=s.st[s.top-1] * s.st[s.top];
}
else if(F[k]=='/')
{
s.st[s.top-1]=s.st[s.top-1] / s.st[s.top];
}
else if(F[k]=='^')
{
s.st[s.top-1]=pow(s.st[s.top-1] , s.st[s.top]);
}
x=s.st[s.top-1];
s.pop();
}
k=k+1;
}
cout<<"\nAns: "<<x;
}
int main()
{
    int ch;
    e.input();
    e.convert();
    e.eval();
    return 0;
}
