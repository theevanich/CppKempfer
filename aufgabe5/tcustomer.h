#ifndef TCUSTOMER_H
#define TCUSTOMER_H

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "tperson.h"

class TCustomer: public TPerson
{
    protected:
        string CustomerNr;

    private:
        void load(ifstream&);

    public:
        TCustomer(ifstream&);
        string get_customerNr() const;
        void set_customerNr(string);
        void print();
};

#endif