// class TMedium
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

#include "tlocation.h"
#include "tmedium.h"

TMedium::TMedium(string Name, string Signature, TLocation* Location, int FSK, Status status)
:Name(Name), Signature(Signature), Location(Location), FSK(FSK)
{
    set_status(status);
}

TMedium::~TMedium()
{
    cout << "Das Medium " << Name << " mit der Signatur " << Signature << " wird vernichtet!" << endl;
}

TMedium::TMedium(ifstream& inFile)
{
    load(inFile);
}

void TMedium::load(ifstream& inFile)
{
    string tagToLookFor[] = {"<Title>", "<Signatur>", "<Location>", "<FSK>", "<Status>"};
    int maxTag = sizeof(tagToLookFor) / sizeof(*tagToLookFor);
    string line;
    
    while (getline(inFile, line))
    {
        // detect end of Medium to prevent any problems
        if (line.find("</Medium>") != string::npos)
        {
            break;
        }
        for(int i = 0; i < maxTag; i++)
        {
            if (line.find(tagToLookFor[i]) != string::npos )
            {
                switch(i)
                {
                    case 0:
                        Name = parseLine(line, tagToLookFor[i]);
                        break;
                    case 1:
                        Signature = parseLine(line, tagToLookFor[i]);
                        break;
                    case 2:
                        Location = new TLocation(inFile);
                        break;
                    case 3:
                        FSK = atoi(parseLine(line, tagToLookFor[i]).c_str());
                        break;
                    case 4:
                        set_status(atoi(parseLine(line, tagToLookFor[i]).c_str()));
                        break;      
                    default:
                        cout << "Nothing found... in Medium" << endl;
                        break;
                }
            }
        }
    }
}

string TMedium::parseLine(string line, string tagToBeStriped)
{
    size_t tagStartPos = line.find(tagToBeStriped);
    int messageLength = line.length() - ((tagStartPos + 1) + (tagToBeStriped.length() * 2) + 1);
    int messageStart = tagStartPos+tagToBeStriped.length(); 
    return line.substr(messageStart, messageLength);
}

void TMedium::set_status(int statusInt)
{
    switch(statusInt)
    {
        case TMedium::verfuegbar:
            status = TMedium::verfuegbar;
            break;
        case TMedium::ausgeliehen:
            status = TMedium::ausgeliehen;
            break;
        case TMedium::bestellt:
            status = TMedium::bestellt;
            break;
        case TMedium::reserviert:
            status = TMedium::reserviert;
            break;            
        default:
            cout << "Nothing found... in status" << endl;
            break;
    }
}

void TMedium::set_status(Status st) {status = st;}
void TMedium::set_name(string n) { Name = n; }
void TMedium::set_signature(string s) { Signature = s; }
void TMedium::set_FSK(int age) { FSK = age;}
void TMedium::set_location(TLocation* location) { Location = location; }

string TMedium::get_name() const { return Name; }
string TMedium::get_signature() const {return Signature;}
int TMedium::get_FSK() const {return FSK;}
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

void TMedium::print()
{
    //char tmp = cout.fill();
    cout.fill(' ');
    cout << setw(10) << left << "Titel: "<< get_name() << endl;
    cout << setw(10) << left << "Signatur: " << get_signature() << endl;
    cout << setw(10) << left << "Ort:"; Location->print(); cout << endl;
    cout << setw(10) << left << "FSK:" << "freigegeben ab " << get_FSK() << " Jahren" << endl;
    cout << setw(10) << left << "Status: " << get_status();
}