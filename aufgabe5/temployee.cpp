// class TEmployee

using namespace std;

#include "temployee.h"

TEmployee::TEmployee(ifstream& inFile)
:TPerson(inFile),
 TCustomer(inFile),
 EmployeeNr("undefined")
{
    load(inFile);
}

void TEmployee::load(ifstream& inFile)
{
    string tagToLookFor = "<EmployeeNr>";
    string line;
    while (getline(inFile, line))
    {
        cout << endl;
        cout << line;
        if (line.find(tagToLookFor) != string::npos)
        {
            CustomerNr = parseLine(line, tagToLookFor);
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