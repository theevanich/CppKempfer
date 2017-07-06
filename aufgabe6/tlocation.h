#ifndef TLOCATION_H
#define TLOCATION_H

#include <fstream>
#include <iostream>
#include <string>

#include "xml.h"

class TLocation
{
    protected:
        
    private:
        string section;
        string rack;
        void load(ifstream&);
        
    public:
        TLocation();
        TLocation(ifstream&);
        TLocation(string section, string rack);
        void print();
        string get_section() const;
        string get_rack() const;
        void set_section(string section);
        void set_rack(string section);
};

#endif