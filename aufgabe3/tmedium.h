#ifndef TMEDIUM_H
#define TMEDIUM_H

#include "taddress.h"

class TMedium
{
    private:
        string Name;
        string Signature;
        TLocation Location;
        int FSK;
        Status status;
        
    public:
        enum Status {verfuegbar, ausgeliehen, bestellt, reserviert};
        
};

#endif