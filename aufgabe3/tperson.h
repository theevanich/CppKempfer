#ifndef TPERSON_H
#define TPERSON_H

#include "taddress.h"
#include "tdate.h"

class TPerson
{
    private:
        std::string Name;
        TAddress Address;
        TDate Birthday;
        
    public:
        TPerson(std::string, TDate, TAddress);
        std::string get_name() const;
        TAddress get_address() const;
        TDate get_birthday() const;
        void set_name(std::string);
        void set_address(TAddress);
        void set_birthday(TDate);
        void print();
        
    
};

#endif
