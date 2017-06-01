// class TLibraryPool

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "tdate.h"
#include "tlocation.h"
#include "taddress.h"
#include "tperson.h"
#include "tmedium.h"
#include "tlibrary.h"
#include "tlibraryPool.h"

TLibraryPool::TLibraryPool(string n, TPerson* p)
:Boss(p)
{
    Name = n;
    Boss = p;
}
TLibraryPool::~TLibraryPool() {}

void TLibraryPool::add(TPerson* customer)
{
    CustomerList.push_back(customer);
}

void TLibraryPool::add(TLibrary* lib)
{
    LibraryList.push_back(lib);
}

void TLibraryPool::print()
{
    cout << endl;
    cout << get_name() << endl;
    cout << "Leitung" << endl;
    Boss->print();
    cout << "\nZum Buecherverband gehoeren " << LibraryList.size() << " Filialen" << endl;
    for(unsigned i = 0; i < LibraryList.size(); i++)
    {
        cout << endl;
        LibraryList.at(i)->print();
        cout << endl;
    }
    cout << "Der Buecherverband hat " << CustomerList.size() << " Kunde/Kunden" << endl;
    for(unsigned j = 0; j < LibraryList.size(); j++)
    {
        cout << endl;
        CustomerList.at(j)->print();
        cout << endl;
    }
}

void TLibraryPool::set_name(string n) {Name = n;}
void TLibraryPool::set_boss(TPerson* b) {Boss = b;}
void TLibraryPool::set_customer(vector<TPerson*> cus) {CustomerList = cus;}
void TLibraryPool::set_libraryList(vector<TLibrary*>lib) {LibraryList = lib;}

string TLibraryPool::get_name() const {return Name;}
TPerson* TLibraryPool::get_boss() const {return Boss;}
vector<TPerson*>TLibraryPool::get_customerList() const {return CustomerList;}
vector<TLibrary*>TLibraryPool::get_libraryList() const {return LibraryList;}