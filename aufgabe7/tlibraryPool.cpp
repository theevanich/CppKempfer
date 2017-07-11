// class TLibraryPool
using namespace std;

#include "tlibraryPool.h"

// TLibraryPool::TLibraryPool(string n, TPerson* p)
// :Name(n), Boss(p) {}

TLibraryPool::TLibraryPool(string xmlFile)
:Filename(xmlFile)
{
    inFile.open(Filename.c_str());
    string tagToLookFor[] = {"<Name>", "<Chairman>", "<Library>", "<Customer>", "<Loan>"};
    string endTag[] = {"</Name>", "</Chairman>", "</Library>", "</Customer>", "</Loan>"};
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
                            case 4:
                                add(new TLoan(inFile));
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
    for(vector<TCustomer*>::iterator k = CustomerList.begin();
        k != CustomerList.end();
        k++)
    {
        delete *k;
    }

    for (vector<TLibrary*>::iterator k = LibraryList.begin();
         k != LibraryList.end();
         k++)
    {
        delete *k;
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

void TLibraryPool::add(TLoan* loan)
{
    LoanList.push_back(loan);
    loan->setCustomer(getCustomerByNr(loan->get_customerNumber()));
    loan->setMedium(getMediumBySignature(loan->get_signatur()));
    loan->getMedium()->set_status(2);
    getCustomerByNr(loan->get_customerNumber())->add(loan);
}

void TLibraryPool::print()
{
    cout << *this;
}

ostream& operator<<(ostream& out, TLibraryPool& librarypool)
{
    out << endl;
    out << librarypool.get_name() << endl;
    out << "Leitung: ";
    librarypool.Boss->print();
    out << endl;

    out << "\nZum Buecherverband gehoeren " << librarypool.LibraryList.size() << " Filialen" << endl;
    for (vector<TLibrary*>::iterator k = librarypool.LibraryList.begin();
         k != librarypool.LibraryList.end();
         k++)
    {
        out << endl;
        (*k)->print();
        out << endl;
    }
    out << endl;

    out << "Der Buecherverband hat " << librarypool.CustomerList.size() << " Kunde/Kunden" << endl;
    for (vector<TCustomer*>::iterator k = librarypool.CustomerList.begin();
         k != librarypool.CustomerList.end();
         k++)
    {
        out << endl;
        (*k)->print();
    }
    out << endl;

    out << "Folgende " << librarypool.LoanList.size() << " Medien sind ausgeliehen:" << endl;
    out << endl;
    
    for (TList<TLoan*>::Iterator k = librarypool.LoanList.begin();
         k != librarypool.LoanList.end();
         k++)
    {
        out << endl;
        (*k)->print();
    }
    
    return out;
}

TCustomer* TLibraryPool::getCustomerByNr(string CustomerNr)
{
    for (uint8_t i=0; i<CustomerList.size(); i++)
    {
        TCustomer *c = CustomerList[i];
        if (c != nullptr && c->get_customerNr().compare(CustomerNr) == 0)
        {
            // comparison is a match!
            return c;
        }
    }

    // search was unsuccessful
    return nullptr;
}

TMedium* TLibraryPool::getMediumBySignature(string Signature)
{
    for (uint8_t i=0; i<LibraryList.size(); i++)
    {
        TLibrary* library = LibraryList[i];
        if (library != nullptr)
        {
            TMedium* medium = library->getMediumBySignature(Signature);
            if (medium != nullptr)
            {
                // great success
                return medium;
            }
        }
    }
    // search was unsuccessful
    return nullptr;
}

void TLibraryPool::set_name(string n) {Name = n;}
void TLibraryPool::set_boss(TEmployee* b) {Boss = b;}
void TLibraryPool::set_customer(vector<TCustomer*> cus) {CustomerList = cus;}
void TLibraryPool::set_libraryList(vector<TLibrary*>lib) {LibraryList = lib;}

string TLibraryPool::get_name() const {return Name;}
TEmployee* TLibraryPool::get_boss() const {return Boss;}
vector<TCustomer*>TLibraryPool::get_customerList() const {return CustomerList;}
vector<TLibrary*>TLibraryPool::get_libraryList() const {return LibraryList;}
