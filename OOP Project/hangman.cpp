#include <iostream>
#include<fstream>
#include<string.h>
#include<ctime>
#include<cstdlib>
using namespace std;

int NUM_TRY=5; //no. of tries
int checkGuess (char, string, string&);  
void display();
string message = "Play!";

int main() {
	srand(int(time(0)));
	int n=rand()% 101;
	ifstream in;
	string line;
	char letter;
	in.open("animals.txt");
	if(in.is_open()){
		for(int i=0;i<n;i++){
			getline(in,line);
		}in.close();
	}string hide_m(line.length(),'X');
	while (NUM_TRY!=0)
	{
		display();
		cout << "\n\n\t\t\t\t" << hide_m;
		cout << "\n\n\t\t\t\tGuess a letter: ";
		cin >> letter;
		
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
	}
	if(NUM_TRY == 0)
	{
		message = "NOOOOOOO!...you've been hanged.";
		display();
		cout << "\n\t\t\t\tThe animal was : " << line << endl;
	}
	cin.ignore();
 return 0;
}

 
int checkGuess (char guess, string secretmonth, string &guessmonth)
{
	int i;
	int matches=0;  //acting like flag variable, returns 0 for wrong letter n positive for right letters
	int len=secretmonth.length();
	for (i = 0; i< len; i++)
	{
		// removes tries after repetition of correct letters
		if (guess == guessmonth[i])
		{
			cout<<"hello\n";
			cout<<guessmonth[i]<<"\t";
			return 0;
		}
		// puts correct letter in correct place
		if (guess == secretmonth[i])
		{
			guessmonth[i] = guess;
			matches++;
		}
	}
	return matches;
}
 
void display()
{
	 //system("color 00");
               system("cls");
 
  /*cout<<"\t\t\t\t**\t**";
   cout<<"\t\t\t\t***\t***";
   cout<<"\t\t\t\t****\t****";
   cout<<"\t\t\t\t*****\t*****";
    cout<<"\t\t\t\t******\t******";
   cout<<"\t\t\t\t*******\t*******";
   cout<<"\t\t\t\t*******\t*******";
   cout<<"\t\t\t\t******\t******";
   cout<<"\t\t\t\t*****\t*****";
   cout<<"\t\t\t\t****\t****";
   cout<<"\t\t\t\t***\t***";
   cout<<"\t\t\t\t**\t**";
   cout<<"\t\t\t\t*\t*";
 */
 cout<<"\t\t************************************************************";
                cout<<"\n\t\t\t\tHangman Game!";
				cout << "\n\t\tYou have " << NUM_TRY << " tries to try and guess the animal.";
				cout<<"\n\n\t\t\t\t"<<message;
 cout<<"\n\t\t**********************************************************\n";
 
}
