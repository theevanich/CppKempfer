#include <iostream>

using namespace std;

#include "tdate.h"
#include "tlocation.h"

int main()
{
   TLocation L1, L2("Technik", "Computer"); // Technik-Abteilung im Computer-Regal

   cout << "Klasse TLocation:" << endl;
   cout << "Standardkonstruktor fuer neue Buecher:    ";     L1.print();   cout << endl;
   cout << "Konstruktor Technik-Abt., Computer-Regal: ";     L2.print();   cout << endl;


   return 0;
}