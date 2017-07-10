#ifndef TTIME_H
#define TTIME_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>

#include "xml.h"

class TTime
{
    private:
        int hh, mm, ss = 0;
        time_t now;
        string myTime;
        void load(ifstream&);
        
    public:
        TTime();
        TTime(int hh, int mm);
        TTime(int hh, int mm, int ss);
        TTime(ifstream&);
        int get_hh() const;
        int get_mm() const;
        int get_ss() const;
        void set_hh(int hh);
        void set_mm(int mm);
        void set_ss(int ss);
        void print();
        friend ostream& operator<<(ostream&, TTime*);
};

#endif