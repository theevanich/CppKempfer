// class tdate
using namespace std;

#include "tdate.h"

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

TDate::TDate(ifstream& inFile)
{
    load(inFile);
}

TDate::~TDate() {}

void TDate::load(ifstream& inFile)
{
    string tagToLookFor[] = {"<Day>", "<Month>", "<Year>"};
    int maxTag = sizeof(tagToLookFor) / sizeof(*tagToLookFor);
    string line;
    
    while (getline(inFile, line))
    {
        // detect end of Date to prevent any problems
        if (line.find("</Date>") != string::npos)
        {
            break;
        }
        for(int i = 0; i < maxTag; i++)
        {
            if (line.find(tagToLookFor[i]) != string::npos )
            {
                switch(i)
                {
                    case 0:
                        dd = atoi(parseLine(line, tagToLookFor[i]).c_str());
                        break;
                    case 1:
                        mm = atoi(parseLine(line, tagToLookFor[i]).c_str());
                        break;
                    case 2:
                        yyyy = atoi(parseLine(line, tagToLookFor[i]).c_str());
                        break;
                    default:
                        cout << "Nothing found... in Date" << endl;
                        break;
                }
            }
        }
    }
}

void TDate::print()
{
    cout.fill('0');
    cout << setw(2) << right << dd << '.' << setw(2) << right << mm << '.' << yyyy;
}

bool TDate::isLeapYear(int year)
{
    return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
}


uint8_t TDate::daysPerMonth(int month, int year)
{
    static const uint8_t dayCount[] =
    {
        31, // january
        28, // february
        31, // march
        30, // april
        31, // may
        30, // june
        31, // july
        31, // august
        30, // september
        31, // october
        30, // november
        31, // december
    };

    return ((month == 2) && isLeapYear(year)) ? 29 : dayCount[month-1];
}


/**
 * @brief Creates a new date object by \
 *        adding or subtracting a given number of days
 * @param days Number of days to add/subtract from date
 */

TDate* operator+(TDate date, int days)
{
    int day = date.dd;
    int month = date.mm;
    int year = date.yyyy;
    while (days > 0)
    {
        days--;
        day++;
        if (day > TDate::daysPerMonth(month, year))
        {
            day = 1;
            month++;
            if (month > 12)
            {
                month = 1;
                year++;
            }
        }
    }
    cout << "returning new date: " << setw(2) << right << day << '.' << setw(2) << right << month << '.' << year << endl;
    return new TDate(day, month, year);
}


ostream& operator<<(ostream& out, TDate* d)
{
    out.fill('0');
    out << setw(2) << right << d->dd << '.' << setw(2) << right << d->mm << '.' << d->yyyy;
    return out;
}