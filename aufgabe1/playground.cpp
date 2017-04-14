#include <iostream>
#include <ctime>
#include <string>
#include "tdate.h"
#include "ttime.h"

using namespace std;

int main()
{
    string maddog;
    // current date/time based on current system
    time_t now = time(0);
    tm *ltm = localtime(&now);

    // print various components of tm structure.
    cout << "Year:" << 1900 + ltm->tm_year<<endl;
    cout << "Month: "<< 1 + ltm->tm_mon<< endl;
    cout << "Day: "<<  ltm->tm_mday << endl;
    cout << "Time: "<< 1 + ltm->tm_hour << ":";
    cout << 1 + ltm->tm_min << ":";
    cout << 1 + ltm->tm_sec << endl;
    
    cout << maddog << endl;
    
    TDate D1, D2(1, 5, 2017);
    TTime T1, T2(6, 32, 27), T3(17, 45);
    cout << "\nKlasse TDate:" << endl;
    cout << "Standardkonstruktor Heutiges Datum (D1):     ";   D1.print();   cout << endl;
    cout << "Konstruktor         Tag der Arbeit (D2):     ";   D2.print();   cout << endl;

    cout << "\nKlasse TTime:" << endl;
    cout << "Standardkonstruktor Aktuelle Uhrzeit (T1):   ";   T1.print();   cout << endl;
    cout << "Konstruktor         Zeit zum Aufstehen (T2): ";   T2.print();   cout << endl;
    cout << "Konstruktor         Uebungsbeginn (T3):      ";   T3.print();   cout << endl;
    
    return 0;
}

