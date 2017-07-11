#include <iostream>

using namespace std;

#include "tlibraryPool.h"

int main()
{
    cout << "hello starting now" << endl;
    
    TLibraryPool LP("data.xml");
    LP.print();
    
    //cout << LP << endl;
    
    cout << endl;

    return 0;
}
