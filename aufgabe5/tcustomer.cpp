// class TCustomer
using namespace std;

#include "tcustomer.h"

TCustomer::TCustomer(ifstream& inFile, streampos endPos)
:TPerson(inFile, endPos), CustomerNr("undefined"), endPos(endPos)
{
    load(inFile);
}

void TCustomer::load(ifstream& inFile)
{
    string tagToLookFor = "<CustomerNr>";
    string line;
    inFile.seekg(TPerson::get_fpos());
    while (getline(inFile, line))
    {
        if (inFile.tellg() == endPos)
        {
            cout << "END OF CUSTOMER DETECTED" << endl;
            break;   
        }
        if (line.find(tagToLookFor) != string::npos)
        {
            CustomerNr = parseLine(line, tagToLookFor);
            inFile.seekg(endPos);
            break;
        }
    }
}

TCustomer::~TCustomer()
{
    cout << "Destructing TCustomer \"" << this->Name << "\"... " << endl;
}

void TCustomer::print()
{
    cout << TPerson::get_name();
    cout << " (Kundennr.: " <<  TCustomer::get_customerNr() << ")" << endl;
    Address->print();
    cout << endl;
    cout << "* ";
    Birthday->print();
    cout << endl;
}

string TCustomer::get_customerNr() const
{
    return CustomerNr;
}