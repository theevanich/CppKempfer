// class TPerson

#include <iostream>
#include <string>
#include "tperson.h"
#include "taddress.h"
#include "tdate.h"

using namespace std;

TPerson::TPerson(string Name, TDate Birthday, TAddress Address)
:Address(Address), Birthday(Birthday)
{
    this->Name = Name;
}

string TPerson::get_name() const
{
    return Name;
}

TAddress TPerson::get_address() const
{
    return Address;
}

TDate TPerson::get_birthday() const
{
    return Birthday;
}

void TPerson::set_name(string Name)
{
    this->Name = Name;
}

void TPerson::set_birthday(TDate Birthday)
{
    this->Birthday = Birthday;
}

void TPerson::set_address(TAddress Address)
{
    this->Address = Address;
}

void TPerson::print()
{
    cout << Name << endl;
    Address.print();
    cout << endl << "* ";
    Birthday.print();
}
