/*
Author : Divyajyoti Ukirde
Roll No. 2179
Batch : H1
 */
 
#include <iostream>
#include<string.h>
using namespace std;

class User
{
private:
    int age , wh;    //wh=no. of wheels on vehicle
    string city;
    long long int sal;
public:
    void input();
    void display();
};

void User::input()
{
        cout<<"Enter age \n";
        cin>>age;
      cout<<"Enter income \n";
        cin>>sal;
         cout<<"Enter city Pune/Bangalore/Mumbai/Chennai \n";
        cin>>city;
        cout<<"2-4 wheeler vehicle? \n";
        cin>>wh;
}

void User::display()
{
    try
    {

        if(age>=18 && age<55)
            {
                cout<<"Age: "<<age<<endl;
            }
        else
        {
            throw 1;
        }

    }catch(int a)
    {
        cout<<"Age should be between 18-55"<<endl;
    }
    try
    {
        if(sal>50000 && sal<100000)
            {
                cout<<"Income: "<<sal<<endl;
            }
        else
        {
            throw 1.1;
        }
    }catch(double b)
    {
        cout<<"Income should be between Rs.50,000-1,00,000 per annum"<<endl;
    }
    try
    {
        if(city=="Pune"||city=="pune"||city=="bangalore"||city=="Bangalore"||city=="Mumbai"||city=="mumbai"||city=="Chennai"||city=="chennai")
            {
                cout<<"City: "<<city<<endl;
            }
        else
        {
            throw 'a';
        }
    }catch(char c)
    {
        cout<<"Not present in the mentioned cities"<<endl;
    }
    try
    {
        if(wh!=4)
            {
                cout<<"Vehicle should be 4 wheeler"<<endl;
            }
        else
        {
            throw "hello";
        }
    }catch(...)
        {
            cout<<"Vehicle: "<<wh<<" wheeler"<<endl;
        }
}

int main()
{
    User u;
    u.input();
    u.display();

    return 0;
}

//OUTPUT
/*Enter age 
18
Enter income 
54000
Enter city Pune/Bangalore/Mumbai/Chennai 
Pune
2-4 wheeler vehicle? 
4
Age: 18
Income: 54000
City: Pune
Vehicle: 4 wheeler
[pict@localhost GroupB]$ g++ B1.cpp
[pict@localhost GroupB]$ ./a.out
Enter age 
17
Enter income 
25000
Enter city Pune/Bangalore/Mumbai/Chennai 
Indore
2-4 wheeler vehicle? 
2
Age should be between 18-55
Income should be between Rs.50,000-1,00,000 per annum
Not present in the mentioned cities
Vehicle should be 4 wheeler
*/
