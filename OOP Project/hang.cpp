#include <iostream>
#include<fstream>
#include<string.h>
#include<ctime>
#include<vector>
#include<cstdlib>
using namespace std;

int NUM_TRY=5; //no. of tries
int checkGuess (char, string, string&);  
void display();
string message1 = "Enter 1 for Admin \n2 for Player \n";
string message = "Play!";
vector<char>v1;

class animal
{
	char name[20];
	int sno;
	public:
		string search();
	friend istream& operator>>(istream&,animal&);
	friend ostream& operator<<(ostream&,animal&);
};

istream & operator>>(istream &in, animal &p)
{
	animal a;
	ofstream outfile;
	outfile.open("animal1.txt",ios::app);
	in>>a.sno;
	in>>a.name;
	outfile.write((char*)&a,sizeof(a));
	outfile.close();
	return in;
}

ostream & operator<<(ostream &out, animal &p)
{
	animal d;
		ifstream fi;
		fi.open("animal1.txt",ios::in);
		fi.seekg(0);
		while(fi.read((char*)&d,sizeof(d)))
			{
				out<<d.sno<<"  "<<d.name<<endl;
			}
		fi.close();
		return out;
}

string animal::search()
{
	int count=0; 
	animal d;
		ifstream fil;
		fil.open("animal1.txt",ios::in);
		fil.seekg(0);
		while(fil.read((char*)&d,sizeof(d)))
			{
				count++;
			}
		fil.close();

	srand(int(time(0)));
	int n=rand()% count;
	string line;
	ifstream fi;

		fi.open("animal1.txt");
		while(fi.read((char*)&d,sizeof(d)))
		{
			if(n==d.sno)
			{
				line=d.name;
			}
		}
		fi.close();
		return line;
}

int main() {
	
	int choice;
	animal p;
/*	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	cin>>p;	
	}*/
//	cout<<p;
	cout<<message1;
	cin>>choice;
	try
	{
	if(choice==1)
	{
		string pass;
		cout<<"Enter Password\n";
		cin>>pass;
		if(pass=="admin")
		{
			while(1)
		{	int ch;
			cout<<"1. Update\n";
			cout<<"2. Display\n";
			cout<<"Enter 0 to stop\n";
			cin>>ch;
			switch(ch)
			{
				case 0:
					exit(0);
				case 1:
					int n;
					cout<<"No. of entries\n";
					cin>>n;
					for(int i=0;i<n;i++)
						{
						cin>>p;	
						}
					break;
				case 2:
					cout<<p;
					break;
			}
		}
		}
		else
		{
			cout<<"Not an admin??";
		}
		
	}
	else if(choice==2)
	{
			char letter;
		string line =p.search();
		string hide_m(line.length(),'X');
		while (NUM_TRY!=0)
		{
			display();
			cout << "\n\n\t\t\t\t" << hide_m<<" ";
			cout << "\n\n\t\t\t\tGuess a letter: ";
			cin >> letter;
			try
			{
				int x;
				x=(int)letter;
				if(x>=97 && x<=123)
				{
					v1.push_back(letter);
					
					if (checkGuess(letter, line, hide_m)==0)
					{
						message = "Incorrect letter.";
						NUM_TRY = NUM_TRY - 1;
					}
					else
					{
						message = "NICE! You guess a letter";
					}
					if (line==hide_m)
					{
						message = "Congratulations! You got it!";
						display();
						cout << "\n\t\t\t\tThe animal is : " << line << endl;
						break;
					}
	
				if(NUM_TRY == 0)
				{
					message = "NOOOOOOO!...you've been hanged.";
					display();
					cout << "\n\t\t\t\tThe animal was : " << line << endl;
				}
				cin.ignore();
			}
			else	
				throw 1;
				
			}catch(...)
			{
				message = "EXCEPTION: PLEASE ENTER JUST SMALL ALPHABETS \n";
			}
					}
			}
			else
			{
				throw 'a';
			}
	}
	catch(char q)
	{
		cout<<"EXCEPTION: INVALID CHOICE \n";
	}

 return 0;
}

 
int checkGuess (char guess, string secretanimal, string &guessanimal)
{
	int i;
	int matches=0;  //acting like flag variable, returns 0 for wrong letter n positive for right letters
	int len=secretanimal.length();
	for (i = 0; i< len; i++)
	{
		// removes tries after repetition of correct letters
		if (guess == guessanimal[i])
		{
			cout<<"hello\n";
			cout<<guessanimal[i]<<"\t";
			return 0;
		}
		// puts correct letter in correct place
		if (guess == secretanimal[i])
		{
			guessanimal[i] = guess;
			matches++;
		}
	}
	return matches;
}
 
void display()
{
               system("cls");
 
 cout<<"\t\t************************************************************";
                cout<<"\n\t\t\t\tHangman Game!";
				cout << "\n\t\tYou have " << NUM_TRY << " tries to try and guess the animal.";
				cout<<"\n\n\t\t\t\t"<<message<<"\n";
				if(!v1.empty())
				{
				cout<<"\t\t\t\tLetters guessed\n\t\t\t\t";
				for(int i=0;i<v1.size();i++)
				{
					cout<<v1[i]<<" ";
				}
			}
 cout<<"\n\t\t**********************************************************\n";
 
}
