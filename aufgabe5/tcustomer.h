#ifndef TCUSTOMER_H
#define TCUSTOMER_H

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

#include "tperson.h"
#include "xml.h"

class TCustomer: virtual public TPerson
{
    protected:
        string CustomerNr;

    private:
        streampos endPos;
        
    public:
        TCustomer(ifstream&, streampos);
        void load(ifstream&);
        virtual ~TCustomer();
        virtual void print();
        string get_customerNr() const;
        void set_customerNr(string);
};

#endif