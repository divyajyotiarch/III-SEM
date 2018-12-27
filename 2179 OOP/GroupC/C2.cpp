#include<iostream>
#include<deque>
#include<string.h>
#include<cstdlib>
using namespace std;
int main()
{
	deque<int> dq;
    deque <int> :: iterator it;
    int item,ch;
 do
{
    cout<<"\n Enter choice";
    cout<<"\n1.Insert at end \n2.Insert in front \n3.Delete from end \n4.Delete from front \n5.Front element \n6.Rear element \n";
    cout<<"7. Exit \n";
    cin>>ch;
  switch(ch)
  {
   case 1:
   	cout<<"Insert Element \t";
     cin>>item;
     dq.push_back(item);
       for (it = dq.begin(); it != dq.end(); ++it)
      {
          cout<<*it<<"  ";
      }
   break;
    case 2:
   {
   	   	cout<<"Insert Element \t";
     cin>>item;
     dq.push_front(item);
   }
    for (it = dq.begin(); it != dq.end(); ++it)
      {
          cout<<*it<<"  ";
      }
   break;
    case 3:
   {
     item=dq.back();
     dq.pop_back();
   }
    for (it = dq.begin(); it != dq.end(); ++it)
      {
          cout<<*it<<"  ";
      }
   break;
    case 4:
   {
      item=dq.front();
      dq.pop_front();
   }
         for (it = dq.begin(); it != dq.end(); ++it)
      {
          cout<<*it<<"  ";
      }
   break;
   case 5:
   {
      cout<<"\n front element of deque is:\t";
      cout<<dq.front();
   }
   break;
   case 6:
   {
      cout<<"\n rear element of deque is:\t";
      cout<<dq.back();
   }

   break;

  }
  
}while(ch<7);
  return 0;
}
