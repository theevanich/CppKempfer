
#ifndef TMAGAZINE_H
#define TMAGAZINE_H

#include <string>
#include <vector>
#include "xml.h"

#include "tprintedmedium.h"


class TMagazine: public TPrintedMedium
{
  private:
    string Designer;
    streampos startPos, endPos;
    bool print_parents = true;
  public:
    /**
     * @brief Create magazine object by parsing from XML
     * @param XML node to import
     */
    TMagazine(ifstream&, streampos);
    ~TMagazine();
    void load(ifstream&);
    void print();
    friend ostream& operator<<(ostream&, TMagazine&);
};

#endif
