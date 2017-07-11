#ifndef TPERSON_H
#define TPERSON_H

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "taddress.h"
#include "tdate.h"
#include "xml.h"

class TPerson
{
    protected:
        string Name;
        TAddress *Address;
        TDate *Birthday;
        
    private:
        streampos startPos, endPos;
        void load(ifstream&);
        
    public:
        TPerson(string, TAddress*, TDate*);
        TPerson(ifstream&, streampos);
        virtual ~TPerson();
        virtual void print();
        streampos get_fpos() const;
        string get_name() const;
        TAddress* get_address() const;
        TDate* get_birthday() const;
        void set_name(string);
        void set_address(TAddress*);
        void set_birthday(TDate*);
};

#endif