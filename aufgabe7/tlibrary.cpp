// class TLibrary
using namespace std;

#include "tlibrary.h"

// TLibrary::TLibrary(string name, TAddress* address, TEmployee* Person )
// :Name(name), address(address), Manager(Person) {}

TLibrary::TLibrary(ifstream& inFile)
{
    load(inFile);
}

void TLibrary::load(ifstream& inFile)
{
    string tagToLookFor[] = {"<Name>", "<Address>", "<Manager>", "<Book>", "<Magazine>", "<DVD>", "<CD>", "<Audiobook>"};
    string endTag[] = {"</Name>", "</Address>", "</Manager>", "</Book>", "</Magazine>", "</DVD>", "</CD>", "</Audiobook>"};
    int maxTag = sizeof(tagToLookFor) / sizeof(*tagToLookFor);
    string line;
    streampos startPos, endPos;
    
    while (getline(inFile, line))
    {
        // detect end of Library to prevent any problems
        if (line.find("</Library>") != string::npos)
        {
            // cout << "End library" << endl;
            break;
        }
        for(int i = 0; i < maxTag; i++)
        {
            if (line.find(tagToLookFor[i]) != string::npos )
            {
                //find child
                startPos = inFile.tellg();
                endPos = findEndPos(inFile, endTag[i]);
                inFile.seekg(startPos);
                switch(i)
                {
                    case 0:
                        Name = parseLine(line, tagToLookFor[i]);
                        break;
                    case 1:
                        address = new TAddress(inFile);
                        break;                        
                    case 2:
                        Manager = new TEmployee(inFile, endPos);
                        break;
                    case 3:
                        add(new TBook(inFile, endPos));
                        break;
                    case 4:
                        add(new TMagazine(inFile, endPos));
                        break;
                    case 5:
                        add(new TDVD(inFile, endPos));
                        break;  
                    case 6:
                        add(new TCD(inFile, endPos));
                        break;
                    case 7:
                        add(new TAudioBook(inFile, endPos));
                        break;                        
                    default:
                        cout << "Nothing found... in Library" << endl;
                        break;
                }
            }
        }
    }
}

TLibrary::~TLibrary()
{
    for(unsigned i = 0; i < MediumList.size(); i++)
    {
        delete MediumList[i];
    }
    delete address;
    delete Manager;
}

void TLibrary::add(TMedium *medium)
{
    MediumList.push_back(medium);
}

TMedium* TLibrary::getMediumBySignature(string Signature)
{
    for (uint16_t i=0; i<MediumList.size(); i++)
    {
        TMedium* medium = MediumList[i];
        if (medium != 0 && medium->get_signature().compare(Signature) == 0)
        {
            // great success
            return medium;
        }
    }
    // search unsuccessful
    return nullptr;
}

void TLibrary::print()
{
    cout << "Buecherei Filiale " << get_name() << endl;
    address->print(); cout << endl;
    cout << "Filialleiter: ";
    Manager->print();
    cout << endl;
    cout << "Es stehen " << MediumList.size() << " Medium/Medien zur Verfuegung:" << endl;
    for(unsigned i = 0; i < MediumList.size(); i++)
    {
        cout << endl;
        cout << "Medium Nr. " << i+1 << endl;
        MediumList.at(i)->print();
        cout << endl;
    }
}

string TLibrary::get_name() const {return Name;}
TAddress* TLibrary::get_address() const {return address;}
TEmployee* TLibrary::get_manager() const {return Manager;}