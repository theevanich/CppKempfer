#ifndef TLIBRARY_H
#define TLIBRARY_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "tdate.h"
#include "tlocation.h"
#include "taddress.h"
#include "tperson.h"
#include "tmedium.h"
#include "temployee.h"
#include "tcustomer.h"
#include "tprintedmedium.h"
#include "tbook.h"
#include "tmagazine.h"
#include "tdvd.h"
#include "tcd.h"
#include "taudiobook.h"
#include "xml.h"

class TLibrary
{
    protected:
        
    private:
        string Name;
        TAddress* address;
        TEmployee* Manager;
        vector<TMedium*>MediumList;
        void load(ifstream&);

    public:
        TLibrary(string, TAddress*, TEmployee*);
        TLibrary(ifstream&);
        ~TLibrary();
        TMedium* getMediumBySignature(string);
        void setName(string);
        void setAddress(TAddress*);
        void setManager(TEmployee*);
        void setMediumList(vector<TMedium*>);
        void print();    

        string get_name() const;
        TAddress* get_address() const;
        TEmployee* get_manager() const;
        vector<TMedium*>getMediumList() const;
        void add(TMedium*);

};

#endif // TLibrary_h