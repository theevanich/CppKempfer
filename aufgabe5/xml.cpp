using namespace std;

#include "xml.h"

string parseLine(string line, string tagToBeStriped)
{
    string tagEndBegin = "</";
    size_t tagStartPos = line.find(tagToBeStriped);
    int messageStart = tagStartPos + tagToBeStriped.length();
    size_t messageLength = line.find(tagEndBegin) - messageStart; 
    return line.substr(messageStart, messageLength);
}

streampos findEndPos(ifstream& inFile, string endTag)
{
    string line;
    streampos res;
    // cout << "End Tag to look for: " << endTag << endl;
    while (getline(inFile, line))
    {
        // detect end of child
        if (line.find(endTag) != string::npos)
        {
            res = inFile.tellg();
            break;
        }
    }
    // cout << "End Tag postion at: " << res << endl;
    return res;
}