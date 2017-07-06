#ifndef XML_H
#define XML_H

#include <iostream>
#include <fstream>
#include <string>

string parseLine(string line, string tagToBeStriped);
streampos findEndPos(ifstream&, string);

#endif //