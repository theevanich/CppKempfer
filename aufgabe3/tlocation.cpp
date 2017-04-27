// class TLocation

#include <iostream>
#include <string>
#include "tlocation.h"

using namespace std;

TLocation::TLocation()
{
    section = "Buero";
    rack = "Fach zum Einsortieren";
}

TLocation::TLocation(string section, string rack)
{
    this->section = section;
    this->rack = rack;
}

void TLocation::print()
{
    cout << "Abt.: " << section << "; " << "Regal: " << rack;
}

string TLocation::get_section() const
{
    return section;
}
string TLocation::get_rack() const
{
    return rack;
}

void TLocation::set_section(string section)
{
    this->section = section;
}

void TLocation::set_rack(string section)
{
    this->rack = rack;
}

