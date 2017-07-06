#ifndef TCD_H
#define TCD_H

#include <string>
#include <vector>
#include "xml.h"

#include "tmedium.h"


class TCD: virtual public TMedium
{
  private:
    string Interpret;
    int Tracks;
    streampos startPos, endPos;

  public:

    /**
     * @brief Create CD object by parsing from XML
     * @param XML node to import
     */
    TCD(ifstream&, streampos);
    void load(ifstream&);
    virtual ~TCD();
    void print();
};

#endif
