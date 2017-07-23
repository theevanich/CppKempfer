using namespace std;

#include "tmagazine.h"

TMagazine::TMagazine(ifstream& inFile, streampos endPos)
:TMedium(inFile, endPos), TPrintedMedium(inFile, endPos), endPos(endPos)
{
    load(inFile);
}


TMagazine::~TMagazine()
{
    cout << "Destructing TMagazine \"" << get_name() << "\"..." << endl;
}

void TMagazine::load(ifstream& inFile)
{
    string tagToLookFor = "<Designer>";
    string line;
    inFile.seekg(TMedium::get_fpos());
    while (getline(inFile, line))
    {
        if (inFile.tellg() == endPos)
        {
            cout << "END OF TMagazine DETECTED" << endl;
            break;   
        }
        if (line.find(tagToLookFor) != string::npos)
        {
            Designer = parseLine(line, tagToLookFor);
            inFile.seekg(endPos);
            break;
        }
    }
}

void TMagazine::print(ostream& out)
{
    out.fill(' ');
    out << setw(15) << left << "Designer: "<< Designer << endl;
    if (print_parents)
    {
        TMedium::print(out);
    }
}

ostream& operator<<(ostream& out, TMagazine& magazine)
{
    magazine.print(out);
    return out;
}
