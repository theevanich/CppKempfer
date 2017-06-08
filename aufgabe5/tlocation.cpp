// class TLocation
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

#include "tlocation.h"

TLocation::TLocation()
{
    section = "Buero";
    rack = "Fach zum Einsortieren";
}

TLocation::TLocation(ifstream& inFile)
{
    load(inFile);
}

TLocation::TLocation(string section, string rack)
{
    this->section = section;
    this->rack = rack;
}

void TLocation::load(ifstream& inFile)
{
    string tagToLookFor[] = {"<Section>", "<Rack>"};
    int maxTag = sizeof(tagToLookFor) / sizeof(*tagToLookFor);
    string line;
    
    while (getline(inFile, line))
    {
        // detect end of Location to prevent any problems
        if (line.find("</Location>") != string::npos)
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
                        section = parseLine(line, tagToLookFor[i]);
                        break;
                    case 1:
                        rack = parseLine(line, tagToLookFor[i]);
                        break;
                    default:
                        cout << "Nothing found...in Location    " << endl;
                        break;
                }
            }
        }
    }
}

string TLocation::parseLine(string line, string tagToBeStriped)
{
    string tagEndBegin = "</";
    size_t tagStartPos = line.find(tagToBeStriped);
    int messageLength = line.length() - ((tagStartPos + 1) + (tagToBeStriped.length() * 2) + 1);
    int messageStart = tagStartPos+tagToBeStriped.length(); 
    return line.substr(messageStart, messageLength);
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

