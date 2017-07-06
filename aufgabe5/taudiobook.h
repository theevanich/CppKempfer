
#ifndef TAUDIOBOOK_H
#define TAUDIOBOOK_H

#include <string>
#include <vector>
#include "xml.h"

#include "tbook.h"
#include "tcd.h"


class TAudioBook: public TBook, public TCD
{
    protected:
        int countCDs;

    private:
        streampos startPos, endPos;

    public:
        /**
         * @brief Create audiobook object by parsing from XML
         * @param XML node to import
         */
        TAudioBook(ifstream&, streampos);
        void load(ifstream&);
        ~TAudioBook();

        void print();
};

#endif
