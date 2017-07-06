// class TEmployee

using namespace std;

#include "temployee.h"

TEmployee::TEmployee(ifstream& inFile, streampos endPos)
:TPerson(inFile, endPos), TCustomer(inFile, endPos), EmployeeNr("undefined"), endPos(endPos)
{
    load(inFile);
}

void TEmployee::load(ifstream& inFile)
{
    string tagToLookFor = "<EmployeeNr>";
    string line;
    inFile.seekg(TPerson::get_fpos());
    while (getline(inFile, line))
    {
        if (inFile.tellg() == endPos)
        {
            cout << "END OF Employee DETECTED" << endl;
            break;   
        }
        if (line.find(tagToLookFor) != string::npos)
        {
            EmployeeNr = parseLine(line, tagToLookFor);
            inFile.seekg(endPos);
            break;
        }
    }
}


TEmployee::~TEmployee()
{
    cout << "Destructing TEmployee \"" << Name << "\"..." << endl;
}


void TEmployee::print()
{
    cout << TPerson::get_name();
    cout << " (Kundennr.: " <<  TCustomer::get_customerNr();
    cout << "/ Personalnr.: " << EmployeeNr << ")" << endl;
    Address->print();
    cout << endl;
    cout << "* ";
    Birthday->print();
    cout << endl;
}


/*
 * getter and setter
 */

string TEmployee::getEmployeeNr() {return EmployeeNr;}

void TEmployee::setEmployeeNr(string e) {this->EmployeeNr = e;}