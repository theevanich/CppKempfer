// class TAddresse

#include <iostream>
#include <string>
#include "taddress.h"

using namespace std;

TAddress::TAddress(string Street, string Number, string Zipcode, string Town)
{
    this->Street = Street;
    this->Number = Number;
    this->Zipcode = Zipcode;
    this->Town = Town;
}

void TAddress::print()
{
    cout << Street << " " << Number << endl << Zipcode << " " << Town;
}

string TAddress::get_street() const
{
    return Street;
}

string TAddress::get_number() const
{
    return Number;
}

string TAddress::get_zipcode() const
{
    return Zipcode;
}

string TAddress::get_town() const
{
    return Town;
}

void TAddress::set_street(std::string)
{
    this->Street = Street;
}

void TAddress::set_number(std::string)
{
    this->Number = Number;
}

void TAddress::set_zipcode(std::string)
{
    this->Zipcode = Zipcode;
}

void TAddress::set_town(std::string)
{
    this->Town = Town;
}
