// class TPerson
using namespace std;

#include "tperson.h"

TPerson::TPerson(string Name, TAddress* Address, TDate*Birthday)
:Name(Name), Address(Address), Birthday(Birthday) {}

TPerson::TPerson(ifstream& inFile)
{
    load(inFile);
}

void TPerson::load(ifstream& inFile)
{
    string tagToLookFor[] = {"<Name>", "<Birthday>", "<Address>"};
    int maxTag = sizeof(tagToLookFor) / sizeof(*tagToLookFor);
    string line;
    int j = 0;
    while (getline(inFile, line))
    {
        if (j == maxTag)
            break;
        for(int i = 0; i < maxTag; i++)
        {
            if (line.find(tagToLookFor[i]) != string::npos)
            {
                switch(i)
                {
                     // find Pool name > save directly
                    case 0:
                        Name = parseLine(line, tagToLookFor[i]);
                        j++;
                        break;
                    // find Birthday > create Birthday and let it load
                    case 1:
                        Birthday = new TDate(inFile);
                        j++;
                        break;
                    // find Address > create Address and let it load then add to vector
                    case 2:
                        Address = new TAddress(inFile);
                        j++;
                        break;
                    default:
                        cout << "Nothing found... in Person" << endl;
                        break;
                }
            }
        }
    }
}

TPerson::~TPerson()
{
    cout << "Die Person " << Name << " wird vernichtet!" << endl;
    delete Address;
    delete Birthday;
}

string TPerson::get_name() const {return Name;}
TAddress* TPerson::get_address() const {return Address;}
TDate* TPerson::get_birthday() const {return Birthday;}

void TPerson::set_name(string Name) {this->Name = Name;}
void TPerson::set_birthday(TDate* Birthday) {this->Birthday = Birthday;}
void TPerson::set_address(TAddress* Address) {this->Address = Address;}

void TPerson::print()
{
    cout << Name;
    Address->print();
    cout << "* ";
    Birthday->print();
    cout << endl;
}
