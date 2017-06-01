#include <iostream>

using namespace std;

#include "tlibrarypool.h"

int main()
{
    TLibraryPool LP("data.xml");

    LP.print();
    cout << endl;

    return 0;
}