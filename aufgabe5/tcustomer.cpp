// class TCustomer
using namespace std;

#include "tcustomer.h"

TCustomer::TCustomer(ifstream& inFile)
{
    load(inFile);
}

void TCustomer::load(ifstream& inFile)
{
    string tagToLookFor[] = {"<Name>", "<Birthday>", "<Address>", "<CustomerNr>"};
    int maxTag = sizeof(tagToLookFor) / sizeof(*tagToLookFor);
    string line;
    
    while (getline(inFile, line))
    {
        // detect end of person to prevent any problems
        if (line.find("</Customer>") != string::npos)
        {
            break;
        }
        for(int i = 0; i < maxTag; i++)
        {
            if (line.find(tagToLookFor[i]) != string::npos )
            {
                switch(i)
                {
                     // find Pool name > save directly
                    case 0:
                        Name = parseLine(line, tagToLookFor[i]);
                        break;
                    // find Birthday > create Birthday and let it load
                    case 1:
                        Birthday = new TDate(inFile);
                        break;
                    // find Address > create Address and let it load then add to vector
                    case 2:
                        Address = new TAddress(inFile);
                        break;
                    case 3:
                        CustomerNr = parseLine(line, tagToLookFor[i]);
                        break;
                    default:
                        cout << "Nothing found... in Person" << endl;
                        break;
                }
            }
        }
    }
}
