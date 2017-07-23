#ifndef TMEDIUM_H
#define TMEDIUM_H

#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

#include "tlocation.h"
#include "xml.h"

class TMedium
{
    protected:
        
    public:
        enum Status {verfuegbar = 1, ausgeliehen, bestellt, reserviert};

    private:
        string Name;
        string Signature;
        TLocation* Location;
        int FSK = 0;
        Status status = TMedium::verfuegbar;
        void load(ifstream&);
        streampos startPos, endPos;
        
    public:
        TMedium();
        virtual ~TMedium();
        // TMedium(string, string, TLocation*, int, Status);
        TMedium(ifstream&, streampos);

        virtual void print(ostream&);
        friend ostream& operator<<(ostream&, TMedium&);
        
        void set_status(Status);
        void set_status(int);
        void set_name(string);
        void set_signature(string);
        void set_FSK(int);
        void set_location(TLocation*);
        
        streampos get_fpos() const;
        string get_status() const;
        string get_name() const;
        string get_signature() const;
        int get_FSK() const;    
        
};

#endif
