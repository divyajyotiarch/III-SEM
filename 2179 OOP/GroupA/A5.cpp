/*
Author : Divyajyoti Ukirde
Roll No. 2179
Batch : H1
 */

#include<iostream>
using namespace std;

class CppArray
{
    int *arr,count;
    public:
    	CppArray()
    	{
    		arr = new (nothrow) int [10];
		}
    void input();
    void range();
    void operator =(CppArray n1)
{
        for(int i=0;i<10;i++)
    {
        arr[i]= n1.arr[i];
    }
}
    void size();
    void output();
};

void CppArray::input()
{    
    int n, i=0;
    char a;
    for(int i=0;i<10;i++)
        {
        arr[i]=0;
        }
    cout<<"Enter array elements";
    do
    {
    cin>>n;
    arr[i]=n;
    i=i+1;
    cout<<"Do you wish to enter one more element?Y/N";
    cin>>a;    
    }while(a!='N');
}

void CppArray::size()
{     count=0;
    for (int i=0;i<10;i++)
    {
        if (arr[i]!=0)
        {
            count++;        
        }
    }
    cout<<" "<<count;
    cout<<endl;
}


void CppArray::range()
{
    int num,a[10],b[10];
    cin>>num;
    for(int i=0;i<10;i++)
        {
        a[i]=0;
        b[i]=0;
        }
        int j=0;
    for(int i=0;i<10;i++)
    {
       if(num>arr[i] && arr[i]!=0)
       {
       	a[j]=arr[i];
       	j=j+1;
	  }
    }
    int k=0;
	 for(int i=0;i<10;i++)
	 {
	   if(num<arr[i] && arr[i]!=0)
	  {
	  	b[k]=arr[i];
	  	k=k+1;
	  }
    }
    
    int min=b[0],max=a[0];
    for(int i=1;i<10;i++)
    {
    	if(min>b[i]&&b[i]!=0)
		{
			min=b[i];	
		}
	}
	for(int i=1;i<10;i++)	
	{
		if(max<a[i]&&a[i]!=0)
		{
			max=a[i];	
		}	
	}
	cout<<"( "<<max<<" ,"<<min<<" )";
	
}

void CppArray::output()
{
for(int i=0;i<10;i++)
{
if(arr[i]!=0)
cout<<" "<<arr[i]<<" ";
}
cout<<endl;
}

int main()
{
CppArray m1,m2,m3;
m1.input();
cout<<"\n Enter any number for checking its range";
m1.range();
cout<<"\n Assigning first object to second";
m2=m1;
cout<<"\n Elements in ob1=";
m1.output();
cout<<"\n Elements in ob2=";
m2.output();
cout<<"\n Size of ob1";
m1.size();
cout<<"\n Size of ob2";
m2.size();

return 0;
}

//OUTPUT
/*[pict@localhost GroupA]$ ./a.out
Enter array elements15
Do you wish to enter one more element?Y/Ny
26
Do you wish to enter one more element?Y/Ny
59
Do you wish to enter one more element?Y/Ny
32
Do you wish to enter one more element?Y/Ny
40
Do you wish to enter one more element?Y/NN

 Enter any number for checking its range24
( 15 ,26 )
 Assigning first object to second
 Elements in ob1= 15  26  59  32  40 

 Elements in ob2= 15  26  59  32  40 

 Size of ob1 5

 Size of ob2 5
*/


