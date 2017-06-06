#include <iostream>

using namespace std;

#include "tlibraryPool.h"

int main()
{
    TLibraryPool LP("data.xml");

    LP.print();
    // cout << LP.get_name() << endl;
    // cout << LP.get_boss()->get_name() << endl;
    // LP.get_boss()->get_address()->print();
    // LP.get_boss()->get_birthday()->print();
    cout << endl;

    return 0;
}