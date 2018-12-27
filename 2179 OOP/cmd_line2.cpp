#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    ifstream in(argv[1]);
    ofstream out(argv[2]);
    string wordToReplace(argv[3]);
    string wordToReplaceWith(argv[4]);

    if (!in)
    {
        cerr << "Could not open " << argv[1] << "\n";
        return 1;
    }

    if (!out)
    {
        cerr << "Could not open " << argv[2] << "\n";
        return 1;
    }

    string line;
    size_t len = wordToReplace.length();
    while (getline(in, line))
    {
        while (true)
        {
            size_t pos = line.find(wordToReplace);
            if (pos != string::npos)
                line.replace(pos, len, wordToReplaceWith);
            else 
                break;
        }

        out << line <<"\n";
    }
}
