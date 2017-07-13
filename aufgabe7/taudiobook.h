
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
        bool print_parents = true;

    public:
        /**
         * @brief Create audiobook object by parsing from XML
         * @param XML node to import
         */
        TAudioBook(ifstream&, streampos);
        void load(ifstream&);
        ~TAudioBook();

        friend ostream& operator<<(ostream&, TAudioBook&);
        virtual void print(ostream&);
};

#endif
