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
    virtual ~TCD();

    void load(ifstream&);

    virtual void print(ostream&);
    friend ostream& operator<<(ostream&, TCD&);

    bool print_parents = true;
};

#endif
