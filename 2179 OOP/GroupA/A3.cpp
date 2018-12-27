/*
Author : Divyajyoti Ukirde
Roll No. 2179
Batch : H1
 */

#include<iostream>
#include<math.h>
using namespace std;

class quadratic
{
    int a,b,c;
   
    public:
    quadratic()
    {
    a=0;
    b=0;
    c=0;
    }
    public:
    void eval(quadratic &);
    void sol(quadratic &);
    quadratic operator +(quadratic);
    friend istream & operator>>(istream &, quadratic &);
    friend ostream & operator<<(ostream &, quadratic &);
};

quadratic quadratic::operator +(quadratic n1)
{
    quadratic n3;
    n3.a = this -> a+n1.a;
    n3.b = this -> b+n1.b;
    n3.c = this -> c+n1.c;
    return n3;
}

istream & operator >>(istream &input, quadratic &n)
{
    input>>n.a>>n.b>>n.c;
    return input;
}

ostream & operator <<(ostream &output, quadratic &n)
{
    if(n.a>0&&n.b>0&&n.c>0)
    output<<n.a<<"x^2 +"<<n.b<<"x +"<<n.c<<"=0"<<endl;
    else
    output<<n.a<<"x^2"<<n.b<<"x"<<n.c<<"=0"<<endl;
}

void quadratic::eval(quadratic &n)
{
    float e,x;
    cin>>x;
    e = n.a*pow(x,2)+n.b*x+n.c;
    cout<<e<<endl;
}

void quadratic::sol(quadratic &n)
{
float x1,x2,d,p;
d=pow(n.b,2);
p=pow(d-(4*n.a*n.c),0.5);
x1=(-n.b+p)/(2*a);
x2=(-n.b-p)/(2*a);
cout<<"x1="<<x1<<"  x2="<<x2<<endl;
}
int main()
{
    quadratic n1,n2,n3;
    cout<<"Enter the first quadratic equation"<<endl;
    cin>>n1;
    cout<<"Enter the second quadratic equation"<<endl;
    cin>>n2;
    n3=n1+n2;
    cout<<"Addition is \n"<<n3;
    cout<<"Evaluation final eq Enter value of x \n";
    n3.eval(n3);
    n3.sol(n3);
     return 0;
}

//OUTPUT
/*[pict@localhost GroupA]$ ./a.out
Enter the first quadratic equation
1
3
3
Enter the second quadratic equation
0
2
3
Addition is 
1x^2 +5x +6=0
Evaluation final eq Enter value of x 
1
12
x1=-2  x2=-3
*/
