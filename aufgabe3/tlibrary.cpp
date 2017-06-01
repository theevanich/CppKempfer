// class TLibrary

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

TLibrary::TLibrary(string name, TAddress address, TPerson* Person )
:Name(name), address(address), Manager(Person) {}

TLibrary::~TLibrary() {}

string TLibrary::get_name() const {return Name;}
TAddress TLibrary::get_address() const {return address;}
TPerson* TLibrary::get_manager() const {return Manager;}

void TLibrary::add(TMedium *medium)
{
    MediumList.push_back(medium);
}

void TLibrary::print()
{
    cout << "Buecherei Filiale " << get_name() << endl;
    address.print(); cout << endl;
    cout << "Filialleister: ";
    Manager->print();
    cout << "Es stehen " << MediumList.size() << " Medium/Medien zur Verfuegung:" << endl;
    for(unsigned i = 0; i < MediumList.size(); i++)
    {
        cout << endl;
        MediumList.at(i)->print();
        cout << endl;
    }
}