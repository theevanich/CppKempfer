// class TTime

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

#include "ttime.h"

TTime::TTime()
{
    now = time(0);
    tm *ltm = localtime(&now);
    hh = ltm->tm_hour;
    mm = ltm->tm_min;
    ss = ltm->tm_sec;
}

TTime::TTime(int hh, int mm)
{
    this->hh = hh;
    this->mm = mm;
    ss = 0;
}

TTime::TTime(int hh, int mm, int ss)
{
    this->hh = hh;
    this->mm = mm;
    this->ss = ss;
}

int TTime::get_hh() const
{
    return hh;
}


int TTime::get_mm() const
{ 
    return mm;
}

int TTime::get_ss() const
{
    return ss;
}

void TTime::set_hh(int hh)
{
    this->hh = hh;
}

void TTime::set_mm(int mm)
{
    this->mm = mm;
}

void TTime::set_ss(int ss)
{
    this->ss = ss;
}

void TTime::print()
{
    cout << setfill('0');
    cout << setw(2) << hh << ':' << setw(2) << mm << ':' << setw(2) << ss;
}