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

void TCustomer::add(TLoan* loan)
{
    LoanList.push_back(loan);
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
    if (LoanList.size() > 0)
    {
        cout << "Ausleihen:" << endl;
        for(uint8_t i = 0; i < LoanList.size(); i++)
        {
            LoanList.at(i)->print();
        }
    }
}

string TCustomer::get_customerNr() const
{
    return CustomerNr;
}