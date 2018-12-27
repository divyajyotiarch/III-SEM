#include<iostream>
using namespace std;
class polynomial
{
   int i,m,n[20];
public:
   void getdata();
   void sum1(polynomial,polynomial);
   void mul(polynomial,polynomial);
   void eva();
};
void polynomial::getdata()
{
	cout<<"Enter the degree of polynomial";
	cin>>m;
	cout<<"Enter coefficients";
	for(i=m;i>=0;i--)
		cin>>n[i];
	for(i=m;i>0;i--)
		cout<<n[i]<<"x^"<<i<<"+";
        cout<<n[0]<<endl;
	}
void polynomial::sum1(polynomial n1,polynomial n2)
{
	int k;
	polynomial n3;
	if(n1.m>=n2.m)
	{
    k=n1.m;
    }
	else
	{
	k=n2.m;
	}
for(i=k;i>=0;i--)
	n3.n[i]=n1.n[i]+n2.n[i];
cout<<"sum=";
for(i=k;i>0;i--)
cout<<n3.n[i]<<"x^"<<i<<"+";
cout<<n3.n[0];
}
void polynomial::mul(polynomial n1,polynomial n2)
{

}
void polynomial::eva()
{

}
int main()
{
	polynomial x,y,z,w;
	x.getdata();
	y.getdata();
	z.sum1(x,y);
	//w.mul(x,y);

	return 0;
}

