// class TCustomer
using namespace std;

#include "tcustomer.h"

TCustomer::TCustomer(ifstream& inFile)
:TPerson(inFile), CustomerNr("undefined")
{
    load(inFile);
}

void TCustomer::load(ifstream& inFile)
{
    string tagToLookFor = "<CustomerNr>";
    string line;
    while (getline(inFile, line))
    {
        if (line.find(tagToLookFor) != string::npos)
        {
            CustomerNr = parseLine(line, tagToLookFor);
            return;
        }
    }
}

TCustomer::~TCustomer()
{
    cout << "Destructing TCustomer \"" << this->Name << "\"... " << endl;
}

void TCustomer::print()
{
    TPerson::print();
    cout << "(Kundennr.: " << this->CustomerNr << endl;
}

string TCustomer::get_customerNr() const
{
    return CustomerNr;
}