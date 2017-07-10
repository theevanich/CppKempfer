#ifndef TDATE_H
#define TDATE_H

#include <fstream>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include "xml.h"

class TDate
{
    protected:
        
    private:
        int dd, mm, yyyy;
        time_t now;
        string date;
        void load(ifstream&);
        
    public:
        TDate();
        TDate(ifstream&);
        TDate(int dd, int mm, int yyyy);
        ~TDate();
        //int get_dd() const;
        //int get_mm() const;
        //int get_yyyy() const;
        //void set_dd(int dd);
        //void set_mm(int mm);
        //void set_yyyy(int yyyy);
        static bool isLeapYear(int);
        static uint8_t daysPerMonth(int, int);
        friend TDate* operator+(TDate date, int days);
        void print();
        friend ostream& operator<<(ostream&, TDate*); 
};

#endif