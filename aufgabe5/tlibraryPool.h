#ifndef TLIBRARYPOOL_H
#define TLIBRARYPOOL_H

#include <fstream>
#include <vector>
#include "tdate.h"
#include "tlocation.h"
#include "taddress.h"
#include "tperson.h"
#include "tmedium.h"
#include "tlibrary.h"

class TLibraryPool
{
    protected:
        string parseLine(string, string);

    private:
        string Name;
        string Filename;
        TPerson *Boss;
        vector<TLibrary*> LibraryList;
        vector<TPerson*> CustomerList;
        ifstream inFile;

    public:
        TLibraryPool(string, TPerson*);
        TLibraryPool(string);
        ~TLibraryPool();

        void add(TLibrary*);
        void add(TPerson*);
        void print();

        void set_name(string);
        void set_boss(TPerson*);
        void set_customer(vector<TPerson*>);
        void set_libraryList(vector<TLibrary*>);

        string get_name() const;
        TPerson* get_boss() const;
        vector <TLibrary*> get_libraryList() const;
        vector <TPerson*> get_customerList() const;
};
#endif // TLIBRARYPOOL