#ifndef TLIBRARYPOOL_H
#define TLIBRARYPOOL_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "tdate.h"
#include "tlocation.h"
#include "taddress.h"
#include "tperson.h"
#include "tmedium.h"
#include "tlibrary.h"
#include "temployee.h"
#include "tcustomer.h"
#include "tlist.h"
#include "xml.h"

#ifdef TLOAN_H
// forward declaration to break circular dependency
class TLoan;
#else
#include "tloan.h"
#endif

class TLibraryPool
{
    protected:

    private:
        string Name;
        string Filename;
        TEmployee *Boss;
        vector<TLibrary*> LibraryList;
        vector<TCustomer*> CustomerList;
        TList<TLoan*> LoanList;
        ifstream inFile;

    public:
        TLibraryPool(string, TPerson*);
        TLibraryPool(string);
        ~TLibraryPool();
        void add(TLibrary*);
        void add(TCustomer*);
        void add(TLoan*);
        void print();
        friend ostream& operator<<(ostream&, TLibraryPool&);
        
        TCustomer* getCustomerByNr(string);
        TMedium* getMediumBySignature(string);

        void set_name(string);
        void set_boss(TEmployee*);
        void set_customer(vector<TCustomer*>);
        void set_libraryList(vector<TLibrary*>);

        string get_name() const;
        TEmployee* get_boss() const;
        vector <TLibrary*> get_libraryList() const;
        vector <TCustomer*> get_customerList() const;
};
#endif // TLIBRARYPOOL
