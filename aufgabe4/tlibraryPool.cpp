// class TLibraryPool

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

#include "tlibraryPool.h"

TLibraryPool::TLibraryPool(string n, TPerson* p)
:Name(n), Boss(p) {}

TLibraryPool::TLibraryPool(string xmlFile)
:Filename(xmlFile)
{
    inFile.open(Filename.c_str());
    string tagToLookFor[] = {"<Name>", "<Chairman>", "<Library>", "<Customer>"};
    int maxTag = sizeof(tagToLookFor) / sizeof(*tagToLookFor);
    string line;

    // to be sure if file is found and is opened
    if (inFile.is_open())
    {
        getline(inFile, line);
        //cout << "first Line: " << line << endl; 
        // check if xml format valid
        if (line.find("<LibraryPool>") != string::npos) // here prolly same with >= 0
        {
            while (getline(inFile, line))
            {
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
                        switch(i)
                        {
                             // find Pool name > save directly
                            case 0:
                                Name = parseLine(line, tagToLookFor[i]);
                                inFile.close();
                                break;
                            // find Chairman > create TPerson and let it load
                            case 1:
                                break;
                            // find Library > create TPerson and let it load then add to vector
                            case 2:
                                break;
                            // find Customer > create TPerson and let it load
                            case 3:
                                break;
                            default:
                                cout << "Nothing found..." << endl;
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

TLibraryPool::~TLibraryPool() {}

void TLibraryPool::add(TPerson* customer)
{
    CustomerList.push_back(customer);
}

void TLibraryPool::add(TLibrary* lib)
{
    LibraryList.push_back(lib);
}

string TLibraryPool::parseLine(string line, string tagToBeStriped)
{
    string tagEndBegin = "</";
    size_t tagStartPos = line.find(tagToBeStriped);
    //size_t tagEndBeginPos = line.find(tagEndBegin);
    
/*     cout << "tagToBeStriped:" << tagToBeStriped << endl;
    cout << "Line: " << line << endl;
    cout << "tagStartPos: " << tagStartPos << endl << "tagEndBeginPos:" << tagEndBeginPos << endl; 
    cout << "tagStartPos+tagToBeStriped.length(): " << tagStartPos+tagToBeStriped.length() << endl; */
    
    int messageLength = line.length() - ((tagStartPos + 1) + (tagToBeStriped.length() * 2) + 1);
    int messageStart = tagStartPos+tagToBeStriped.length();
    
    //cout << line.substr(a, l) << endl;
    
    return line.substr(messageStart, messageLength);

}

void TLibraryPool::print()
{
    cout << endl;
    cout << get_name() << endl;
    cout << "Leitung" << endl;
    Boss->print();
    cout << "\nZum Buecherverband gehoeren " << LibraryList.size() << " Filialen" << endl;
    for(unsigned i = 0; i < LibraryList.size(); i++)
    {
        cout << endl;
        LibraryList.at(i)->print();
        cout << endl;
    }
    cout << "Der Buecherverband hat " << CustomerList.size() << " Kunde/Kunden" << endl;
    for(unsigned j = 0; j < LibraryList.size(); j++)
    {
        cout << endl;
        CustomerList.at(j)->print();
        cout << endl;
    }
}

void TLibraryPool::set_name(string n) {Name = n;}
void TLibraryPool::set_boss(TPerson* b) {Boss = b;}
void TLibraryPool::set_customer(vector<TPerson*> cus) {CustomerList = cus;}
void TLibraryPool::set_libraryList(vector<TLibrary*>lib) {LibraryList = lib;}

string TLibraryPool::get_name() const {return Name;}
TPerson* TLibraryPool::get_boss() const {return Boss;}
vector<TPerson*>TLibraryPool::get_customerList() const {return CustomerList;}
vector<TLibrary*>TLibraryPool::get_libraryList() const {return LibraryList;}