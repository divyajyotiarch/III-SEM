
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class directory
		{		
		public:	
			char name[20];
			char address[50];
			long long int ph;

			void getdata();
			void data();
		};
		
void directory::getdata()
	{
		cout<<"\nEnter name: ";
		cin>>name;
		cout<<"\nEnter Address:";
		cin.ignore();
		cin.getline(address,50);
		cout<<"\nEnter ph. no.: ";
		cin>>ph;
	}
void directory::data()
{
	cout<<"\nName: "<<name;
	cout<<"\nAddress:"<<address;
	cout<<"\nPh. no.: "<<ph<<"\n";
 }  
int main() 
{
    map<string,directory>m;
    cout<<"Enter the no. of entries \n";
	int n;
	cin>>n;
	directory d[n];
		
	for(int i=0;i<n;i++)
	{
		d[i].getdata();
		m.insert(make_pair(d[i].name,d[i]));
	}	
	int ch;
    map<string,directory>::iterator it;
    map<string,directory>::iterator i;
    while(1)
	{
    cout<<"1. Display \n";
    cout<<"2. Search \n";
    cout<<"0 for Exit \n";
    cin>>ch;
    switch(ch)
	{
    case 0:
        exit(0);
    case 1:
        for( it=m.begin();it!=m.end();it++)
		{
            //cout<<it->first<<" ";
                it->second.data();
        }
        break;
        
 	  case 2:
    	string nam;
			cout<<"Enter the first name to search: ";
			cin>>nam;

          i=m.find(nam);
          if(i==m.end())
          {
          	cout<<"Not present \n";
		  }
		  else
		  {
		 // 	cout<<i->first<<" ";
                   i->second.data();
		  }		
        break;
    	}
    }
    return 0;
}
 
