// class tdate
#include <fstream>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>

using namespace std;

#include "tdate.h"

TDate::TDate()
{
    now = time(0);
    tm *ltm = localtime(&now);
    dd = ltm->tm_mday;
    mm = 1 + ltm->tm_mon;
    yyyy = 1900 + ltm->tm_year;
}

TDate::TDate(int dd, int mm, int yyyy)
{
    this->dd = dd;
    this->mm = mm;
    this->yyyy = yyyy;
}

TDate::TDate(ifstream& inFile)
{
    load(inFile);
}

void TDate::load(ifstream& inFile)
{
    string tagToLookFor[] = {"<Day>", "<Month>", "<Year>"};
    int maxTag = sizeof(tagToLookFor) / sizeof(*tagToLookFor);
    string line;
    
    while (getline(inFile, line))
    {
        // detect end of Date to prevent any problems
        if (line.find("</Date>") != string::npos)
        {
            break;
        }
        for(int i = 0; i < maxTag; i++)
        {
            if (line.find(tagToLookFor[i]) != string::npos )
            {
                switch(i)
                {
                    case 0:
                        dd = atoi(parseLine(line, tagToLookFor[i]).c_str());
                        break;
                    case 1:
                        mm = atoi(parseLine(line, tagToLookFor[i]).c_str());
                        break;
                    case 2:
                        yyyy = atoi(parseLine(line, tagToLookFor[i]).c_str());
                        break;
                    default:
                        cout << "Nothing found... in Date" << endl;
                        break;
                }
            }
        }
    }
}

string TDate::parseLine(string line, string tagToBeStriped)
{
    string tagEndBegin = "</";
    size_t tagStartPos = line.find(tagToBeStriped);
    int messageLength = line.length() - ((tagStartPos + 1) + (tagToBeStriped.length() * 2) + 1);
    int messageStart = tagStartPos+tagToBeStriped.length(); 
    return line.substr(messageStart, messageLength);
}

void TDate::print()
{
    cout << setfill('0');
    cout << setw(2) << dd << '.' << setw(2) << mm << '.' << yyyy;
}