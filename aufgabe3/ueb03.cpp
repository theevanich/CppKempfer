#include <iostream>

using namespace std;

#include "tdate.h"
#include "tlocation.h"
#include "taddress.h"
#include "tperson.h"
//#include "tmedium.h"
//#include "tlibrary.h"
//#include "tlibrarypool.h"

int main()
{
    TDate D1(17, 11, 1963);

    TLocation L1("Technik", "Computer");
    TLocation L2("Romane", "Krimi");
    TLocation L3("Kinder", "Comics");
    TLocation L4("DVDs", "Horror");

    TAddress A1("Buchallee", "15a", "13315", "Berlin");
    TAddress A2("Schlossstr.", "117", "12077", "Berlin");
    TAddress A3("Muellerstr.", "39", "13309", "Berlin");

    TPerson Leitung("Egon Mustermann", A2, D1);
    TPerson FL1("Peter Mueller", A3, D1);
    TPerson FL2("Erika Mueller", A3, D1);
    TPerson K1("Marion Schulz", A1, D1);
    TPerson K2("Stefan Meier", A2, D1);

    //TMedium M1("Programmieren in C", "PC99", L1, 0, TMedium::ausgeliehen);
    //TMedium M2("Der Hexer", "He83", L2, 12, TMedium::verfuegbar);
    //TMedium M3("Asterix und Obelix", "KC17", L3, 0, TMedium::verfuegbar);
    //TMedium M4("Der Werwolf", "WW175", L4, 16, TMedium::ausgeliehen);

/*     TLibrary LWedding("Wedding", A1, &FL1);
    TLibrary LSteglitz("Steglitz", A2, &FL2);

    TLibraryPool LP("Buechereiverband Berlin", &Leitung);


    LWedding.add(&M1);
    LWedding.add(&M2);

    LSteglitz.add(&M3);
    LSteglitz.add(&M4);

    LP.add(&LWedding);
    LP.add(&LSteglitz);
    LP.add(&K1);
    LP.add(&K2);

    LP.print();
    cout << endl; */

    return 0;
}