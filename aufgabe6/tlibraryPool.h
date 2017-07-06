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
#include "xml.h"

class TLibraryPool
{
    protected:

    private:
        string Name;
        string Filename;
        TEmployee *Boss;
        vector<TLibrary*> LibraryList;
        vector<TCustomer*> CustomerList;
        ifstream inFile;

    public:
        TLibraryPool(string, TPerson*);
        TLibraryPool(string);
        ~TLibraryPool();

        void add(TLibrary*);
        void add(TCustomer*);
        void print();

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