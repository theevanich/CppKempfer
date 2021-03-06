// class TBook
using namespace std;

#include "tbook.h"


TBook::TBook(ifstream& inFile, streampos endPos)
:TMedium(inFile, endPos), TPrintedMedium(inFile, endPos), endPos(endPos)
{
    load(inFile);
}

void TBook::load(ifstream& inFile)
{
    string tagToLookFor = "<Author>";
    string line;
    inFile.seekg(TMedium::get_fpos());
    while (getline(inFile, line))
    {
        if (inFile.tellg() == endPos)
        {
            cout << "END OF TBook DETECTED" << endl;
            break;   
        }
        if (line.find(tagToLookFor) != string::npos)
        {
            Author = parseLine(line, tagToLookFor);
            inFile.seekg(endPos);
            break;
        }
    }
}


TBook::~TBook()
{
    cout << "Destructing TBook \"" << get_name() << "\"..." << endl;
}

void TBook::print()
{
    cout.fill(' ');
    cout << setw(10) << left << "Author: "<< Author << endl;
    TMedium::print();
}
