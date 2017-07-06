#ifndef TDVD_H
#define TDVD_H

#include <string>
#include <vector>
#include "xml.h"

#include "ttime.h"
#include "tmedium.h"


class TDVD: public TMedium
{
  private:
    string Actors;
    TTime  *PlayingTime;
    streampos startPos, endPos;

  public:
    /**
     * @brief Create DVD object by parsing from XML
     * @param XML node to import
     */
    TDVD(ifstream&, streampos);
    void load(ifstream&);
    ~TDVD();
    void print();
};

#endif
