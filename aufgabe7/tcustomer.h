#ifndef TCUSTOMER_H
#define TCUSTOMER_H

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>

#include "tperson.h"
#include "tloan.h"
#include "tlist.h"
#include "xml.h"

class TCustomer: virtual public TPerson
{
    protected:
        string CustomerNr;

    private:
        streampos endPos;
        TList<TLoan*> LoanList;
        
    public:
        TCustomer(ifstream&, streampos);
        void load(ifstream&);
        virtual ~TCustomer();
        virtual void print();
        string get_customerNr() const;
        void set_customerNr(string);
        void add(TLoan*);
};

#endif
