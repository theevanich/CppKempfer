// class TMedium

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#include "tlocation.h"
#include "tmedium.h"

TMedium::TMedium(string Name, string Signature, TLocation Location, int FSK, Status status)
:Name(Name), Signature(Signature), Location(Location), FSK(FSK)
{
    set_status(status);
}

void TMedium::set_status(Status st)
{
    status = st;
}

TMedium ::~TMedium()
{
    cout << "Das Medium " << Name << " mit der Signatur " << Signature << " wird vernichtet!" << endl;
}

string TMedium::get_status() const
{
    switch(status)
    {
        case bestellt:
            return "bestellt";
        case verfuegbar:
            return "verfuegbar";
        case reserviert:
            return "reserviert";
        case ausgeliehen:
            return "ausgeliehen";
        default:
            return "not defined";
    }
}

void TMedium::set_name(string n) { Name = n; }
void TMedium::set_signature(string s) { Signature = s; }
void TMedium::set_FSK(int age) { FSK = age;}
void TMedium::set_location(TLocation location) { Location = location; }

string TMedium::get_name() const { return Name; }
string TMedium::get_signature() const {return Signature;}
int TMedium::get_FSK() const {return FSK;}

void TMedium::print()
{
    char tmp = cout.fill();
    cout.fill(' ');
    cout << setw(10) << left << "Titel: "<< get_name() << endl;
    cout << setw(10) << left << "Signatur: " << get_signature() << endl;
    cout << setw(10) << left << "Ort:"; Location.print(); cout << endl;
    cout << setw(10) << left << "FSK:" << "freigegeben ab " << get_FSK() << " Jahren" << endl;
    cout << setw(10) << left << "Status: " << get_status();
}