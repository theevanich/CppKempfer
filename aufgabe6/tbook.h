#ifndef TBOOK_H
#define TBOOK_H

#include <string>
#include <vector>
#include "xml.h"

#include "tprintedmedium.h"


class TBook: virtual public TPrintedMedium
{
  private:
    string Author;
    streampos startPos, endPos;

  public:
    /**
     * @brief Create book object by parsing from XML
     * @param XML node to import
     */
    TBook(ifstream&, streampos);
    void load(ifstream&);
    ~TBook();

    /**
     * @brief Grant output stream operator access to private class members
     */
    friend ostream& operator<<(ostream&, TBook&);
    void print();
    bool print_parents = true;
};

#endif
