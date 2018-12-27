/*
 ============================================================================
 Name        : Assignment2.cpp
 Author      : hh
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C++,
 ============================================================================
 */

#include <iostream>

using namespace std;

class matrix
{
	int i,j,m1[3][3],m2[3][3];
public:

	void getdata();
	void upperTriangle();
	void trace();
	void transpose();
	void operation();
	void saddle();
	void display();
};

void matrix::getdata()
{

cout<<"enter matrix1\n";
for(i=0;i<3;i++)
{
for (j=0;j<3;j++)
	cin>>m1[i][j];
}
cout<<"enter matrix2\n";
for(i=0;i<3;i++)
{
for (j=0;j<3;j++)
cin>>m2[i][j];
}
}
void matrix::display()
{

	for(i=0;i<3;i++)
	{
	for (j=0;j<3;j++)
	cout<<"\t"<<m1[i][j];
	}
	for(i=0;i<3;i++)
	{
	for (j=0;j<3;j++)
	cout<<"\t"<<m2[i][j];
	}
}

int main()
{
	matrix m;
	m.getdata();
	m.display();

	return 0;
}

