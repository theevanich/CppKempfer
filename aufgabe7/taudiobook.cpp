using namespace std;

#include "taudiobook.h"


TAudioBook::TAudioBook(ifstream& inFile, streampos endPos)
:TMedium(inFile, endPos), TPrintedMedium(inFile, endPos), TBook(inFile, endPos), TCD(inFile, endPos)
{
    load(inFile);
}


void TAudioBook::load(ifstream& inFile)
{
    cout << "begin loading TAudioBook" << endl;
    string tagToLookFor = "<countCDs>";
    string line;
    inFile.seekg(TMedium::get_fpos());
    while (getline(inFile, line))
    {
        // detect end of Library to prevent any problems
        if (inFile.tellg() == endPos)
        {
            cout << "END OF TAudioBook DETECTED" << endl;
            break;   
        }
        if (line.find(tagToLookFor) != string::npos)
        {
            countCDs = atoi(parseLine(line, tagToLookFor).c_str());
            cout << "countCDs found: " << countCDs << endl;
            // inFile.seekg(endPos);
            break;
        }
    } 
}


TAudioBook::~TAudioBook()
{
    cout << "Destructing TAudioBook \"" << get_name() << "\"..." << endl;
}


void TAudioBook::print()
{
    cout << *this;
}

ostream& operator<<(ostream& out, TAudioBook& ab)
{
    out.fill(' ');
    out << setw(15) << left << "Anz. CDs: " << ab.countCDs << endl;
    if (ab.print_parents)
    {
        ((TCD&) ab).print_parents = false;
        out << (TCD&) ab;
        ((TBook&) ab).print_parents = true;
        out << (TBook&) ab;
    }

    return out;
}