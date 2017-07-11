#ifndef TPRINTEDMEDIUM_H
#define TPRINTEDMEDIUM_H

#include <string>
#include <vector>
#include "xml.h"

#include "tmedium.h"


class TPrintedMedium: virtual public TMedium
{
  private:
    int Pages;
    streampos startPos, endPos;
    bool print_parents = true;
    
  public:
    /**
     * @brief Create printed medium object by parsing from XML
     * @param XML node to import
     */
    TPrintedMedium(ifstream&, streampos);
    void load(ifstream&);
    ~TPrintedMedium();
    virtual void print();
    friend ostream& operator<<(ostream&, TPrintedMedium&);
};

#endif

