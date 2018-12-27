/*
Author : Divyajyoti Ukirde
Roll No. 2179
Batch : H1
 */

#include<iostream>
#include<string.h>
using namespace std;

	class personal
{
    protected:
    	char name[20],address[50];
    	int d,m,y;
    	long long ph;	
    
    public:
    void display()
    {
        cout<<"\n Name:"<<name;
        cout<<"\n Address: ";
        cout<<address;
        cout<<"\n DOB: "<<d<<"/"<<m<<"/"<<y;
        cout<<"\n Phone no.: "<<ph;
    }
};

class professional
{
    protected:
    	char company[20],work[20];	
    public:
    void display()
    {
        cout<<"\n Company: ";
        cout<<company;
        cout<<"\n Designation: ";
        cout<<work;        
    }

};

class academic
{
    protected:
    char qual[10];
    float ssc,hsc;
    public:
    void display()
    {
        cout<<"\n Qualification: "<<qual;
        cout<<"\n SSC%:"<<ssc<<"\t HSC%:"<<hsc;
    }
};

class biodata : public personal, public professional, public academic
{
    public:
    void getdata()
    {    
        cout<<"Enter Biodata: ";   
        cout<<"Enter Name: ";
        cin.ignore(); 
        cin.getline(name,20); 
        cin.ignore();
        cout<<"\n Enter Address: ";
        cin.getline(address,50);
        cout<<"\n Enter DOB(dd/mm/yy)";
        cin>>d>>m>>y;    
        cout<<"\n Enter phone no.: ";
        cin>>ph;
        cout<<"\n Enter Qualification: ";
        cin>>qual;
        cout<<"\n Enter SSC and HSC %: ";
        cin>>ssc>>hsc;
        cout<<"\n Enter Company Name: ";
        cin.ignore();
        cin.getline(company,20);
        cin.ignore();
        cout<<"\n Enter Designation: ";
        cin.getline(work,20);
    }    
    void display()
    {
        personal::display();
        professional::display();
        academic::display();
    }
};


int main()
{    
	biodata *b1 = new biodata[10];
	int count=0;
    char x;
    do
    {
    b1[count].getdata();
    cout<<"Want to enter data? y/n";
    cin>>x;
    count++;
    }while(x!='n');
    for(int j=0;j<count;j++)
        {
        b1[j].display();	
		}
    return 0;  
}

//OUTPUT
/* Name:divya
 Address: pune dhankavdi
 DOB: 5/4/98
 Phone no.: 9898987898
 Company: Morgan Stanley
 Designation: Software Engineer
 Qualification: B.Tech
 SSC%:97	 HSC%:89
 Name:Medha
 Address: pune katraj
 DOB: 31/3/99
 Phone no.: 8987898789
 Company: Google
 Designation: CEO
 Qualification: B.E.
 SSC%:98	 HSC%:98*/
