// class TLibraryPool
using namespace std;

#include "tlibraryPool.h"

// TLibraryPool::TLibraryPool(string n, TPerson* p)
// :Name(n), Boss(p) {}

TLibraryPool::TLibraryPool(string xmlFile)
:Filename(xmlFile)
{
    inFile.open(Filename.c_str());
    string tagToLookFor[] = {"<Name>", "<Chairman>", "<Library>", "<Customer>"};
    string endTag[] = {"</Name>", "</Chairman>", "</Library>", "</Customer>"};
    int maxTag = sizeof(tagToLookFor) / sizeof(*tagToLookFor);
    string line;
    streampos startPos, endPos;
    // to be sure if file is found and is opened
    if (inFile.is_open())
    {
        getline(inFile, line);
        // check if xml format valid
        if (line.find("<LibraryPool>") != string::npos) // here prolly same with >= 0
        {
            while (getline(inFile, line))
            {
                // cout << "Line: " << line << endl; 
                // detect end of xml to prevent any problems
                if (line.find("</LibraryPool>") != string::npos)
                {
                    cout << "end of xml... bye" << endl;
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
                        // cout << "case: " << tagToLookFor[i] << "in line: " << line << endl;
                        // cout << "startPos: " << startPos << ", endPos: " << endPos << endl;
                        switch(i)
                        {
                             // find Pool name > save directly
                            case 0:
                                Name = parseLine(line, tagToLookFor[i]);
                                break;
                            // find Chairman > create TPerson and let it load
                            case 1:
                                Boss = new TEmployee(inFile, endPos);                                 
                                break;
                            // find Library > create TPerson and let it load then add to vector
                            case 2:
                                add(new TLibrary(inFile));
                                break;
                            case 3:
                                add(new TCustomer(inFile, endPos));
                                break;
                            default:
                                cout << "Nothing found... in LibraryPool" << endl;
                                break;
                        }
                    }
                }
            }
        }
    }
    else
    {
        cout << "Error opening file!" << endl;
    }  
    cout << "Closing file" << endl;
    inFile.close();
}

TLibraryPool::~TLibraryPool()
{
    for(unsigned i = 0; i < LibraryList.size(); i++)
    {
        delete LibraryList[i];
    }   
    for(unsigned i = 0; i < CustomerList.size(); i++)
    {
        delete CustomerList[i];
    }
    delete Boss;        
}

void TLibraryPool::add(TCustomer* customer)
{
    CustomerList.push_back(customer);
}

void TLibraryPool::add(TLibrary* lib)
{
    LibraryList.push_back(lib);
}

void TLibraryPool::print()
{
    cout << endl;
    cout << get_name() << endl;
    cout << "Leitung: ";
    Boss->print();
    cout << endl;
    cout << "\nZum Buecherverband gehoeren " << LibraryList.size() << " Filialen" << endl;
    for(unsigned i = 0; i < LibraryList.size(); i++)
    {
        cout << endl;
        LibraryList.at(i)->print();
        cout << endl;
    }
    cout << endl;
    cout << "Der Buecherverband hat " << CustomerList.size() << " Kunde/Kunden" << endl;
    for(unsigned j = 0; j < CustomerList.size(); j++)
    {
        cout << endl;
        CustomerList.at(j)->print();
    }
    cout << endl;
}

void TLibraryPool::set_name(string n) {Name = n;}
void TLibraryPool::set_boss(TEmployee* b) {Boss = b;}
void TLibraryPool::set_customer(vector<TCustomer*> cus) {CustomerList = cus;}
void TLibraryPool::set_libraryList(vector<TLibrary*>lib) {LibraryList = lib;}

string TLibraryPool::get_name() const {return Name;}
TEmployee* TLibraryPool::get_boss() const {return Boss;}
vector<TCustomer*>TLibraryPool::get_customerList() const {return CustomerList;}
vector<TLibrary*>TLibraryPool::get_libraryList() const {return LibraryList;}