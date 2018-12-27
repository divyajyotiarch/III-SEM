#include<iostream>
using namespace std;

class term
{
	int m[10][10],r,c,v;
	public:
		term()
		{
			r=0;c=0;v=0;
		}
	friend class sparse;	
};

class sparse
{
	term a[10],m1;
	int tc,tr,tv;
	public:
		sparse()
		{
			tc=0;tv=0;tr=0;
		}
		void input();
		void convert();
		void displaysparse();
		void display();
		void simpletranspose(sparse);
		void transpose(sparse);
		void addition(sparse,sparse);
};

void sparse::input()
{
	int val;
	cout<<"No. of rows\n";
	cin>>m1.r;
	cout<<"No. of columns\n";
	cin>>m1.c;
	cout<<"Enter elements in matrix\n";
	for(int i=0;i<m1.r;i++)
	{
		for(int j=0;j<m1.c;j++)
		{
			cin>>val;
			if(val!=0)
			{
				tv++;
			}
			m1.m[i][j]=val;
		}
	}
	tr=m1.r;
	tc=m1.c;
}

void sparse::displaysparse()
{
	cout<<"Sparse matrix\n";
	for(int i=0;i<m1.r;i++)
	{
		for(int j=0;j<m1.c;j++)
		{
			cout<<m1.m[i][j]<<"  ";
		}
		cout<<"\n";
	}	
}

void sparse::convert()
{
	cout<<"Compact Sparse Matrix\n";
	a[0].r=tr;
	a[0].c=tc;
	a[0].v=tv;
	int k=1;
	for(int i=0;i<tr;i++)
	{
		for(int j=0;j<tc;j++)
		{
			if(m1.m[i][j]!=0)
			{
				a[k].r=i;
				a[k].c=j;
				a[k].v=m1.m[i][j];
				k++;
			}
		}
	}
}

void sparse::simpletranspose(sparse p)
{
	int k=1;
	a[0].r=p.a[0].c;
	a[0].c=p.a[0].r;
	a[0].v=p.a[0].v;
	tv=a[0].v;
	for(int i=0;i<p.a[0].c;i++)
	{
		for(int j=1;j<=tv;j++)
		{
			if(i==p.a[j].c)
			{
				a[k].r=i;
				a[k].c=p.a[j].r;
				a[k].v=p.a[j].v;
				k++;
			}
		}
	}
}

void sparse::display()
{
	cout<<"Rows\tCols\tTerms\n";
	cout<<"-------------------------\n";
	cout<<a[0].r<<"\t"<<a[0].c<<"\t"<<a[0].v<<"\n";
	cout<<"-------------------------\n";
	for(int i=1;i<=tv;i++)
	{
		cout<<a[i].r<<"\t";
		cout<<a[i].c<<"\t";
		cout<<a[i].v<<"\n";
	}
}

void sparse::transpose(sparse s1)
{
	int rt[10],sp[10],j,num_cols,num_terms;
 	num_cols = s1.a[0].c;
	num_terms = s1.a[0].v;
	a[0].r=s1.a[0].c;
	a[0].c=s1.a[0].r;
	a[0].v=s1.a[0].v;
	tv=a[0].v;
	if(num_terms>0)
	{
		for(int i=0;i<num_cols;i++)
		{
			rt[i]=0;
		}
		for(int i=1;i<=num_terms;i++)
		{
			rt[s1.a[i].c]++;
		}
		sp[0]=1;
		for(int i=1;i<num_cols;i++)
		{
			sp[i] = rt[i-1] + sp[i-1];
		}
		for(int i=1;i<=num_terms;i++)
		{
			j = sp[s1.a[i].c]++;
			a[j].r=s1.a[i].c;
			a[j].c=s1.a[i].r;
			a[j].v=s1.a[i].v;
		}
	}
}

void sparse::addition(sparse s1,sparse s2)
{
	int num_terms1,num_terms2;
	int k1,k2,k3;
	if(s1.a[0].r!=s2.a[0].r && s1.a[0].c!=s2.a[0].c)
	{
		cout<<"Order of matrices must be same\n";
	}
	else
	{
		num_terms1 = s1.a[0].v; num_terms2 = s2.a[0].v;
		k1=k2=k3=1;
		while(k1<=num_terms1 && k2<=num_terms2)
		{
			if(s1.a[k1].r<s2.a[k2].r)
			{
				a[k3].r = s1.a[k1].r;
				a[k3].c = s1.a[k1].c;
				a[k3].v = s1.a[k1].v;
				k3++; k1++;
			}
			else if(s1.a[k1].r>s2.a[k2].r)
			{
				a[k3].r = s2.a[k2].r;
				a[k3].c = s2.a[k2].c;
				a[k3].v = s2.a[k2].v;
				k3++; k2++;
			}
			else if(s1.a[k1].r == s2.a[k2].r)
			{
				if(s1.a[k1].c<s2.a[k2].c)
				{
					a[k3].r = s1.a[k1].r;
					a[k3].c = s1.a[k1].c;
					a[k3].v = s1.a[k1].v;
					k3++; k1++;
				}
				else if(s1.a[k1].c>s2.a[k2].c)
				{
					a[k3].r = s2.a[k2].r;
					a[k3].c = s2.a[k2].c;
					a[k3].v = s2.a[k2].v;
					k3++; k2++;
				}
				else
				{
					a[k3].r = s1.a[k1].r;
					a[k3].c = s1.a[k1].c;
					a[k3].v = s1.a[k1].v + s2.a[k2].v;
					k3++; k2++; k1++;
				}
			}
		}
		while(k1<=num_terms1)
		{
			a[k3].r = s1.a[k1].r;
			a[k3].c = s1.a[k1].c;
			a[k3].v = s1.a[k1].v;
			k3++; k1++;
		}
		while(k2<=num_terms2)
		{
			a[k3].r = s2.a[k2].r;
			a[k3].c = s2.a[k2].c;
			a[k3].v = s2.a[k2].v;
			k3++; k2++;
		}
		a[0].r = s1.a[0].r;
		a[0].c = s1.a[0].c;
		a[0].v = k3-1;
		tv=a[0].v;
	}
}

int main()
{
	sparse s1,s2,s3,s4,s5;
	cout<<"Enter Sparse Matrix 1\n";
	s1.input();
	s1.displaysparse();
	s1.convert();
	cout<<"Sparse Matrix 1\n";
	s1.display();
	cout<<"Fast Transpose\n";
	s3.transpose(s1);
	s3.display();
	cout<<"Simple Transpose is\n";
	s5.simpletranspose(s1);
	s5.display();
	cout<<"Enter Sparse Matrix 2\n";
	s2.input();
	s2.displaysparse(); s2.convert();
	cout<<"Sparse Matrix 2\n";
	s2.display();
	s4.addition(s1,s2);
	s4.display();
	
}
