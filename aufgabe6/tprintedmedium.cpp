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

void TPrintedMedium::print()
{
    cout << "Medientyp: Gedrucktes Medium" << endl;
    TMedium::print();
}


TPrintedMedium::~TPrintedMedium ()
{
    cout << "Destructing TPrintedMedium \"" << get_name() << "\"..." << endl;
}
