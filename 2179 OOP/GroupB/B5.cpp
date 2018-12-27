#include<iostream>
#include<fstream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;

int main(int argc,char *argv[])
{	
	if(argc<4)
	{
		cout<<"Insufficient arguments\n";
		exit(1);
	}

		string line,newline;
		
		fstream file;
		file.open(argv[1],ios::in); //read mode
		newline="";
		if(!file.is_open())
		{
			cout<<"Could not open file\n";
			exit(1);
		}
			while(file)
			{
				getline(file,line);
				int pos = (int)line.find(argv[2],0);
				while(pos!=string::npos)
				{
					line.replace(pos,strlen(argv[2]),argv[3]);
					pos = line.find(argv[2],pos+1);
				}
				newline = newline + line + "\n";
			}
			file.close();
		
		file.open(argv[1],ios::out);   //write mode
		file.seekg(0);
		file<<newline;
		file.close();

	return 0;
}
