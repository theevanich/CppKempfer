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

//string get_section() const;
//string get_rack() const;
//void set_section(string section);
//void set_rack(string section);

