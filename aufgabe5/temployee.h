/**
 * Class TEmployee
 *
 * An employee works for a library,
 * is itself a person (base class TPerson),
 * but can also loan mediums and
 * is therefore also a customer (base class TCustomer).
 */

#ifndef TEMPLOYEE_H
#define TEMPLOYEE_H

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

#include "xml.h"
#include "taddress.h"
#include "tdate.h"
#include "tperson.h"
#include "tcustomer.h"

class TEmployee: public TCustomer, virtual public TPerson
{
    protected:
        string EmployeeNr;
        
    public:
        TEmployee(string, TAddress*, TDate*, string);

        /**
         * @brief Create TEmployee by importing from XML node
         * @param XML node to import
         */
        TEmployee(ifstream&);
        void load(ifstream&);
        ~TEmployee();
        void print();

        // getter and setter
        string getEmployeeNr();
        void setEmployeeNr(string);
};

#endif