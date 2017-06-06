#include <iostream>

using namespace std;

#include "tlibraryPool.h"

int main()
{
    TLibraryPool LP("data.xml");

    //LP.print();
    cout << LP.get_name();
    cout << endl;

    return 0;
}