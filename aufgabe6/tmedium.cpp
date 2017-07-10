// class TMedium

using namespace std;

#include "tmedium.h"

// TMedium::TMedium(string Name, string Signature, TLocation* Location, int FSK, Status status)
// :Name(Name), Signature(Signature), Location(Location), FSK(FSK)
// {
    // set_status(status);
// }

TMedium::~TMedium()
{
    cout << "Das Medium " << Name << " mit der Signatur " << Signature << " wird vernichtet!" << endl;
}

TMedium::TMedium(ifstream& inFile, streampos endPos)
:endPos(endPos)
{
    load(inFile);
}

void TMedium::load(ifstream& inFile)
{
    string tagToLookFor[] = {"<Title>", "<Signatur>", "<Location>", "<FSK>"};
    int maxTag = sizeof(tagToLookFor) / sizeof(*tagToLookFor);
    string line;
    startPos = inFile.tellg();
    // cout << "Medium Start Position: " << startPos << endl;
    while (getline(inFile, line))
    {
        if (inFile.tellg() == endPos)
        {
            cout << "END OF Medium DETECTED" << endl;
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
                        // cout << "Title found: " << Name << endl;
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
                    default:
                        cout << "Nothing found... in Medium" << endl;
                        break;
                }
            }
        }
    }
}


void TMedium::set_status(int statusInt)
{
    switch(statusInt)
    {
        case 1:
            status = TMedium::verfuegbar;
            break;
        case 2:
            status = TMedium::ausgeliehen;
            break;
        case 3:
            status = TMedium::bestellt;
            break;
        case 4:
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

streampos TMedium::get_fpos() const {return startPos;}
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
    cout << *this;
}

ostream& operator<<(ostream& out, TMedium& tmedium)
{
    out.fill(' ');
    out << setw(15) << left << "Titel: "<< tmedium.get_name() << endl;
    out << setw(15) << left << "Signatur: " << tmedium.get_signature() << endl;
    out << setw(15) << left << "Ort:"; tmedium.Location->print(); out << endl;
    out << setw(15) << left << "FSK:" << "freigegeben ab " << tmedium.get_FSK() << " Jahren" << endl;
    out << setw(15) << left << "Status: " << tmedium.get_status();
    return out;
}