using namespace std;

#include "tprintedmedium.h"


TPrintedMedium::TPrintedMedium(ifstream& inFile, streampos endPos)
:TMedium(inFile, endPos), endPos(endPos)
{
    load(inFile);
}

void TPrintedMedium::load(ifstream& inFile)
{
    string tagToLookFor = "<Pages>";
    string line;
    inFile.seekg(TMedium::get_fpos());
    while (getline(inFile, line))
    {
        if (inFile.tellg() == endPos)
        {
            cout << "END OF TPrintedMedium DETECTED" << endl;
            break;   
        }
        if (line.find(tagToLookFor) != string::npos)
        {
            Pages = atoi(parseLine(line, tagToLookFor).c_str());
            inFile.seekg(endPos);
            break;
        }
    }    
}

TPrintedMedium::~TPrintedMedium ()
{
    cout << "Destructing TPrintedMedium \"" << get_name() << "\"..." << endl;
}


void TPrintedMedium::print(ostream& out)
{
    out.fill(' ');
    out << setw(15) << left << "Anz. Seiten: " << Pages << endl;

    if (print_parents)
    {
        TMedium::print(out);
    }
}

ostream& operator<<(ostream& out, TPrintedMedium& printedmedium)
{
    printedmedium.print(out);
    return out;    
}
