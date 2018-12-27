#include <iostream>

using namespace std;

class matrix
{
int m,n;
    int a[10][10];
public:
    void getdata();
    void upperTriangle();
    void trace();
    void transpose();
    void add(matrix d1,matrix d2);
    void sub(matrix d1,matrix d2);
    void multiply(matrix d1,matrix d2);
    void saddle();
    void display();
};

void matrix::getdata()
{   int i=1,j=1;

    cin>>m>>n;

cout<<"enter matrix\n";
for(i=1;i<=m;i++)
{
for (j=1;j<=n;j++)
    cin>>a[i][j];
}
}

void matrix::upperTriangle()
{int flag=0,j,i;
for(i=1;i<=m;i++)
{
    for(j=i-1;j>=1;j--)
{

    if (a[i][j]!=0)
        flag=1;
    else break;

}
}
if (flag==1)
{
cout<<" not upper triangular\n";
}
else
cout<<" upper triangular\n";

}
void matrix::trace()
{   int i=1,t=0;
    for(i=1;i<=m;i++)
    {
    t=t+a[i][i];
    }
cout<<t;
}
void matrix::transpose()
{
    int i=1,j=1,temp;

for(i=1;i<=n;i++)
{
    for(j=1;j<=m;j++)
    {

        cout<<a[j][i]<<"\t";
    }
}
}
void matrix::add(matrix d1,matrix d2)
{  m=d1.m;
   n=d1.n;
    int i=1,j=1;
    for(i=1;i<=m;i++)
    {
        for (j=1;j<=n;j++)
        {
            a[i][j]=d1.a[i][j]+d2.a[i][j];
        }
    }
}
void matrix::sub(matrix d1,matrix d2)
{m=d1.m;
n=d1.n;
    int i=1,j=1;
    for(i=1;i<=m;i++)
    {
        for (j=1;j<=n;j++)
        {
            a[i][j]=d1.a[i][j]-d2.a[i][j];
        }
    }
}
void matrix::multiply(matrix d1,matrix d2)
{m=d1.m;
n=d1.n;
for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
        	{a[i][j]=0;
            for(int k = 1; k <= j;k++)
            {
                a[i][j] = a[i][j] + d1.a[i][k] * d2.a[k][j];
            }}
}
void matrix::saddle()
{int i;
int flag=0,sp,pos;
for(int i=1;i<=m;i++)
{
sp=a[i][1],pos=1;
for(int j=1;j<=n;j++)
{
if(a[i][j]<sp)
{ sp=a[i][j];
  pos=j;
}
else if (a[i][j]==sp)
{
	sp=a[i][j];

}
}

for(int k=1;k<=m;k++)
{
 if(a[k][pos]>sp)
 {
 flag=1;
 }
}
}
if(flag==1)
cout<<" "<<sp<<endl;
}

void matrix::display()
{
for(int i=1;i<=m;i++)
{
for(int j=1;j<=n;j++)
{
cout<<a[i][j]<<"\t";
}
}
}
int main()
{
matrix m1,m2,m3,m4,m5;
    cout<<"Enter the no. of rows and columns for m1";
    m1.getdata();
    cout<<"Enter the no. of rows and columns for m2";
    m2.getdata();

    cout<<"m1";
    m1.upperTriangle();
    cout<<"m2";
    m2.upperTriangle();

    cout<<"\n trace of m1=";
    m1.trace();
    cout<<"\n transpose of m1=";
    m1.transpose();
    cout<<"\n trace of m2=";
    m2.trace();
    cout<<"\n transpose of m2=";
    m2.transpose();

    cout<<"\nSaddle pt. of m1=";
    m1.saddle();
    cout<<"\nSaddle pt. of m2=";
    m2.saddle();

    cout<<"addition"<<endl;
    m3.add(m1,m2);
    m3.display();
    cout<<"\n subtraction"<<endl;
    m4.sub(m1,m2);
    m4.display();
    cout<<"\n multiplication"<<endl;
    m5.multiply(m1,m2);
    m5.display();

    return 0;
}
