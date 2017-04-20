// class tdate

#include <iostream>
#include <ctime>
#include <iomanip>
#include "tdate.h"
using namespace std;

TDate::TDate()
{
    now = time(0);
    tm *ltm = localtime(&now);
    dd = ltm->tm_mday;
    mm = 1 + ltm->tm_mon;
    yyyy = 1900 + ltm->tm_year;
}

TDate::TDate(int dd, int mm, int yyyy)
{
    this->dd = dd;
    this->mm = mm;
    this->yyyy = yyyy;
}

void TDate::print()
{
    cout << setfill('0');
    cout << setw(2) << dd << '.' << setw(2) << mm << '.' << yyyy;
}