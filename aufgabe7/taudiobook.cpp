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


void TAudioBook::print(ostream& out)
{
    out.fill(' ');
    out << setw(15) << left << "Anz. CDs: " << countCDs << endl;
    if (print_parents)
    {
        ((TCD&) *this).print_parents = false;
        TCD::print(out);
        ((TBook&) *this).print_parents = true;
        TBook::print(out);
    }
}

ostream& operator<<(ostream& out, TAudioBook& ab)
{
    ab.print(out);
    return out;
}
