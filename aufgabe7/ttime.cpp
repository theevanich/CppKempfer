// class TTime
using namespace std;

#include "ttime.h"

TTime::TTime()
{
    now = time(0);
    tm *ltm = localtime(&now);
    hh = ltm->tm_hour;
    mm = ltm->tm_min;
    ss = ltm->tm_sec;
}

TTime::TTime(int hh, int mm)
{
    this->hh = hh;
    this->mm = mm;
    ss = 0;
}

TTime::TTime(int hh, int mm, int ss)
{
    this->hh = hh;
    this->mm = mm;
    this->ss = ss;
}

TTime::TTime(ifstream& inFile)
{
    load(inFile);
}

void TTime::load(ifstream& inFile)
{
    string tagToLookFor[] = {"<Hour>", "<Minute>", "<Second>"};
    int maxTag = sizeof(tagToLookFor) / sizeof(*tagToLookFor);
    string line;
    
    while (getline(inFile, line))
    {
        // detect end of Date to prevent any problems
        if (line.find("</Time>") != string::npos)
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
                        hh = atoi(parseLine(line, tagToLookFor[i]).c_str());
                        break;
                    case 1:
                        mm = atoi(parseLine(line, tagToLookFor[i]).c_str());
                        break;
                    case 2:
                        ss = atoi(parseLine(line, tagToLookFor[i]).c_str());
                        break;
                    default:
                        cout << "Nothing found... in Date" << endl;
                        break;
                }
            }
        }
    }    
}

int TTime::get_hh() const
{
    return hh;
}


int TTime::get_mm() const
{ 
    return mm;
}

int TTime::get_ss() const
{
    return ss;
}

void TTime::set_hh(int hh)
{
    this->hh = hh;
}

void TTime::set_mm(int mm)
{
    this->mm = mm;
}

void TTime::set_ss(int ss)
{
    this->ss = ss;
}

void TTime::print()
{
    cout << this;
}

ostream& operator<<(ostream& out, TTime* t)
{
    out.fill('0');
    out << setw(2) << right << t->hh << ':' << setw(2) << right << t->mm << ':' << setw(2) << right << t->ss;
    return out;
}
