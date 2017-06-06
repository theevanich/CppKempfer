// class TAddresse

#include <iostream>
#include <string>

using namespace std;

#include "taddress.h"


TAddress::TAddress(string Street, string Number, string Zipcode, string Town)
{
    this->Street = Street;
    this->Number = Number;
    this->Zipcode = Zipcode;
    this->Town = Town;
}

string TAddress::parseLine(string line, string tagToBeStriped)
{
    string tagEndBegin = "</";
    size_t tagStartPos = line.find(tagToBeStriped);
    int messageLength = line.length() - ((tagStartPos + 1) + (tagToBeStriped.length() * 2) + 1);
    int messageStart = tagStartPos+tagToBeStriped.length(); 
    return line.substr(messageStart, messageLength);
}


void TAddress::print()
{
    cout << Street << " " << Number << endl << Zipcode << " " << Town;
}

string TAddress::get_street() const {return Street;}
string TAddress::get_number() const {return Number;}
string TAddress::get_zipcode() const {return Zipcode;}
string TAddress::get_town() const {return Town;}

void TAddress::set_street(string s) {Street = s;}
void TAddress::set_number(string n) {Number = n;}
void TAddress::set_zipcode(string z) {Zipcode = z;}
void TAddress::set_town(string t) {Town = t;}