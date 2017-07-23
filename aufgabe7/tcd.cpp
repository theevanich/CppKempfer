using namespace std;

#include "tcd.h"


TCD::TCD (ifstream& inFile, streampos endPos)
:TMedium(inFile, endPos), endPos(endPos)
{
    load(inFile);
}


void TCD::load(ifstream& inFile)
{
   string tagToLookFor[] = {"<Interpret>", "<Tracks>"};
    int maxTag = sizeof(tagToLookFor) / sizeof(*tagToLookFor);
    string line;
    inFile.seekg(TMedium::get_fpos());
    while (getline(inFile, line))
    {
        // detect end of Library to prevent any problems
        if (inFile.tellg() == endPos)
        {
            cout << "END OF TCD DETECTED" << endl;
            break;   
        }
        for(int i = 0; i < maxTag; i++)
        {
            if (line.find(tagToLookFor[i]) != string::npos )
            {
                switch(i)
                {
                    case 0:
                        Interpret = parseLine(line, tagToLookFor[i]);
                        break;
                    case 1:
                        Tracks = atoi(parseLine(line, tagToLookFor[i]).c_str());
                        break;                                            
                    default:
                        cout << "Nothing found... in TCD" << endl;
                        break;
                }
            }
        }
    }
}


TCD::~TCD()
{
    cout << "Destructing TCD \"" << get_name() << "\"..." << endl;
}

void TCD::print(ostream& out)
{
    out.fill(' ');
    out << setw(15) << left << "Interpret: " << Interpret << endl;
    out << setw(15) << left << "Anz. Tracks: " << Tracks << endl;

    if (print_parents)
    {
        TMedium::print(out);
    }
}

ostream& operator<<(ostream& out, TCD& cd)
{
    cd.print(out);
    return out;
}
