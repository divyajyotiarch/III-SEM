/*
Author : Divyajyoti Ukirde
Roll No. 2179
Batch : H1
 */

#include<iostream>
#include<string.h>
#include<fstream>

using namespace std;

class student
{
	string name;
	int rno;
	public:
	void getdata()
	{
		cout<<"Enter name and roll no.\n";
		cin>>name>>rno;
	}
	void display()
	{
		cout<<name<<" :\t";
		cout<<rno<<"\n";
	}
};

int main()
{
	int n;
	cout<<"\n Enter Size of array \n";
	cin>>n;
	student s[n];
	
	ofstream outfile;
	outfile.open("16Student", ios::out | ios::trunc);
	
	if(outfile.is_open())
	{
		for(int i=0; i<n;i++)
		{
			s[i].getdata();
			outfile.write((char*)&s[i], sizeof(s));
		}
		
		outfile.close();
	}
	ifstream infile;
	infile.open("16Student",ios::in);
	if(infile.is_open())
	{
		
		for(int i=0; i<n;i++)
		{
		infile.read((char*)&s[i], sizeof(s));
			s[i].display();
		}
		infile.close();
	}
	
	return 0;
}

//OUTPUT
/*Enter Size of array 
3
Enter name and roll no.
divya 2179
Enter name and roll no.
harry 2555
Enter name and roll no.
ron 3434
divya :	2179
harry :	2555
ron :	3434
*/
